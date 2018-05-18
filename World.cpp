// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacteriaGa.h"
#include "BacteriaGb.h"
#include "World.h"


#include <map>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <stdio.h>

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


  pop_ = new Bacteria** [H_];
  a_ = new float *[H_];
  b_ = new float *[H_];
  c_ = new float *[H_];

  std::vector<int> rand_v;
  for (int i = 0; i<W_*H_; i++){
    int rand_type = rand()%2 ;
    rand_v.push_back(rand_type);
   } 


  int i;
  for(int i = 0; i<H_; i++){
    pop_[i] = new Bacteria* [W_];
    a_[i] = new float [W_];
    b_[i] = new float [W_];
    c_[i] = new float [W_];
   }
  int k=0;
  int j;
  for(i = 0; i< H_ ; i++){
    for(j = 0; j< W_ ; j++){
      if (rand_v[k]==0){
        BacteriaGa add_a;
        pop_[i][j] = &add_a;
      }
      else{
        BacteriaGb add_b;
        pop_[i][j] = &add_b;
      }
      // Tests for diffuse
      a_[i][j] = 0.0; // to suppress
      //a_[i][j] = 50.0; // to uncomment

      b_[i][j] = 0.0;
      c_[i][j] = 0.0;
      ++k;
    }
    // Tests for diffuse
    a_[1][1]=50.0; // to suppress
  }
}




  
  
// ===========================================================================
//                                 Destructor
// ===========================================================================

World::~World(){
  int i;
  for(i=0; i<H_; i++){
    delete[] a_[i];
    delete[] b_[i];
    delete[] c_[i];
    delete[] pop_[i];
  }  
  delete[] a_;
  delete[] b_;
  delete[] c_;
  delete[] pop_;
}


// ===========================================================================
//                           Public Function members
// ===========================================================================
 
