#ifndef _BACTERIAGB_H_
#define _BACTERIAGB_H_

// ===========================================================================
//                                  Includes
// ===========================================================================
#include <iostream>
#include "Bacteria.h"
#include "BacteriaGa.h"
// ===========================================================================
//                            "using" statements
// ===========================================================================

class BacteriaGb: public Bacteria {
  public:
  // =========================================================================
  //                               Constructors
  // =========================================================================
    /* Constructor of Bacteria Gb takes as parameter the probability of mutation 
  wich is common with  A bacterias */ 
  BacteriaGb(float proba_mute);
  // copy constructor
  BacteriaGb(const BacteriaGb& bactGb);
  // =========================================================================
  //                                Destructor
  // =========================================================================
 

  // =========================================================================
  //                          Public Function members
  // =========================================================================
   /* For bacteria B this method takes as parameter the concentration of substrat 
  B present in the environement. BacteriasGb could use a certain quatity of this
  substrat and use this one to produce energy. This reaction  increases the
  quantity of B in cell. 
  Precondition : quantity of available B, quantities of substrat and product present in
  the bacteria must be known.
  Post-condition : The phenotype of a bacteria is updated after the execution and also
  concentrations in the environment.
  */
  void metabolize(float *a,float * b) override;

  float get_fitness() override ;  
  
  void kill_bacteria(float *a, float *b, float *c) override;

  protected:
  // =========================================================================
  //                        Protected Function members
  // =========================================================================

  /* For bacteria Ga the method divide allows to create a bacteria A if a random
  number is over its probability of mutation, a B otherwise.
  Precondition : The phenotype of a bacteria Ga must be known and also its probability
  of mutation
  Postcondition : A bacteria Ga or Gb is generated, and bacterias' phenotypes are updated.  */
  Bacteria* divide() override;
};



#endif
