// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <iostream>
#include <vector>

#include "Bacteria.h"
#include "BacteriaGa.h"
#include "BacteriaGb.h"
#include "World.h"


// ===========================================================================
//                            Function declarations
// ===========================================================================

// ===========================================================================
//                             "using" statements
// ===========================================================================
using std::cout;
using std::endl;


// ===========================================================================
//                                    MAIN
// ===========================================================================
int main(int argc, char* argv[]) {
  /*
  // Bacteria B;
  // cout << B.PROBA_DEATH() <<endl;
    

   //Bacteria B;
  BacteriaGa myGa;
  BacteriaGb myGb;

  // Test of constructor copy
  BacteriaGa myGa_copy(myGa);
  BacteriaGb myGb_copy(myGb);

  // Test of getters  
  cout <<"Default proba of death  " <<myGa.PROBA_DEATH()<<endl;
  cout <<"Default proba  "<< myGa.PROBA_MUTE()<<endl;
  cout <<"Default  FITNESS_MIN "<< myGa.FITNESS_MIN()<<endl;
  cout <<"Phenotype "<< myGa.phenotype()[0]<< "," <<myGa.phenotype()[1]<<endl;
  cout <<"Genotype "<< myGa.genotype()<<endl;
  // Test of settter :
  std::vector<float> update_phenotype = {0,1};
  myGa.set_phenotype(update_phenotype);
  cout <<"Phenotype "<< myGa.phenotype()[1]<< "," <<myGa.phenotype()[2]<<endl;


    
  myGa.toString();
  myGb.toString();
    
  cout << myGa.get_fitness() << endl;
  cout << myGb.get_fitness() << endl;
  */
  
  // Test of KIll
  // Sorry myGa 
  /* THIS TEST CANNOT BE EXUCETED ANY MORE BECAUSE kill_bacteria as been protected
  float cA =0.8 ; float cB = 0.9 ; float cC = 0;
  myGa.kill_bacteria(&cA , &cB , &cC);
  cout <<"Phenotype "<< myGa.phenotype()[1]<< "," <<myGa.phenotype()[2]<<endl;
  */

  //TEst of divide
  /* THIS TEST CANNOT BE EXUCETED ANY MORE BECAUSE kill_bacteria as been protected					
  BacteriaGa daughtermyGA = myGa.divide();// Wellcome !
  cout <<"Phenotype "<< daughtermyGA.phenotype()[0]<< "," <<daughtermyGA.phenotype()[1]<<endl;
	*/
	
	//Testeurs de world
	  
	//test constructeur
	
	// Bacteria** tableau[2][2];
	
	


	World myworld(2, 2, 0.1);
  //cout<<""<<endl;
  //myworld.display(3);

  //myworld.diffuse_concentration();
	
	
  return EXIT_SUCCESS;
}


// ===========================================================================
//                            Function definitions
// ===========================================================================

