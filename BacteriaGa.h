#ifndef _BACTERIAGA_H_
#define _BACTERIAGA_H_

// ===========================================================================
//                                  Includes
// ===========================================================================

#include "Bacteria.h"
#include "BacteriaGb.h"
// ===========================================================================
//                             "using" statements
// ===========================================================================

class BacteriaGa : public Bacteria {
  public:
  // =========================================================================
  //                               Constructors
  // =========================================================================
  /* Constructor of Bacteria A takes as parameter the probability of mutation 
  wich is common with B bacterias */  
  BacteriaGa(float proba_mute);
  // copy constructor
  BacteriaGa(const BacteriaGa& bactGa);

  // =========================================================================
  //                                Destructor
  // =========================================================================
 

  // =========================================================================
  //                                  Getters
  // =========================================================================

  float get_fitness() override;  

  // =========================================================================
  //                          Public Function members
  // =========================================================================
  /* For bacteria Ga this method takes as parameter the concentration of substrat 
  A present in the environement. BacteriasGa could use a certain quatity of this
  substrat and use this one to produce energy. This reaction  increases the
  quantity of B in cell. 
  Precondition : quantity of available A, quantities of substrat and product present in
  the bacteria must be known.
  Post-condition : The phenotype of a bacteria is updated after the execution and also
  concentrations in the environment.
  */
  void metabolize(float * a,float * b) override;

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
