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
#include <algorithm>  /*shuffle */
#include <iomanip>     // std::setprecision
#include <iterator>
#include <tuple>
#include <fstream>



using namespace std;

// ===========================================================================
//                                Constructors
// ===========================================================================


World::World(int width, int height, float a_init , int T_renew ,float diffusion, float pmute){

  a_init_ = a_init;
  W_ = width;
  H_ = height;
  D_ = diffusion;
  T_renew_ = T_renew;
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

  std::random_shuffle(rand_v.begin(), rand_v.end() );

  // COmportement identique à chaque tour !!
  /*  
  for (int i=0; i!=rand_v.size();++i){
    std::cout<<rand_v[i]<<std::endl;
  }
  */
  
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
        Bacteria* p_add_a = new BacteriaGa(pmute);
        pop_[i][j] = p_add_a;
        
        //std::cout<< p_add_a <<std::endl;
        //std::cout<< pop_[i][j]->genotype() <<std::endl;
        //std::cout<< p_add_a->genotype() <<std::endl;
      }
      else{
        Bacteria* p_add_b = new BacteriaGb(pmute);
        pop_[i][j] = p_add_b;
      }
        
      a_[i][j] = a_init_;
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


void World::competition(){
	map<Bacteria *,float> neighborhood;// Initialisation of the returned ma
	int x;
	int y;
    vector<tuple<int,int>> gap;
	gap = this->get_empty();
	if (gap.empty() ==  false){
	std::random_shuffle(gap.begin(), gap.end() );
	for (int i=0; i!=gap.size(); ++i)
	{
  	  x= std::get<0>(gap[i]);
  	  y = std::get<1>(gap[i]);
      int xg;
      int xd;
      int yh;
      int yb;
  
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
    if (pop_[yh][xg] != NULL){
      neighborhood.insert ( std::pair<Bacteria*,float>(pop_[yh][xg], pop_[yh][xg]->get_fitness()) );
    }
    if (pop_[y][xg] != NULL){
      neighborhood.insert ( std::pair<Bacteria*,float>(pop_[y][xg],pop_[y][xg]->get_fitness()) );
    }
    if (pop_[yb][xg] != NULL){
      neighborhood.insert ( std::pair<Bacteria*,float>(pop_[yb][xg], pop_[yb][xg]->get_fitness()) );
    }
    if (pop_[yh][xd] != NULL){
      neighborhood.insert ( std::pair<Bacteria*,float>(pop_[yh][xd],pop_[yh][xd]->get_fitness()) );
    }
    if (pop_[y][xd] != NULL){
      neighborhood.insert ( std::pair<Bacteria*,float>(pop_[y][xd],pop_[y][xd]->get_fitness()) );
    }
    if (pop_[yb][xd] != NULL){
      neighborhood.insert ( std::pair<Bacteria*,float>(pop_[yb][xd], pop_[yb][xd]->get_fitness()) );
    }
    if (pop_[yh][x] != NULL){
          neighborhood.insert ( std::pair<Bacteria*,float>(pop_[yh][x] ,pop_[yh][x]->get_fitness()) );
    }
    if (pop_[yb][x] != NULL){
          neighborhood.insert ( std::pair<Bacteria*,float>(pop_[yb][x], pop_[yb][x]->get_fitness()) );
    }

    /* Search the best bacteria in the neighborhood or choose randomly the best one in case of equality*/
    if (neighborhood.empty()==false){
    Bacteria* best = neighborhood.begin()->first; //initialisation
    
    /* Find maximal fitness */

    //std::map<Bacteria*,float> current_copy = (neighborhood);
    int c= neighborhood.size();
    while(c>=2){
     
    auto it = neighborhood.begin();
    auto next_it = std::next(it); 
    if (it->second > next_it->second){
      neighborhood.erase(next_it);
    }
    else if(it->second < next_it->second){
      neighborhood.erase(it);
    }
    else if (it->second == next_it->second){
      int fight = rand()%2;
      if (fight >0){
        neighborhood.erase(next_it);
      }
      else {
        neighborhood.erase(it);
      }
    }
    --c; 
    }
    
    best = neighborhood.begin()->first; 
    Bacteria* daugther = best->divide(); 
    pop_[y][x] = daugther;  
 
  } // end for
  } // no bacteria in neighboorhood
 } // end no gap
}



