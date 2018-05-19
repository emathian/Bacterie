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
