// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
#include <ctime>
#include <fstream>

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
  
  std::cout <<"At begining :" <<std::endl;
  myworld.display(4);
  myworld.display(5);
 
  std::cout<< "After run  :"<<std::endl;
  myworld.update(5);

  std::cout <<"Modif display :" <<std::endl;
  //std::cout << (int) rand() << std::endl;
  
  tuple<int,int> liste = myworld.count();
  std::cout << "The contents of liste are:";
  std::cout << ' ' << get<0>(liste)<<' '<<get<1>(liste);
  std::cout << '\n';
  
  return EXIT_SUCCESS;
}


// ===========================================================================
//                            Function definitions
// ===========================================================================
