#ifndef _BACTERIA_H_
#define _BACTERIA_H_

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <vector>
#include <stdlib.h> // rand
#include <time.h>

// ===========================================================================
//                             "using" statements
// ===========================================================================

/* Bacteria is a virtual class use by daugthers' classes BacteriaGa and 
BacteriaGb */

class Bacteria {
	public:
  
	// =========================================================================
  //                               Constructors
  // =========================================================================
  /*Default constructor */
  Bacteria();
  /*Copy constructor */
  Bacteria(const Bacteria& bact); 

  // =========================================================================
  //                                Destructor
  // =========================================================================
  virtual ~Bacteria()=default;

  // =========================================================================
  //                                  Getters
  // =========================================================================
 
  /* PROBA_MUTE_ return the probability that a bacteria mute.This attribute is
  the same for all individual in the class */
  float PROBA_MUTE() const;
  /* PROBA_MUTE_ return the probability that a bacteria mute.This attribute is
  the same for all individual in the class */
  float PROBA_DEATH() const;
  /* FITNESS_MIN return the minimal fitness of a bacteria that it's to say the con-
  centration of the metabolism product, either B for bacteria a and C for bacterias b.
  The minimal fitness allows to know if a bacteria could divide itself. */
  float FITNESS_MIN() const;
  /* phenotype a vector of metabolite and product at time t in a cell */
  std::vector<float> phenotype();
  /* genotype return the bacterias' species */
  char genotype() const;
  /* get_fitness return the current fitness of a bacteria.*/ 
  virtual float get_fitness()=0;

  // =========================================================================
  //                                  Setters
  // =========================================================================
  /* set_phenotype allow to update phenotype in function of current concentration 
  in the environment.
  Precondition : the parameter is a vector of with the phenotype to update.
  Post-condition : Bacteria's phenotype is update after the execution of this method
   */
  void set_phenotype(std::vector<float> new_phenotype);

  // =========================================================================
  //                          Public Function members
  // =========================================================================
  /* toString : Display the probability of probability of death and its probability
  of mute. */
  virtual void toString();
  /* metabolize is a method that takes the current concentration of metabolite in the environement
  and update internal concentration in the bacteria and external metabolite's concentration.
  Precondition : we know current phenotype of the bacteria, and concentration of metabolite of world
  Post-condition: bacteria's phenotype is updated and also external concentration of metabolite.  */
  virtual void metabolize(float * a, float * b)=0;
  /* kill bacteria is a method that allows to add in the environement the current concentration in the
  bateria supposed to die; also this method delete a bacteria.
  Precondition : we know the concentration of each metabolite
  Post-condition : the current bacteria is delete, and external concentration are updated. */
  virtual void kill_bacteria(float *a, float *b, float *c)=0;
  /* divide is method that allow to create a new bacteria from a pre-existant one. The daaugther is 
  initialize with the half concentration of the mother one. Furthemore the daugther's genotype is setted to
  the mother one in function of a random float compare its probility of mute. If the random number is lower than
  mute probability the other genotype is create, in this case concentration of subtrate is settted to zero 
  and concentration of product is setted to the half of mother subtrate concentration.*/ 
  virtual Bacteria* divide()=0;


	protected:

  // =========================================================================
  //                               Data members
  // =========================================================================
  // vector of float containing concentration of subtrate and metabolism product at each time

  std::vector<float> phenotype_; 
  float PROBA_DEATH_; 
  float PROBA_MUTE_; // Probability that a bacteria change its type during a division event
  static float FITNESS_MIN_; //Undre a the minimal fitness a bacteria can't divide itself.
  char genotype_;

};


#endif
