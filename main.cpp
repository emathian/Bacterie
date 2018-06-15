// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
#include <ctime>
#include <fstream>
#include <string>

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
  srand(std::time(nullptr));
  //Parameters
  int t[] = {5,50,500,1000,1500};
  int a;
  int a_init = 0;
  int a_end = 50;
  int i;
  int state;
  
  int trenew=t[4];
  
  string nomcsv;

  cout << "Nom du fichier csv:";

  cin >> nomcsv;

  std::ofstream outfile (nomcsv,ios::out);
  
  for (a = a_init ; a < a_end ; a++){
      World myworld(32,32,0 , 1500,0.1); // trenew = trenew
      myworld.update(5000);
      tuple<int,int> liste = myworld.count();
      // write to outfile
      if (get<0>(liste)==0 && get<1>(liste)==0){        
        state =0; // extinction
      }
      else if (get<0>(liste)==0 || get<1>(liste)==0){ 
        state =1; // exclusion
      }
      else{
        state=2; // cohabitation
      }
      outfile << state << ";" << i << ";" << a << endl;
  }
  
  return EXIT_SUCCESS;
}


// ===========================================================================
//                            Function definitions
// ===========================================================================
