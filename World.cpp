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
#include <algorithm>  /*shufle */
#include <iomanip>     // std::setprecision
#include <iterator>
#include <tuple>

using namespace std;

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
  for (int i = 0; i<W_*H_/2; i++){     
    rand_v.push_back(0);
  } 
  for (int j = W_*H_/2; j<W_*H_; j++){     
    rand_v.push_back(1);
  } 
  std::random_shuffle( rand_v.begin(), rand_v.end() );

  int i;
  for(int i = 0; i<H_; i++){
    pop_[i] = new Bacteria* [W_];
    a_[i] = new float [W_];
    b_[i] = new float [W_];
    c_[i] = new float [W_];
  }
  int k=0;
  int j;
  for(i = 0; i<H_; i++){
    for(j = 0; j<W_; j++){

      if (rand_v[k]==0){
        std::vector<int> current_pos ={i,j};    
        Bacteria* p_add_a = new BacteriaGa();
        pop_[i][j] = p_add_a;
        
        //std::cout<< p_add_a <<std::endl;
        //std::cout<< pop_[i][j]->genotype() <<std::endl;
        //std::cout<< p_add_a->genotype() <<std::endl;
      }
      else{
        Bacteria* p_add_b = new BacteriaGb();
        pop_[i][j] = p_add_b;
      }
        
      a_[i][j] = 50.0;
      b_[i][j] = 0.0;
      c_[i][j] = 0.0;
      ++k;
    }
  }
}


// ===========================================================================
//                                 Destructor
// ===========================================================================
  
World::~World(){ 
  int i;
  int j;
  for(i = 0; i<H_; i++){ // suppress bacterias*
    for(j = 0; j<W_; j++){
      delete pop_[i][j];
    }
  }
  for(i=0; i<H_; i++){ // suppress pointer to float* / batcteria*
    delete[] a_[i];
    delete[] b_[i];
    delete[] c_[i];
    delete[] pop_[i];
  } 
    
  delete[] a_; // suppress 1D table
  delete[] b_;
  delete[] c_;
  delete[] pop_;
}


// ===========================================================================
//                           Public Function members
// ===========================================================================
 
void World::diffuse_concentration(){
  float** stockA = new float *[H_];
  float** stockB = new float *[H_];
  float** stockC = new float *[H_];

  // Copy of medium 
  for(int i = 0; i<H_; i++){ 
     stockA[i] = new float [W_];
     for(int j = 0; j<W_; j++){
       stockA[i][j] = a_[i][j];
     }
   }
   for(int i = 0; i<H_; i++){ 
     stockB[i] = new float [W_];
     for(int j = 0; j<W_; j++){
       stockB[i][j] = b_[i][j];
     }
   }
  for(int i = 0; i<H_; i++){ 
     stockC[i] = new float [W_];
     for(int j = 0; j<W_; j++){
       stockC[i][j] = c_[i][j];
     }
   }

  // Declare position variables
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
      }else{ //endif
        if(x == W_-1){ // cas cellule sur bord droit
          xg = x - 1;
          xd = 0;
        }else{ // cas cellule pas sur les bords G/D
          xg = x - 1;
          xd = x + 1;
        }
      } //endelse
      if(y == 0){ // cas cellule sur bord haut
        yh = H_ - 1;
        yb = y + 1;
      }else{ //endif
        if(y == H_-1){ // cas cellule sur bord bas
          yh = y - 1;
          yb = 0; 
        }else{ // cas cellule pas sur bords H/B
          yh = y - 1;
          yb = y + 1;          
        } 
      } //endelse
      // Attention dans les coordonnees, x et y sont inversés par rapport à l'ordre habituel
      stockA[y][x] = stockA[y][x] + D_*(a_[yh][xg] + a_[yh][x] + a_[yh][xd]
                                      + a_[y][xg] + a_[y][x] + a_[y][xd]
                                      + a_[yb][xg] + a_[yb][x] + a_[yb][xd]);
      stockB[y][x] = stockB[y][x] + D_*(b_[yh][xg] + b_[yh][x] + b_[yh][xd]
                                      + b_[y][xg] + b_[y][x] + b_[y][xd]
                                      + b_[yb][xg] + b_[yb][x] + b_[yb][xd]);
      stockC[y][x] = stockC[y][x] + D_*(c_[yh][xg] + c_[yh][x] + c_[yh][xd]
                                      + c_[y][xg] + c_[y][x] + c_[y][xd]
                                      + c_[yb][xg] + c_[yb][x] + c_[yb][xd]);

      stockA[y][x] = stockA[y][x] - 9*D_*a_[y][x]; 
      stockB[y][x] = stockB[y][x] - 9*D_*b_[y][x];
      stockC[y][x] = stockC[y][x] - 9*D_*c_[y][x];      
    } 
  } //endfor différents cas

  int i;
  int j;
  
  for(i = 0; i<H_; i++){
    for(j = 0; j<W_; j++){
      a_[i][j] = stockA[i][j];   
    }
    delete[] stockA[i];
  }
  delete[] stockA;
  
  for(i = 0; i<H_; i++){
    for(j = 0; j<W_; j++){
      b_[i][j] = stockB[i][j];   
    }
    delete[] stockB[i];
  }
  delete[] stockB;
  
  for(i = 0; i<H_; i++){
    for(j = 0; j<W_; j++){
      c_[i][j] = stockC[i][j];   
    }
    delete[] stockC[i];
  }
  delete[] stockC;
}

