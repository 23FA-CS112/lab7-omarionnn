/* Experiment1.h measures how long it takes to append an item to a vector or
 * list.
 *
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef EXPERIMENT1_H_
#define EXPERIMENT1_H_

#include "NanoTimer.h"

class Experiment1 {
   public:
    void run();
    void timeAppendToVectorOfSize(unsigned size);
    void timeRepeatedAppendUntilVectorIsSize(unsigned reps);
    void timeRepeatedAppendUntilListIsSize(unsigned reps);
    void timeAppendToListOfSize(unsigned size);

   private:
    const unsigned REPS = 10000;
    NanoTimer myTimer;
};

#endif /*EXPERIMENT1_H_*/