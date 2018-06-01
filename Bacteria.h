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


class Bacteria {
	public:
  
	// =========================================================================
  //                               Constructors
  // =========================================================================
  Bacteria();
  Bacteria(const Bacteria& bact); 

  // =========================================================================
  //                                Destructor
  // =========================================================================
  virtual ~Bacteria()=default;

  // =========================================================================
  //                                  Getters
  // =========================================================================
  float PROBA_MUTE() const;
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
