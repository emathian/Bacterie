// ===========================================================================
//                                  Includes
// ===========================================================================
#include "BacteriaGa.h"
// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
static float Raa = 0.1;
static float Rab = 0.1;

// ===========================================================================
//                                Constructors
// ===========================================================================
BacteriaGa::BacteriaGa(){
  genotype_ = 'a';
}

BacteriaGa::BacteriaGa(const BacteriaGa& bactGa){
	genotype_ = bactGa.genotype_;
};


// ===========================================================================
//                                 Destructor
// ===========================================================================


// ===========================================================================
//                         Protected Function members
// ===========================================================================

void BacteriaGa::metabolize(float a){
  // update A  
  phenotype_[0] = a*Raa - phenotype_[0]*Rab;

  // update B 
  phenotype_[1] = phenotype_[1]*Rab;
}

float BacteriaGa::get_fitness(){
  return phenotype_[1]; 
}


void BacteriaGa::kill_bacteria(float *a, float *b, float *c){
	*a = *a +  phenotype_[0];
	*b = *b +  phenotype_[1];
	*c = *c; 
	phenotype_ = {0,0};
}

BacteriaGa BacteriaGa::divide(){
	BacteriaGa 	daugtherGa; 
	 this -> phenotype_[0] = this-> phenotype_[0]/2;
	 this -> phenotype_[1] = this-> phenotype_[1]/2;
	 daugtherGa.phenotype_[0] = this-> phenotype_[0];
	 daugtherGa.phenotype_[1] = this -> phenotype_[1];
	 return daugtherGa;

}

// ===========================================================================
//                           Public Function members
// ===========================================================================

