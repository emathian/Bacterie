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

   // Bacteria B;
   // cout << B.PROBA_DEATH() <<endl;
     

    //Bacteria B;

    BacteriaGa myGa;
    BacteriaGb myGb;

    // Test of getters  
    cout <<"Default proba of death  " <<myGa.PROBA_DEATH()<<endl;
    cout <<"Default proba  "<< myGa.PROBA_MUTE()<<endl;
    cout <<"Default  FITNESS_MIN "<< myGa.FITNESS_MIN()<<endl;
    cout <<"Phenotype "<< myGa.phenotype()[1]<< , <<myGa.phenotype()[2]<<endl;
    // Test of settter :



    
    myGa.toString();
    myGb.toString();
    
    cout << myGa.get_fitness() << endl;
    cout << myGb.get_fitness() << endl;


    return EXIT_SUCCESS;
}


// ===========================================================================
//                            Function definitions
// ===========================================================================

