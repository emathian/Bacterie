#ifndef _WORLD_H_
#define _WORLD_H_

// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacteriaGa.h"
#include <array>
#include <vector>
#include <string.h> 
#include <map>
#include <tuple>
// ===========================================================================
//                             "using" statements
// ===========================================================================
using namespace std;

class World {
   
	public:
	// =========================================================================
  //                               Constructors
  // =========================================================================
  

  /* Constructor
  width : number of columns
  height : number of rows
  diffusion : coefficient on diffusion
  Preconditions: width and height not negative or null.
  Postconditions : creates 3 2D arrays containing bacterias and metabolites. */
  World(int width, int height, float a_init, int T_renew,float diffusion);
 

  // =========================================================================
  //                                Destructor
  // =========================================================================
  
  /* Destructor
  Frees manually allocated memory. */
 ~World();
  
  // =========================================================================
  //                          Public Function members
  // =========================================================================
  
  /* competition
  Browses the 2D array of Bacterias and makes the best bacterias divide in empty 
  adjacent box.
  Preconditions: none
  Postconditions: the population is modified, bacterias dividing themselves if they can.
  */
  void competition();

  /* diffuse_concentration
  Called at each iteration to perform natural diffusion of metabolites in the medium.
  Preconditions: none
  Postconditions: modifies the arrays of concentrations of the metabolites A, B and C.
  */
  void diffuse_concentration(); // A mettre en privé ?

  /* update
  Calls all other methods in order to simulate the evolution.
  Diffuses metabolites, make bacterias fight to survive (kills and divide Bacterias) 
  and renews medium.
  Preconditions: none
  Postconditions: the population is modified. All 7 iterations, the mediump is renewed.
  */
  void update(int tours_max);

  /* renew
  Changes the concentration of metabolites in the medium.
  Preconditions: none
  Postconditions: metabolite A is set to 50, B and C to 0.
  */
  void renew();

  /* display
  Displays differents aspects of the world according to the int.
  Preconditions: none
  Postconditions: if choice=1: displays medium A.
  if choice=2: displays medium B.
  if choice=3: displays medium C.
  if choice=4: displays genotype of the bacterias.
  if choice=5: displays fitness of bacterias.
  if choice=6: displays other metabolites (Ga : B, Gb: C) contained in each bacteria.
  if choice>6 or <0 : displays "Choice impossible!"
  */
  void display(int choice);

  /* find_neighborhood 
  Allows to record the neighborhood of a cell in a dictionnary.
  Pre-conditions: Neighborhood takes as arguments i (column) and j (row). 
  Post-condition : Owing to these coordinates the function fills a dictionnary of 8 
  elements wich corresponds to each cell of the Moore neighborhood. Keys are integers
  which are the result of the sum of the two coordinates given in argument. Like this,
  the position of the cell in the grid can be find. Values corresponds to the fitness
  of a bacteria if the cell is full, otherwise values are settled to the default 
  number -1.  */
  map<int,float> find_neighborhood(int i, int j);
  /**methode pour avoir une liste de coordonnees x,y des cases vides **/
  vector<tuple<int,int>> get_empty(); 

	private:
  // =========================================================================
  //                        Private Function members
  // =========================================================================

  // =========================================================================
  //                               Data members
  // =========================================================================
    
  // size of the world
  Bacteria* **pop_; // Array of population (Bacterias Ga or Gb)
  int W_ ; 
  int H_ ;
  float D_ ; //diffusion coefficient
 

  
  
  // Arrays of metabolites
  float **a_;
  float **b_;
  float **c_;
  float a_init_;
  int T_renew_;
  
};


#endif
