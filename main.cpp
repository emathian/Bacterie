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

  std::vector<int> t;
  for (int i=0; i<=1500 ; i=i+50){
    t.push_back(i);
  }
 
 
 std::vector<float> d;
  for (float k=0; k<=0.1 ; k=k+0.01){
    d.push_back(k);
  }
  
 


  int a;
  int a_init = 34;
  int a_end = 51;
  int i;
  int state;
  float pB;
  float pA ;
  int trenew;
  float diff;
  string nomcsv;
  cout << "Nom du fichier csv:";

  cin >> nomcsv;
  
  std::ofstream outfile (nomcsv,ios::out);
  


  for (a = a_init ; a <= a_end ; a++){
    for (int i= 0 ; i< t.size(); ++i){
      for (int j=0 ; j<d.size(); ++j){
      trenew = t[i];
      diff = d[j];
      World myworld(32,32,a,trenew,diff,0);
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
}
/*
  outfile.close();
  
  std::ofstream outfile ("pm0.001_a017",ios::out);
   for (a = a_init ; a < a_end ; a++){
    for (int i= 0 ; i< t.size(); ++i){
      trenew = t[i];
      World myworld(32,32,a,trenew,0.1,0.001);
      myworld.update(5000);
      tuple<int,int> liste = myworld.count();
      
      pB =float(get<1>(liste))/(get<1>(liste)+get<0>(liste));
     
      outfile << pB << ";" << trenew << ";" << a << endl;
  }
}
 outfile.close();

  std::ofstream outfile ("diff_a017",ios::out);
   for (a = a_init ; a < a_end ; a++){
    for (int i= 0 ; i< t.size(); ++i){
      for (int j= 0 ; j< d.size(); ++j){
      trenew = t[i];
      diff = d[i];
      World myworld(32,32,a,trenew,diff,0);
      myworld.update(5000);
      tuple<int,int> liste = myworld.count();
      
      pB =float(get<1>(liste))/(get<1>(liste)+get<0>(liste));
     
      outfile << pB << ";" << trenew << ";" << a << ";"<< diff<< endl;
  }
 }
}
 outfile.close();
 */
  return EXIT_SUCCESS;
}


// ===========================================================================
//                            Function definitions
// ===========================================================================
