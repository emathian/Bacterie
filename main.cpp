// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>

#include "Bacteria.h"
#include "BacteriaGa.h"
#include "BacteriaGb.h"
#include "World.h"


// ===========================================================================
//                            Function declarations
// ===========================================================================

// ===========================================================================
//                             "using" statements
// ===========================================================================<
using namespace std;

// ===========================================================================
//                                    MAIN
// ===========================================================================
int main(int argc, char* argv[]) {
  srand(time(NULL));
  /*
  //----------------------
  //Testeurs de Bacteria
  //----------------------
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

  //----------------------
  //Testeurs de World
  //----------------------

  //test constructeur
  World myworld(4,3,0.1);
  
  cout<< "Pop : " << endl;
  myworld.display(4);
  //myworld.pop();  
  cout<< "a : " << endl;
  myworld.display(1);
  cout<< "b : " << endl;
  myworld.display(2);
  cout<< "c : " << endl;
  myworld.display(3);
  
  // Tests de la méthode diffuse
  /* Tests réalisés en modifiant le constructeur pour avoir une seule case remplie en a_ 
  Bord g/d : done
  Bord h/b : done
  coin hg : done
  coin hd : done
  coin bg : done
  coin bd : done
  */
  
  /*
  myworld.diffuse_concentration();
  cout<< endl;

  cout<< "Après diffusion : " << endl; 
  
  cout<< "Pop : " << endl;
  myworld.display(4);
  //myworld.pop();  
  */
  

  myworld.display(1);
  myworld.display(2);
  myworld.display(3);
  
  /*
  cout<<""<<endl;
  myworld.display(4);
  

  
  myworld.renew(30);
  myworld.display(1);
  myworld.display(2);

  cout<<"genotype "<<endl;
  myworld.display(4);
    
  myworld.display(6);   
  //myworld.competition();

  int s = 15/4;
  cout<<s<<endl;
  
  
  myworld.renew(30);
  myworld.display(1);
  myworld.display(2);
  vect<tuple<int,int>> coord = myworld.find_empty();
  
  myworld.find_neighborhood(1,1);
  myworld.competition();

    
  //myworld.display(4);
  
  
  //test empty
  vector<tuple<int,int>> liste = myworld.get_empty();
  std::cout << "The contents of liste are:";
  for (vector<tuple<int,int>>::iterator it = liste.begin(); it != liste.end(); ++it)
    std::cout << ' ' << get<0>(*it);
  std::cout << '\n';
  */


  return EXIT_SUCCESS;
}


// ===========================================================================
//                            Function definitions
// ===========================================================================
