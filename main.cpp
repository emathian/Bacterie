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
//                             "using" statements
// ===========================================================================<
using namespace std;

// ===========================================================================
//                                    MAIN
// ===========================================================================
int main(int argc, char* argv[]) {
  srand(std::time(nullptr));
  // Time step 
  std::vector<int> t;
  for (int i=0; i<=1500 ; i=i+100){
    t.push_back(i);
  }
  // Diffusion step 
  std::vector<float> d;
  for (float k=0; k<=0.1 ; k=k+0.01){
    d.push_back(k);
  }

  // Initialization of parameters
  int a ;
  int a_init = 0;
  int a_end = 50;
  int i;
  int state; // Global state at the end
  float pB; // Proportion of B
  float pA ;// Proportion of A
  int trenew ; // Update a concentration
  float diff; // Coefficient of diffusion

  // Save file 
  
  string nomcsv;
  cout << "Nom du fichier csv:";
  cin >> nomcsv;
  
  std::ofstream outfile (nomcsv,ios::out);
  
  // Main loop
  
  for (a = a_init ; a <= a_end ; a++){
    for (int i= 0 ; i< t.size(); ++i){
      //for (int j=0 ; j<d.size(); ++j){
        trenew = t[i];
        World myworld(32,32,a,trenew,0.1,0.001);
        myworld.update(5000);
        tuple<int,int> liste = myworld.count();
        if (get<1>(liste)+get<0>(liste) !=0 ){
          pB =float(get<1>(liste))/(get<1>(liste)+get<0>(liste));
          pA = float(get<0>(liste))/(get<1>(liste)+get<0>(liste));
        }
        else{
          pB = 0;
          pA = 0;
         }
        outfile << pB << ";" << pA << ";" <<trenew << ";" << a <<";"<< diff<< endl;
      }
    }
  
  return EXIT_SUCCESS;
}


