// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacteriaGa.h"
#include "BacteriaGb.h"
#include "World.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <stdio.h>
#include <algorithm>  /*shufle */
#include <iomanip>     // std::setprecision
#include <iterator>




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


    pop_ = new Bacteria** [W_];
    a_ = new float *[W_];
    b_ = new float *[W_];
    c_ = new float *[W_];

    std::vector<int> rand_v;
    for (int i = 0; i<W_*H_/2; i++){     
      rand_v.push_back(0);
    } 
    for (int j = W_*H_/2; j<W_*H_; j++){     
      rand_v.push_back(1);
    } 
    std::random_shuffle( rand_v.begin(), rand_v.end() );

    int i;
    for(int i = 0; i<W_; i++){
      pop_[i] = new Bacteria* [H_];
      a_[i] = new float [H_];
      b_[i] = new float [H_];
      c_[i] = new float [H_];
     }
    int k=0;
    int j;
    for(i = 0; i<W_; i++){
      for(j = 0; j<H_; j++){

        if (rand_v[k]==0){
          std::vector<int> current_pos ={i,j};		
          Bacteria* p_add_a = new BacteriaGa();
          pop_[i][j] = p_add_a;
          pop_[i][j]->set_pos(current_pos);
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
  for(i=0; i<W_; i++){
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
  float** stockA = a_;
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
    a_ = stockA;
    b_ = stockB;
    c_ = stockC;
  }

  std::map<int,float> World::find_neighborhood(int i, int j){
  	int x = i;
  	int y = j;
    int xg;
    int xd;
    int yh;
    int yb;
  	std::map<int,float> neighborhood;
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
    /* Problème mm si la case n'est pas vide je crée un dico ce qui est long !*/
    
    //Bacteria* will_dead_one = pop_[0][0];
    //Bacteria* will_dead_two = pop_[1][0];
  
    pop_[0][0] = NULL;
    pop_[1][0] = NULL;
    std::multimap< int,int> test;
    test = find_neighborhood(pop_[0][0]);

    srand(time(NULL));
    std::map<Bacteria *,float> neighborhood;
    std::multimap< int,int> possible_pos;
    Bacteria* best_fitness;
    std::map<int,float> neighborhood_best_fitness;
    std::vector<int> v_pos;

    int x;
    int y;
    int xg;
    int xd;
    int yh;
    int yb;
    for(x = 0; x< W_; x++){
      for(y = 0; y< H_; y++){
      	
       //if(pop_[x][y] == NULL){
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
        
        if (pop_[xg][yh] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][yh], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][yh],pop_[xg][yh]->get_fitness()) );
        }
        if (pop_[xg][y] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][y], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][y],pop_[xg][y]->get_fitness()) );
        }     
         if (pop_[xg][yb] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][yb], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xg][yb],pop_[xg][yb]->get_fitness()) );
        }     
        if (pop_[xd][yh] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][yh], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][yh],pop_[xd][yh]->get_fitness()) );
        } 
        if (pop_[xd][y] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][y], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][y],pop_[xd][y]->get_fitness()) );
        } 
        if (pop_[xd][yb] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][yb], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[xd][yb],pop_[xd][yb]->get_fitness()) );
        } 
        if (pop_[x][yh] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[x][yh], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[x][yh],pop_[x][yh]->get_fitness()) );
        } 
       if (pop_[x][yb] == NULL){
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[x][yb], -1) );
        }else{
          neighborhood.insert ( std::pair<Bacteria *,float>(pop_[x][yb],pop_[x][yb]->get_fitness()) );
        } 
        
     
        /* Search the best bacteria and choose randomly the best one in case of equality*/

        best_fitness = neighborhood.begin()->first;
        std::map<Bacteria *,float>::const_iterator it = neighborhood.begin();
        std::map<Bacteria *,float>::const_iterator next_it = std::next(neighborhood.begin());
        int c = 0;
        while(c < neighborhood.size() -1)
        {
          if (it->second > next_it->second ){
            best_fitness = it->first;
          }
          else if (it->second < next_it->second ){
            best_fitness = next_it->first;
           }
          else{
           
            int fight = rand() % 100;
             if (fight < 50){
              best_fitness = it->first;
             }
            else{
              best_fitness = next_it->first;
              }
           }
          ++c;
          ++it;
          ++next_it;

        }// while

        /* Divide bacteria and choose randomly the best place in the case there is more than one gap*/     
        /*Il faudrait retenir l'adresse des mortes */

       
        int pos_best_fitness_x = best_fitness->pos()[0];
        int pos_best_fitness_y = best_fitness->pos()[1];
        neighborhood_best_fitness = find_neighborhood(best_fitness);
        for ( std::map<int,float>::const_iterator it= neighborhood_best_fitness.begin(); it!=neighborhood_best_fitness.end();++it){
        	if (it->second == -1){
        		v_pos.push_back(it->first);
        	}
        }
        int destination = rand()%v_pos.size();
        int daugther_pos_y = destination/W_;
        int daugther_pos_x = destination%W_;

       // Bacteria* daugther = new Bacteria; 
       	Bacteria* daugther = best_fitness->divide(); // Help me problem of memory
       	pop_[daugther_pos_x][daugther_pos_y] = daugther;
        

       } 
      }
      
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
    for(x = 0; x <W_; x++){
      for(y = 0; y< H_; y++){
        random_nb = ((float)(rand()%101))/100.0;
        if(random_nb < death){
          pop_[x][y]-> kill_bacteria(&a_[x][y],&b_[x][y],&c_[x][y]);
          pop_[x][y]= NULL; 
        }
      }
    }
    //this-> competition();
    //metabolize
    for(x = 0; x <W_; x++){
      for(y = 0; y< H_; y++){
        pop_[x][y]->metabolize(&a_[x][y],&b_[x][y]);
      }
    }
  }
}
  
void World::renew(int a_init){
  for (int i=0; i<W_ ; ++i){
    for (int j=0; j<H_ ; ++j){
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
    for (int i=0; i<W_ ; ++i){
      for (int j=0; j<H_ ; ++j){
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
   for (int i=0; i<W_ ; ++i){
     for (int j=0; j<H_ ; ++j){
        std::cout <<"   "<<pop_[i][j]->genotype() <<"  |";
        }
        std::cout <<'\n';
      }
    }

   else if (choice==5) {
      std::cout <<"concentration of substrat  : "<<std::endl;
      std::cout <<'\n';
      for (int i=0; i<W_ ; ++i){
        for (int j=0; j<H_ ; ++j){
          std::cout <<"   "<<pop_[i][j]->phenotype()[0] <<"  |";
        }
      std::cout <<'\n';
      } 
    }
    
    else if (choice == 6){
      std::cout <<"concentration of metabolite  : "<<std::endl;
      std::cout <<'\n';
      for (int i=0; i<W_ ; ++i){
        for (int j=0; j<H_ ; ++j){
          std::cout <<"   "<<pop_[i][j]->phenotype()[1] <<"  |";
        }
      std::cout <<'\n';
      }
    }
    else {
      std::cout<<"Choice impossible !"<<std::endl;
    }
}
    




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
