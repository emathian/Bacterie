// ===========================================================================
//                                  Includes
// ===========================================================================
#include "BacteriaGb.h"
// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
static float Rbb = 0.1;
static float Rbc = 0.1;

// ===========================================================================
//                                Constructors
// ===========================================================================
BacteriaGb::BacteriaGb(){
  genotype_ = 'b';
}

// ===========================================================================
//                                 Destructor
// ===========================================================================

// ===========================================================================
//                           Public Function members
// ===========================================================================
void BacteriaGb::metabolize(float b){
  // update B
  phenotype_[0] = b*Rbb - phenotype_[0]*Rbc;

  // update C 
  phenotype_[1] = b*phenotype_[1];
}

float BacteriaGb::get_fitness(){
  return phenotype_[1]; // corresponds to C rate
}

void BacteriaGb::kill_bacteria(float *a, float *b, float *c){
	*a = *a;
	*b = *b +  phenotype_[1];
	*c = *c +  phenotype_[2];
	phenotype_ = {0,0};
}

BacteriaGb BacteriaGb::divide(){
	BacteriaGb	daugtherGb; 
	 this -> phenotype_[0] = this-> phenotype_[0]/2;
	 this -> phenotype_[1] = this-> phenotype_[1]/2;
	 daugtherGb.phenotype_[0] = this-> phenotype_[0];
	 daugtherGb.phenotype_[1] = this -> phenotype_[1];
	 return daugtherGb;

}

// ===========================================================================
//                         Protected Function members
// ===========================================================================

