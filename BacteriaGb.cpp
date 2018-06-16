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
BacteriaGb::BacteriaGb(float proba_mute) : Bacteria(){
  genotype_ = 'b';
  PROBA_MUTE_ = proba_mute;
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

  // update C 
  phenotype_[1] = (phenotype_[0]*Rbc)*dt + phenotype_[1] ;
  
  //update medium
  *b = (-(*b)*(Rbb))*dt + *b  ;
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
	*b = *b +  phenotype_[0];
	*c = *c +  phenotype_[1];
	delete this;
}


Bacteria* BacteriaGb::divide(){

	double rand_mute;
	rand_mute = ((double) rand() / (RAND_MAX)); 
	Bacteria* daugther;
	if (this->get_fitness() >0){
		if (rand_mute< this->PROBA_MUTE_)
		{
	 		daugther =new BacteriaGb(this->PROBA_MUTE_);
		}
		else 	
		{
			daugther =new BacteriaGa(this->PROBA_MUTE_);
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
