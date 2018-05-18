// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacteriaGa.h"
#include "World.h"

#include <iostream>

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                Constructors
// ===========================================================================


  World::World(int width, int height, float diffusion){
    
    W_ = width;
    H_ = height;
    D_ = diffusion;
    pop_ = new Bacteria* *[W_];
    a_ = new float *[W_];
    b_ = new float *[W_];
    c_ = new float *[W_];

    int i;
    for(int i = 0; i<W_; i++){
      pop_[i] = new Bacteria* [H_];
      a_[i] = new float [H_];
      b_[i] = new float [H_];
      c_[i] = new float [H_];
     }
    int j;
    for(i = 0; i<width; i++){
      for(j = 0; j<height; j++){
        BacteriaGa a;
        pop_[i][j] = &a;
        a_[i][j] = 50.0;
        b_[i][j] = 0.0;
        c_[i][j] = 0.0;
      }
    }

  }




  
  
// ===========================================================================
//                                 Destructor
// ===========================================================================
  /*
  World::~World(){
    int i;
    for(i=0; i<W_; i++){
      delete[] pop_[i];
      delete[] a_[i];
      delete[] b_[i];
      delete[] c_[i];
    }
    delete pop_[];
    delete[] a_;
    delete[] b_;
    delete[] c_;
    delete D_ ;
    delete W_ ; 
    delete H_ ;
  }

// ===========================================================================
//                           Public Function members
// ===========================================================================
 
 
void diffuse_concentration(){
  int stockA = a_;
  int stockB = b_;
  int stockC = c_;
  int x;
  int y;
  int i;
  int j;
  for(x = 0; i<W_; i++){
    for(y = 0; j<H_; j++){
      for(i = -1; i<=1; i++){
        for(j = -1; j<=1; j++){
          stockA[x][y] = stockA[x][y] + D_*a_[x+i][y+j];
          stockB[x][y] = stockA[x][y] + D_*b_[x+i][y+j];
          stockC[x][y] = stockA[x][y] + D_*c_[x+i][y+j];
        }
        stockA[x][y] = stockA[x][y] - 9*D_*a_[x][y];
        stockB[x][y] = stockA[x][y] - 9*D_*b_[x][y];
        stockC[x][y] = stockA[x][y] - 9*D_*c_[x][y]; 
      }
    }
    a_ = stockA;
    b_ = stockB;
    c_ = stockC;
  }


  void competition(){
    
    int x;
    int y;
    int i;
    int j;
    for(x = 0; i<W_; i++){
      for(y = 0; j<H_; j++){
        for(i = -1; i<1; i++){
          for(j = -1; j<1; j++){
            stockA[x][y] = stockA[x][y] + D_*a_[x+i][y+j];
            stockB[x][y] = stockA[x][y] + D_*b_[x+i][y+j];
            stockC[x][y] = stockA[x][y] + D_*c_[x+i][y+j];
          }
        }
        stockA[x][y] = stockA[x][y] - 9*D_*a_[x][y];
        stockB[x][y] = stockA[x][y] - 9*D_*b_[x][y];
        stockC[x][y] = stockA[x][y] - 9*D_*c_[x][y]; 
      }
    }
  }
    
}
  
  void update(){
  
  }
  
void renew(int a_init){
 
}
  **/

// ===========================================================================
//                                 Getters
// ===========================================================================

void World::pop(){
  for(int i = 0; i<W_; i++){
      for(int j = 0; j<H_; j++){
        std::cout << "Adresse : " << pop_[i][j] << "///";
        pop_[i][j]->toString();
      }
  }
}
  
  

// ===========================================================================
//                         Protected Function members
// ===========================================================================
