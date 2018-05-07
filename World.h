#ifndef _WORLD_H_
#define _WORLD_H_

// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Bacteria.h"
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
  
  World(Bacteria** population[], int length, int width, int height, float diffusion);
  ~World();
  /**void diffuse_concentration();
  void competition();
  void update();
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
  int D_ ; //diffusion coefficient
  Bacteria* pop_[][];
  float a_[][];
  float b_[][];
  float c_[][];
  
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
