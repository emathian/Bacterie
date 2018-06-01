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
BacteriaGb::BacteriaGb() : Bacteria(){
  genotype_ = 'b';
}

BacteriaGb::BacteriaGb(const BacteriaGb& bactGb) : Bacteria(bactGb){
	genotype_ = bactGb.genotype_;
};
// ===========================================================================
//                                 Destructor
// ===========================================================================

// ===========================================================================
//                           Public Function members
// ===========================================================================
void BacteriaGb::metabolize(float *a,float *b){
  float dt=0.1; // pas de temps  
  // update B
  phenotype_[0] = (*b*Rbb - phenotype_[0]*Rbc)*dt + phenotype_[0] ;
  *b = ((*b)*(Rbb))*dt + phenotype_[0]  ;

  // update C 
  phenotype_[1] = (*b*phenotype_[1])*dt + phenotype_[1] ;
}

float BacteriaGb::get_fitness(){
  	if (phenotype_[1]<this->FITNESS_MIN_){
		return 0;
	}
	else{
  		return phenotype_[1]; // corresponds to C rate
	}
}

void BacteriaGb::kill_bacteria(float *a, float *b, float *c){
	*a = *a;
	*b = *b +  phenotype_[1];
	*c = *c +  phenotype_[2];
	delete this;
}


Bacteria* BacteriaGb::divide(){
	srand(time(NULL));
	double rand_mute;
	rand_mute = ((double) rand() / (RAND_MAX)); 
	std::cout << rand_mute <<std::endl; 
	Bacteria* daugther;
	if (this->get_fitness() >0){
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
	
	 }else{
	 	daugther=NULL;
	 }

	 return daugther;	


}


// ===========================================================================
//                         Protected Function members
// ===========================================================================
