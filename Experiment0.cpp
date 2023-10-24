/* Experiment0.cpp defines methods for timing the vector subscript operation.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Experiment0.h"

#include <iomanip>  // setw(), fixed, showpoint, setprecision()
using namespace std;

void Experiment0::run() {
    cout << "0. Timing vector subscript operations using the average of "
         << REPS << " trials..." << endl;
    timeAccessesForVectorOfSize(10);
    timeAccessesForVectorOfSize(100);
    timeAccessesForVectorOfSize(1000);
    timeAccessesForVectorOfSize(10000);
    timeAccessesForVectorOfSize(100000);
    cout << "\nExperiment 0 complete." << endl;
}

void Experiment0::timeAccessesForVectorOfSize(int size) {
    cout << "\n* timing accesses for vector of size " << size << endl;
    myVector.resize(size);                   // set vector's size
                                             // then time access to
    timeAccessAtIndex(0);                    // - first  item
    timeAccessAtIndex(myVector.size() / 2);  // - middle item
    timeAccessAtIndex(myVector.size() - 1);  // - last item
}

void Experiment0::timeAccessAtIndex(int index) {
    cout << "-- Average time to access value at index " << setw(6) << index
         << ": " << flush;
    myTimer.reset();                  // clear the timer
    for (int i = 0; i < REPS; ++i) {  // repeatedly...
        myTimer.start();              //   start it
        myVector[index];              //   access item at index
        myTimer.stop();               //   stop it
    }
    cout << fixed << showpoint  // show average results
         << myTimer.getTotalTimeInNanos() / (double)REPS
         << " nsecs"
         // if you prefer seconds, use the next two lines instead of the
         // previous line
         //      << setprecision(12)
         //      << myTimer.getTotalTimeInSecs() / (double) REPS << " secs ("
         << endl;
}
