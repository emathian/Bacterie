#ifndef _WORLD_H_
#define _WORLD_H_

// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacteriaGa.h"
#include <array>
// ===========================================================================
//                             "using" statements
// ===========================================================================
using namespace std;

class World {
   
	public:
	// =========================================================================
  //                               Constructors
  // =========================================================================
  World(BacteriaGa** population, int width, int height, float diffusion);
 // ~World();

  // =========================================================================
  //                                Destructor
  // =========================================================================
 

  // =========================================================================
  //                                  Getters
  // =========================================================================
 

  // =========================================================================
  //                                  Setters
  // =========================================================================

  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                          Public Function members
  // =========================================================================
  
  /**
  void diffuse_concentration();
  
  void competition();

 // void update();

  
  void renew();
  **/

  void display();

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
 
<<<<<<< HEAD
  BacteriaGa** pop_;
=======
  Bacteria **pop_;
>>>>>>> 6fa4dbe6cf1c5229576c6bf8bcb67fc0d9e43494
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
