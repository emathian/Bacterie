#ifndef _BACTERIAGB_H_
#define _BACTERIAGB_H_

// ===========================================================================
//                                  Includes
// ===========================================================================
#include <iostream>
#include "Bacteria.h"
// ===========================================================================
//                             "using" statements


class BacteriaGb: public Bacteria {
	public:
	// =========================================================================
  //                               Constructors
  // =========================================================================
  BacteriaGb();
  BacteriaGb(const BacteriaGb& bactGb);
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
  void metabolize(float *a,float * b) override;
  float get_fitness() ;  

	protected:
  // =========================================================================
  //                        Protected Function members
  // =========================================================================

/* The method kill_bacteria allows to update metabolites concentration in a cell
after the death of a bacteria. Like this the concentration in a cell are setted 
equal to the old one more those contained in the bacteria who is dying.
Pre-conditions : kill_bacteria's arguments are three pointer to each metabolites
 in a cell of world.
Post-conditions: This concentration are updated and the phenotype of bacteria is 
setted to null.
*/
  virtual void metabolize(float b) override;
  virtual void kill_bacteria(float *a, float *b, float *c) override;

/* Th function divide allows to create a new bateria whith a phenotype setted 
equal to her parent. (WARNING) This function must be use after decided if the daug-
ther'll be mute or not. 
*/
 
   BacteriaGb divide();
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
