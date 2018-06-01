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
  /*Default constructor*/
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
  /* Constant attributes */
  /* PROBA_MUTE_ return the probability that a bacteria mute.This attribute is
  the same for all individual in the class */
  float PROBA_MUTE() const;
  /* PROBA_MUTE_ return the probability that a bacteria mute.This attribute is
  the same for all individual in the class */
  float PROBA_DEATH() const;
  float FITNESS_MIN() const;

  std::vector<float> phenotype();

  char genotype() const;
  virtual float get_fitness()=0;

  // =========================================================================
  //                                  Setters
  // =========================================================================
  void set_phenotype(std::vector<float> new_phenotype);

  // =========================================================================
  //                          Public Function members
  // =========================================================================
  virtual void toString();
  
  virtual void metabolize(float * a, float * b)=0;

  virtual void kill_bacteria(float *a, float *b, float *c)=0;

  virtual Bacteria* divide()=0;


	protected:

  // =========================================================================
  //                               Data members
  // =========================================================================
  
  std::vector<float> phenotype_;
  float PROBA_DEATH_; // Voir pour le passer en static plus tard
  float PROBA_MUTE_; // idem
  static float FITNESS_MIN_;
  char genotype_;

};


#endif
