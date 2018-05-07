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
  genotype_ = Bacteria::Genotype::Gb;
}

// ===========================================================================
//                                 Destructor
// ===========================================================================

// ===========================================================================
//                           Public Function members
// ===========================================================================

// ===========================================================================
//                         Protected Function members
// ===========================================================================
void BacteriaGb::metabolize(float b){
  // update B
  phenotype_[0] = b*Rbb - phenotype_[0]*Rbc;

  // update C 
  phenotype_[1] = b*phenotype_[1];
}
