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
BacteriaGa::BacteriaGa(float proba_mute) : Bacteria(){
  genotype_ = 'a';
  PROBA_MUTE_ = proba_mute;
  
}

BacteriaGa::BacteriaGa(const BacteriaGa& bactGa) : Bacteria(bactGa){
	genotype_ = bactGa.genotype_;
};


// ===========================================================================
//                                 Destructor
// ===========================================================================


// ===========================================================================
//                         Protected Function members
// ===========================================================================

void BacteriaGa::metabolize(float * a, float * b){
  float dt=0.1; // pas de temps  
  // update A  
  phenotype_[0] = ((*a)*Raa - phenotype_[0]*Rab)*dt + phenotype_[0];
  
  // update B 
  phenotype_[1] = (phenotype_[0]*Rab)*dt + phenotype_[1] ;
  
  // update medium
  *a = -((*a)*(Raa))*dt + *a; 
}

float BacteriaGa::get_fitness(){
	if (phenotype_[1]<this->FITNESS_MIN_){
		return 0;
	}
	else{
    return phenotype_[1]; 
	}	
}


void BacteriaGa::kill_bacteria(float *a, float *b, float *c){
	*a = *a +  phenotype_[0];
	*b = *b +  phenotype_[1];
	*c = *c; 
	delete this; // VOIR POUR CHANGER
}

Bacteria* BacteriaGa::divide(){
	float rand_mute;
	rand_mute = (float) rand()/(float)RAND_MAX ; // Null 
	Bacteria* daugther;
	if (this->get_fitness() >0){
		if (rand_mute< this->PROBA_MUTE_)
		{
	 		daugther =new BacteriaGb( this->PROBA_MUTE_);
	 		this -> phenotype_[0] = this-> phenotype_[1]/2;
	    this -> phenotype_[1] = 0;
		}
		else 	
		{
			daugther =new BacteriaGa( this->PROBA_MUTE_);
			this -> phenotype_[0] = this-> phenotype_[0]/2;
	    this -> phenotype_[1] = this-> phenotype_[1]/2;
		}


	std::vector<float> new_phenotype = {this-> phenotype_[0] , this->phenotype_[1] };
	daugther->set_phenotype(new_phenotype);
	
	 } else{
	 	daugther=nullptr;
	 }
		
	 return daugther;	

}