std::map<int,float> World::find_neighborhood(int i, int j){ 
    int x = i; // row position
    int y = j; // column position
    int xg;
    int xd;
    int yh;
    int yb;
    std::map<int,float> neighborhood;   // Initialisation of the returned map
    /* Find indexes of cell contained in the Moore Neighborhood according Toroid
    grid's constraints. */ 
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
        // Fill the returned map according filling conditions.
      // ATTENTION XG ET YH... etc A INVERSER (A VERIFIER MAIS JE CROIS)
      // if (pop_[YH][YG] == NULL){
        if (pop_[xg][yh] == NULL){
          neighborhood.insert ( std::pair<int,float>(xg +yh, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(xg+yh,pop_[xg][yh]->get_fitness()) );
        }
        if (pop_[xg][y] == NULL){
          neighborhood.insert ( std::pair<int,float>(xg+y, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(xg+y,pop_[xg][y]->get_fitness()) );
        }     
         if (pop_[xg][yb] == NULL){
          neighborhood.insert ( std::pair<int,float>(xg+yb, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(xg+yb,pop_[xg][yb]->get_fitness()) );
        }     
        if (pop_[xd][yh] == NULL){
          neighborhood.insert ( std::pair<int,float>(xd+yh, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(xd+yh,pop_[xd][yh]->get_fitness()) );
        } 
        if (pop_[xd][y] == NULL){
          neighborhood.insert ( std::pair<int,float>(xd+y, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(xd+y,pop_[xd][y]->get_fitness()) );
        } 
        if (pop_[xd][yb] == NULL){
          neighborhood.insert ( std::pair<int,float>(xd+yb, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(xd+yb,pop_[xd][yb]->get_fitness()) );
        } 
        if (pop_[x][yh] == NULL){
          neighborhood.insert ( std::pair<int,float>(x+yh, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(x+yh,pop_[x][yh]->get_fitness()) );
        } 
       if (pop_[x][yb] == NULL){
          neighborhood.insert ( std::pair<int,float>(x+yb, -1) );
        }else{
          neighborhood.insert ( std::pair<int,float>(x+yb,pop_[x][yb]->get_fitness()) );
        } 
  return neighborhood;    

}

void World::competition(){
   
 srand(time(NULL)); 
 Bacteria* best; // Bacteria with the best fitness in a gap neighborhood
 std::map<int,float> current_neighborhood; // Neighborhood of a gap
 int pos_best; // Position of the best bacteria according its key in current_neiborhood map
 int best_pos_y; // Column of best bacteria 
 int best_pos_x; // Row of best bacteria
 std::vector<int> v_pos; // Vector of gaps arround the best bacteria
 int x;
 int y;
  
  for(x = 0; x< W_; x++){
    for(y = 0; y< H_; y++){ 
      if (pop_[x][y]==NULL){// Find gaps
        current_neighborhood = find_neighborhood(x,y); // Find neighborhood around a gap
    
        /* Search the best bacteria in the neighborhood or choose randomly the best one in case of equality*/
        int pos_best = current_neighborhood.begin()->first; //initialisation
        std::map<int,float>::const_iterator it = current_neighborhood.begin();
        std::map<int ,float>::const_iterator next_it = std::next(current_neighborhood.begin()); 
    
        /* Find maximal fitness */
        std::map<int,float> current_copy = (current_neighborhood);
        int c= current_neighborhood.size();
        while(c>=2){
     
          auto it = current_copy.begin();
          auto next_it = std::next(it); 
          if (it->second > next_it->second){
            current_copy.erase(next_it);
          }
          else if(it->second < next_it->second){
            current_copy.erase(it);
          }
          else if (it->second == next_it->second){
            int fight = rand()%2;
          if (fight >0){
            current_copy.erase(next_it);
          }
          else {
            current_copy.erase(it);
          }
        }
        --c; 
      }
      else {
        current_copy.erase(it);
      }
    }
    --c; 
    }
    pos_best = current_copy.begin()->first;
    
    if(current_neighborhood.find(pos_best)->second > -1 ){ // Check if at least one bacteria is present in the neighborhood
    // Find the best bacteria according its key of in the dicionnary
      if (pos_best!=0){
        best_pos_y = pos_best/W_;
        best_pos_x = pos_best%W_;
        best = pop_[best_pos_x][best_pos_y]; // Best bacteria found according its position
      }
      else{ // Case of impossible operation
        best_pos_y = 0;
        best_pos_x = 0;
        best = pop_[0][0]; // The best one has as coordinate (0,0)
      }
      // Find available gaps
      //neighborhood_best = find_neighborhood(best_pos_x , best_pos_y);
      for ( std::map<int,float>::const_iterator it= current_neighborhood.begin(); it!=current_neighborhood.end();++it){
        if (it->second == -1){
          v_pos.push_back(it->first);
        }
      } 
      // Choose randomly one gap
      if (v_pos.size()!=0){ // Prevent impossible operation
        int random_destination = rand()%v_pos.size();
        int destination = v_pos[random_destination];
      if (destination !=0){ // Prevent impossible operation
        int daugther_pos_y = destination/W_;
        int daugther_pos_x = destination%W_;
        Bacteria* daugther = best->divide(); 
        pop_[daugther_pos_x][daugther_pos_y] = daugther; // Fill the choosen gap and create a new bacteria
      }
      else { 
        Bacteria* daugther = best->divide(); // Help me problem of 
        pop_[0][0] = daugther; // Fill the gap in position (0,0)
      }
    }
   } // End of condition of the presence
  } // End of gap condition 
 } // for y
} // for x 

}
     

void World::update(int tours_max){
  int tours;
  int x;
  int y;
  float death = pop_[0][0]->PROBA_DEATH();
  float random_nb;
  for( tours = 0; tours < tours_max; tours++){
    if(tours%7==0){
      //this->renew();
      }
    this-> diffuse_concentration();
    //death of the bacteries // Bizzard elles ont une proba de mourir 
    for(x = 0; x <H_; x++){
      for(y = 0; y< W_; y++){
        random_nb = ((float)(rand()%101))/100.0;
        if(random_nb < death){
          pop_[x][y]-> kill_bacteria(&a_[x][y],&b_[x][y],&c_[x][y]);
          pop_[x][y]= NULL; 
        }
      }
    }
    //this-> competition();
    //metabolize
    for(x = 0; x <H_; x++){
      for(y = 0; y< W_; y++){
        pop_[x][y]->metabolize(&a_[x][y],&b_[x][y]);
      }
    }
  }
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

void World::display(int choice){ // Just for tests
  float **p;
  char which_concentration = '\0';
  
  if (choice == 1){
    p= a_;
    which_concentration ='a';
  }
  else if (choice == 2){
    p = b_;
    which_concentration ='b';
  }
  else if(choice == 3){
    p= c_;
    which_concentration ='c';
  }

  if (choice == 1|| choice==2||choice==3){
   std::cout <<"Concentration metabolites "<< which_concentration <<" : "<<std::endl;
   std::cout <<'\n';
    for (int i=0; i<H_ ; ++i){
      for (int j=0; j<W_ ; ++j){
        if (p[i][j]<10){
        std::cout <<"   "<< std::fixed<< std::setprecision(3)<<p[i][j]<<" |";
       }
       else if (p[i][j]<100){
        std::cout <<"  "<< std::fixed<< std::setprecision(3)<<p[i][j]<<" |";
       }
      else if (p[i][j]<1000){
        std::cout <<" "<< std::fixed<< std::setprecision(3)<<p[i][j]<<" |";
       }
      }
       std::cout <<'\n';
    }
  }

  
  else if (choice ==4){
   std::cout <<"genotype  : "<<std::endl;
   std::cout <<'\n';
   for (int i=0; i<H_ ; ++i){
     for (int j=0; j<W_ ; ++j){
        std::cout <<"   "<<pop_[i][j]->genotype() <<"  |";
        }
        std::cout <<'\n';
      }
    }

   else if (choice==5) {
      std::cout <<"concentration of substrat  : "<<std::endl;
      std::cout <<'\n';
      for (int i=0; i<H_ ; ++i){
        for (int j=0; j<W_ ; ++j){
          std::cout <<"   "<<pop_[i][j]->phenotype()[0] <<"  |";
        }
      std::cout <<'\n';
      } 
    }
    
    else if (choice == 6){
      std::cout <<"concentration of metabolites  : "<<std::endl;
      std::cout <<'\n';
      for (int i=0; i<H_ ; ++i){
        for (int j=0; j<W_ ; ++j){
          std::cout <<"   "<<pop_[i][j]->phenotype()[1] <<"  |";
        }
      std::cout <<'\n';
      }
    }
    else {
      std::cout<<"Choice impossible !"<<std::endl;
    }
}


vector<tuple<int,int>> World::get_empty(){
  vector<tuple<int,int>> coordinates;
  int i;
  int j;
  for(i = 0 ; i < W_ ; i++){
    for(j = 0; j < H_ ; j++){
      if(pop[j][i] == NULL){
        coordinates.pushback(make_tuple(i,j)); //WARNING : beware of the order there !!!
      }
    }
  }
  return coordinates;
}
