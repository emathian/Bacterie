#ifndef _BACTERIAGA_H_
#define _BACTERIAGA_H_

// ===========================================================================
//                                  Includes
// ===========================================================================

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
  BacteriaGa(const BacteriaGa& bactGa);

  // =========================================================================
  //                                Destructor
  // =========================================================================
 

  // =========================================================================
  //                                  Getters
  // =========================================================================
  float get_fitness() ;  
  // =========================================================================
  //                                  Setters
  // =========================================================================

  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                          Public Function members
  // =========================================================================
  //void metabolize(float a) override;
 

	protected:
  // =========================================================================
  //                        Protected Function members
  // =========================================================================
  virtual void metabolize(float *a,float * b) override;

/* The method kill_bacteria allows to update metabolites concentration in a cell
after the death of a bacteria. Like this the concentration in a cell are setted 
equal to the old one more those contained in the bacteria who is dying.
Pre-conditions : kill_bacteria's arguments are three pointer to each metabolites
 in a cell of world.
Post-conditions: This concentration are updated and the phenotype of bacteria is 
setted to null.
*/
  virtual void kill_bacteria(float *a, float *b, float *c) override;

/* Th function divide allows to create a new bateria whith a phenotype setted 
equal to her parent. (WARNING) This function must be use after decided if the daug-
ther'll be mute or not. 
*/
  
  BacteriaGa divide();

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
