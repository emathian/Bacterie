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
  World(Bacteria** population, int width, int height, float diffusion);
  ~World();

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
  
  
  void diffuse_concentration();
  void competition();
  
  /**void update();
  void renew();
  **/

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
 
  Bacteria** pop_;
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