void World::diffuse_concentration(){
  
  float** stockA = new float *[H_];
  for(int i = 0; i<W_; i++){ //differents cas pour la forme toroïdale
    stockA[i] = new float [W_];
    for(int j = 0; j<H_; j++){
      stockA[i][j] = a_[i][j];
    }
  }
  
  // A modifier de la même façon (pas de copie globale)
  float** stockB = b_;
  float** stockC = c_;

  int x;
  int y;
  int xg;
  int xd;
  int yh;
  int yb;
  for(x = 0; x<W_; x++){ //differents cas pour la forme toroïdale
    for(y = 0; y<H_; y++){
      if(x == 0){ // cas cellule sur bord gauche
        xg = W_ - 1;
        xd = x + 1;
      }else{
        if(x == W_-1){ // cas cellule sur bord droit
          xg = x - 1;
          xd = 0;
        }else{ // cas cellule pas sur les bords G/D
          xg = x - 1;
          xd = x + 1;
        }
      }
      if(y == 0){ // cas cellule sur bord haut
        yh = H_ - 1;
        yb = y + 1;
      }else{
        if(y == H_-1){ // cas cellule sur bord bas
          yh = y - 1;
          yb = 0; 
        }else{ // cas cellule pas sur bords H/B
          yh = y - 1;
          yb = y + 1;          
        }
      }
      stockA[x][y] = stockA[x][y] + D_*(a_[xg][yh] + a_[x][yh] + a_[xd][yh]
                                      + a_[xg][y] + a_[x][y] + a_[xd][y]
                                      + a_[xg][yb] + a_[x][yb] + a_[xd][yb]);
      stockB[x][y] = stockB[x][y] + D_*(b_[xg][yh] + b_[x][yh] + b_[xd][yh]
                                      + b_[xg][yb] + b_[x][yb] + b_[xd][y]
                                      + b_[xg][yb] + b_[x][yb] + b_[xd][yb]);
      stockC[x][y] = stockC[x][y] + D_*(c_[xg][yh] + c_[x][yh] + c_[xd][yh]
                                      + c_[xg][y] + c_[x][y] + c_[xd][y]
                                      + c_[xg][yb] + c_[x][yb] + c_[xd][yb]);
        
      stockA[x][y] = stockA[x][y] - 9*D_*a_[x][y];
      stockB[x][y] = stockB[x][y] - 9*D_*b_[x][y];
      stockC[x][y] = stockC[x][y] - 9*D_*c_[x][y]; 
    }
  }
  //a_ = stockA;

  int i;
  int j;
  for(i = 0; i<H_; i++){ //differents cas pour la forme toroïdale
    for(j = 0; j<W_; j++){
      a_[i][j] = stockA[i][j];   
    }
    delete[] stockA[i];
  }
  delete[] stockA;

  // A recopier de la même façon que a_
  b_ = stockB;
  c_ = stockC;
}

  /*
  // ATTENTION W ET H A INVERSER ? (j'ai pas checké)
  void World::competition(){
    map<Bacteria *,float> neighborhood;
    int x;
    int y;
    int xg;
    int xd;
    int yh;
    int yb;
    for(x = 0; x< W_; x++){
      for(y = 0; y< H_; y++){
        if(pop_[x][y] == NULL){
          if(x == 0){
            xg = W_ - 1;
            xd = x + 1;
          }else{
            if(x == W_-1){
              xg = x - 1;
              xd = 0;
            }else{
              xg = x - 1;
              xd = x + 1;
            }
         }
          if(y == 0){
            yh = H_ - 1;
           yb = y + 1;        
          }else{
            if(y == H_-1){
              yh = y - 1;
              yb = 0; 
            }else{
             yh = y - 1;
              yb = y + 1;          
            }
          }
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][yh],pop_[xg][yh].get_fitness()) );
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][y],pop_[xg][y].get_fitness()) );
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][yb],pop_[xg][yb].get_fitness()) );
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][yh],pop_[xd][yh].get_fitness()) );
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][y],pop_[xd][y].get_fitness()) );
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][yb],pop_[xd][yb].get_fitness()) );
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[x][yh],pop_[x][yh].get_fitness()) );
        neighborhood.insert ( std::pair<Bacteria *,float>(pop_[x][yb],pop_[x][yb].get_fitness()) );
        std::map<Bacteria *,float>::iterator it = neighborhood.begin();
        // faire divide ici
        }      
      }
    }
}
*/

  /**
  void update(){
  
  }
  
void World::renew(int a_init){
  for (int i=0; i<H_ ; ++i){
    for (int j=0; j<W_ ; ++j){
      b_[i][j]=0;
      c_[i][j]=0;
      a_[i][j]= a_init;
    }
  }
 
}
  **/

void World::display(int choice){ // Just for tests

 
  if (choice == 1){
    for (int i=0; i<H_ ; ++i){
      for (int j=0; j<W_ ; ++j){
      std::cout<< i << j<<'\t'<<a_[i][j] <<std::endl;
      }
    }
  }  
  else if (choice == 2){
    for (int i=0; i<H_ ; ++i){
       for (int j=0; j<W_ ; ++j){
      std::cout<< i <<j <<'\t'<<b_[i][j] <<std::endl;
    }
   } 
  }
  else if (choice == 3){
    for (int i=0; i<H_ ; ++i){
       for (int j=0; j<W_ ; ++j){
      std::cout<< i <<j <<'\t'<<c_[i][j] <<std::endl; 
    }
   } 
  }

  else{
    for (int i=0; i<H_ ; ++i){
      for (int j=0; j<W_ ; ++j){
        std::cout<< i <<j <<'\t'<<pop_[i][j]->genotype() <<std::endl; 
      }
    } 
  }

}  

// ===========================================================================
//                                 Getters
// ===========================================================================

void World::pop(){
  for(int i = 0; i<H_; i++){
      for(int j = 0; j<W_; j++){
        std::cout << "Adresse : " << pop_[i][j] << "///";
        pop_[i][j]->toString();
      }
  }
}
  
  

// ===========================================================================
//                         Protected Function members
// ===========================================================================