void World::update(int tours_max){
  int tours;
  int x;
  int y;
  float death = pop_[0][0]->PROBA_DEATH();
  float random_nb;

  
  for( tours = 0; tours < tours_max; tours++){
    
    tuple<int,int> liste = this->count();
  
  float pB =float(get<1>(liste));
  float pA = float(get<0>(liste));
          
  std::ofstream outfile ("30_300_pm0.csv",ios::app);
  
  outfile <<tours << ';'<< pB << ";" << pA << endl;
     
    this-> diffuse_concentration();
    //death of the bacteries // Bizzard elles ont une proba de mourir 
    for(y = 0; y <H_; y++){
      for(x = 0; x< W_; x++){
        if(pop_[y][x] != nullptr){ // We could kill only those alieve
        random_nb = ((float)(rand()%101))/100.0;
        if(random_nb < death){
          pop_[y][x]-> kill_bacteria(&a_[y][x],&b_[y][x],&c_[y][x]);
          //delete[] pop_[y][x];
          pop_[y][x]= nullptr; 
          }
        }
      }
    }
  this->competition();

    //metabolize
    for(y = 0; y <H_; y++){
      for(x = 0; x< W_; x++){
        if(pop_[y][x] != nullptr){ // Si elle est pas morte...
          pop_[y][x]->metabolize(&a_[y][x],&b_[y][x]);
  
        }
      }
    }
    if (T_renew_ !=0){
    if(tours%T_renew_==0){
      this->renew();
    }
   
	}
  
  }
}
  


void World::renew(){
  for (int i=0; i<H_ ; ++i){
    for (int j=0; j<W_ ; ++j){
      b_[i][j]=0;
      c_[i][j]=0;
      a_[i][j]= this -> a_init_;
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
        if (pop_[i][j]==NULL){
          std::cout<<"   "<< 'X'<<"  |";
        }
        else{
          std::cout <<"   "<<pop_[i][j]->genotype() <<"  |";
        }
       }
        std::cout <<'\n';
      }
    }
  

   else if (choice==5) {
      std::cout <<"concentration of substrat  : "<<std::endl;
      std::cout <<'\n';
      for (int i=0; i<H_ ; ++i){
        for (int j=0; j<W_ ; ++j){
          if (pop_[i][j]==NULL){
            std::cout<<"      "<< 'X' <<"  |";
          }else{
            std::cout <<"   "<<pop_[i][j]->phenotype()[0] <<"  |";
          }
        }
      std::cout <<'\n';
      } 
    }
  
    
    else if (choice == 6){
      std::cout <<"concentration of metabolites  : "<<std::endl;
      std::cout <<'\n';
      for (int i=0; i<H_ ; ++i){
        for (int j=0; j<W_ ; ++j){
          if (pop_[i][j]==NULL){
            std::cout<<"       "<< 'X' <<"  |";
           }
          else{
            std::cout <<"   "<<pop_[i][j]->phenotype()[1] <<"  |";
         }
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
      if(pop_[j][i] == NULL){
        coordinates.push_back(make_tuple(i,j)); //WARNING : beware of the order there !!!
      }
    }
  }
  return coordinates;
}

tuple<int,int> World::count(){
  int a = 0;
  int b = 0;
  int i;
  int j;
  for(i = 0; i < W_ ; i++){
    for(j = 0; j < H_ ; j++){
      if (pop_[j][i] != NULL){ 		
      if(pop_[j][i]->genotype() == 'a'){
        a++;
      }
      if(pop_[j][i]->genotype() == 'b'){
        b++;
      }
     }
    }
  }
  tuple<int,int> result (a,b);
  return result;
}





















