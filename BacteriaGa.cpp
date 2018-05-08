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
  return phenotype_[1]; // corresponds to B rate
}


void BacteriaGa::kill_bacteria(float *a, float *b, float *c){
	*a = *a +  phenotype_[0];
	*b = *b +  phenotype_[1];
	*c = *c; 
	phenotype_ = {0,0};
}

// ===========================================================================
//                           Public Function members
// ===========================================================================

