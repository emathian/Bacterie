#ifndef _BACTERIAGA_H_
#define _BACTERIAGA_H_

// ===========================================================================
//                                  Includes
// ===========================================================================
#include <iostream>
#include "Bacteria.h"

// ===========================================================================
//                             "using" statements
// ===========================================================================

class BacteriaGa : public Bacteria {
	public:
	// =========================================================================
  //                               Constructors
  // =========================================================================
  BacteriaGa();

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
  void metabolize(float a) override;

	protected:
  // =========================================================================
  //                        Protected Function members
  // =========================================================================
  void metabolize(float a);

  // =========================================================================
  //                               Data members
  // =========================================================================
 


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
