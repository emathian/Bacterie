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
// ===========================================================================
//                             "using" statements
// ===========================================================================
using namespace std;

class World {
   
	public:
	// =========================================================================
  //                               Constructors
  // =========================================================================



  World(int width, int height, float diffusion);
 

  // =========================================================================
  //                                Destructor
  // =========================================================================
 
 ~World();
  // =========================================================================
  //                                  Getters
  // =========================================================================
  void pop();

  // =========================================================================
  //                                  Setters
  // =========================================================================

  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                          Public Function members
  // =========================================================================
  
  void competition();
  void diffuse_concentration(); // A mettre en privé ?
  void update(int tours_max);
  void renew(int a_init);
  void display(int choice);

  /* find_neighborhood is a function allowing to reccord in a dictionnary the neighbor-
  hood of a cell.
  Pre-condition : Neighborhood takes as arguments two int that correspond to a po-
  sition in the grid, by row and by column.  
  Post-condition : Owing to these coordinates the function fill a dictionnary of 8 
  elements wich correspond to each cell of the Moore neighborhood. Keys are integers
  which are the result of the sum of the two coordinates given in argument. Like this
  the position of the cell in the grid could be find. Values correspond to the fitness
  of a bacteria if the cell is full, otherwise values are settesd equal to the default 
  number -1.  */
  std::map<int,float> find_neighborhood(int i, int j);

	private:
  // =========================================================================
  //                        Private Function members
  // =========================================================================

  // =========================================================================
  //                               Data members
  // =========================================================================
    
  // size of the world
  int W_ ; 
  int H_ ;
  float D_ ; //diffusion coefficient
 

  Bacteria* **pop_;

  float **a_;
  float **b_;
  float **c_;
  
};

// ===========================================================================
//                            Getters' definitions
// ===========================================================================


// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================



#endif
