/* Experiment2.h declares a class that times the vector and list prepend
 * operations.
 *
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef EXPERIMENT2_H_
#define EXPERIMENT2_H_

#include "NanoTimer.h"

class Experiment2 {
   public:
    void run();
    void timePrependToVectorOfSize(unsigned size);
    void timeRepeatedPrependUntilVectorIsSize(unsigned reps);

   private:
    const unsigned REPS = 10000;
    NanoTimer myTimer;
};

#endif /*EXPERIMENT2_H_*/
