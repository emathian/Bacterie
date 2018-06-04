// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
#include <iostream>
#include <stdlib.h> 
// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
float Bacteria::FITNESS_MIN_ =0.001;

// ===========================================================================
//                                Constructors
// ===========================================================================
Bacteria::Bacteria(): PROBA_DEATH_(0.2), PROBA_MUTE_(0.0){ // PROBA_DEATH= 0.02 !!!!!!!!!!!!
	phenotype_ = {0., 0.};
	

}

Bacteria::Bacteria(const Bacteria& bact) 
{
	this->PROBA_DEATH_ = bact.PROBA_DEATH_; 
	this->phenotype_ = bact.phenotype_; 
	this-> PROBA_MUTE_ = bact.PROBA_MUTE_;	

}
// ===========================================================================
//                                Getter
// ===========================================================================
float Bacteria::PROBA_MUTE() const{
	return PROBA_MUTE_;
}	
float Bacteria::PROBA_DEATH() const{
	return PROBA_DEATH_;
};

float Bacteria::FITNESS_MIN() const{
	return FITNESS_MIN_;
}

std::vector<float> Bacteria::phenotype() {

	return phenotype_;
}



char Bacteria::genotype() const{
 	return genotype_;
 }

// ===========================================================================
//                               Setter
// ===========================================================================
  void Bacteria::set_phenotype(std::vector<float> new_phenotype){
  	phenotype_ = new_phenotype;
  }

// ===========================================================================
//                         Protected Function members
// ===========================================================================

void Bacteria::toString(){
  std::cout << "Je suis une bactérie de p_death " << PROBA_DEATH_ << " et de p_mut " << PROBA_MUTE_ << std::endl;
}
