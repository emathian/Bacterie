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

void BacteriaGa::metabolize(float * a, float * b){
  float dt=0.1; // pas de temps  
  // update A  
  phenotype_[0] = (*a*Raa - phenotype_[0]*Rab)*dt + phenotype_[0];
  *a = -((*a)*(Raa))*dt + *a; // update medium
  // update B 
  phenotype_[1] = (phenotype_[1]*Rab)*dt + phenotype_[1] ;
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

Bacteria* BacteriaGa::divide(){
	srand(time(NULL));
	double rand_mute;
	rand_mute = ((double) rand() / (RAND_MAX)); 
	std::cout << rand_mute <<std::endl; 
	Bacteria* daugther;
	if (rand_mute< this->PROBA_MUTE_)
	{
	 	daugther =new BacteriaGb();
	}
	else 	
	{
		daugther =new BacteriaGa();
	}
	 
	this -> phenotype_[0] = this-> phenotype_[0]/2;
	this -> phenotype_[1] = this-> phenotype_[1]/2;
	std::vector<float> new_phenotype = {this-> phenotype_[0] , this->phenotype_[1] };
	daugther->set_phenotype(new_phenotype);
	return daugther;

}

// ===========================================================================
//                           Public Function members
// ===========================================================================
