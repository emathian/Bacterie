// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacteriaGa.h"
#include "World.h"
#include <map>

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
    Bacteria* tab[width][height];
    pop_ = tab;

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
    for(x = 0; x<W_; x++){ //differents cas pour la forme toroïdale
      for(y = 0; y<H_; y++){
        if(x = 0){
          xg = W_ - 1;
          xd = x + 1;
        }else{
          if(x = W_-1){
            xg = x - 1;
            xd = 0;
          }else{
            xg = x - 1;
            xd = x + 1;
          }
        }
        if(y = 0){
          yh = H_ - 1;
          yb = y + 1;        
        }else{
          if(y = H_-1){
            yh = y - 1;
            yb = 0; 
          }else{
            yh = y - 1;
            yb = y + 1;          
          }
        }
        stockA[x][y] = stockA[x][y] + D_*(a_[xg][yh] + a_[x][yh] + a_[xd][yh]
                                        + a_[xg][y] + a_[x][y] + a_[xd][y]
                                        + a_[xg][yb] + a_[x][yb] + a_[xd][yb]);
        stockA[x][y] = stockA[x][y] + D_*(b_[xg][yh] + b_[x][yh] + b_[xd][yh]
                                        + b_[xg][yb] + b_[x][yb] + b_[xd][y]
                                        + b_[xg][yb] + b_[x][yb] + b_[xd][yb]);
        stockA[x][y] = stockA[x][y] + D_*(c_[xg][yh] + c_[x][yh] + c_[xd][yh]
                                        + c_[xg][y] + c_[x][y] + c_[xd][y]
                                        + c_[xg][yb] + c_[x][yb] + c_[xd][yb]);
        
        stockA[x][y] = stockA[x][y] - 9*D_*a_[x][y];
        stockB[x][y] = stockA[x][y] - 9*D_*b_[x][y];
        stockC[x][y] = stockA[x][y] - 9*D_*c_[x][y]; 
      }
    }
  }


  void competition(){
    map<Bacteria *,float> neighborhood;
    int x;
    int y;
    for(x = 0; x< W_; x++){
      for(y = 0; y< H_; y++){
        if(pop_[x][y] = NULL){
          if(x = 0){
            xg = W_ - 1;
            xd = x + 1;
          }else{
            if(x = W_-1){
              xg = x - 1;
              xd = 0;
            }else{
              xg = x - 1;
              xd = x + 1;
            }
         }
          if(y = 0){
            yh = H_ - 1;
           yb = y + 1;        
          }else{
            if(y = H_-1){
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
  
  void update(){
  
  }
  
void renew(int a_init){
 
}
  **/


 
  
  

// ===========================================================================
//                         Protected Function members
// ===========================================================================
