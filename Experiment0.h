/* Experiment0.h declares a class that times the vector subscript operation.
 *
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef EXPERIMENT0_H_
#define EXPERIMENT0_H_

#include <vector>

#include "NanoTimer.h"
using namespace std;

class Experiment0 {
   public:
    void run();
    void timeAccessesForVectorOfSize(int size);
    void timeAccessAtIndex(int index);

   private:
    const int REPS = 10000;
    NanoTimer myTimer;
    vector<long> myVector;
};

#endif /*EXPERIMENT0_H_*/
