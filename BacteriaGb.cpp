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

BacteriaGb::BacteriaGb(const BacteriaGb& bactGb){
	genotype_ = bactGb.genotype_;
};
// ===========================================================================
//                                 Destructor
// ===========================================================================

// ===========================================================================
//                           Public Function members
// ===========================================================================
void BacteriaGb::metabolize(float *a,float * b){
  float dt=0.1; // pas de temps  
  // update B
  phenotype_[0] = (*b*Rbb - phenotype_[0]*Rbc)*dt + phenotype_[0] ;
  *b = ((*b)*(Rbb))*dt + phenotype_[0]  ;

  // update C 
  phenotype_[1] = (*b*phenotype_[1])*dt + phenotype_[1] ;
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


Bacteria* BacteriaGb::divide(){
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
//                         Protected Function members
// ===========================================================================
