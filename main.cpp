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
  int t[] = {5,50,500,1000,1500};
  int trenew=t[4];
  World myworld(32,32,1,trenew,0.1);
  myworld.update(5000);
  //myworld.display(4);
  //Parameters
  /*
  int t[] = {5,50,500,1000,1500};
  int a;
  int a_init = 0;
  int a_end = 17;
  int i;
  int state;
  
  int trenew=t[4];

  string nomcsv;

  cout << "Nom du fichier csv:";

  cin >> nomcsv;
  World myworld(32,32,1,trenew,0.1);
  myworld.update(5000);
  std::ofstream outfile (nomcsv,ios::out);
  tuple<int,int> liste = myworld.count();
  cout << get<0>(liste);
  */

 
  

  return EXIT_SUCCESS;
}


// ===========================================================================
//                            Function definitions
// ===========================================================================
