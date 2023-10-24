/* Experiment1.cpp defines the methods that measure the time required
 *  to append an item to a vector or list.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Experiment1.h"

#include <iomanip>  // setw(), fixed, showpoint, setprecision()
#include <list>
#include <vector>
using namespace std;

void Experiment1::run() {
    cout << "1a. Timing vector append operations using the average of " << REPS
         << " trials..." << endl;

    timeAppendToVectorOfSize(10);
    timeAppendToVectorOfSize(100);
    timeAppendToVectorOfSize(1000);
    timeAppendToVectorOfSize(10000);
    timeAppendToVectorOfSize(100000);

    timeRepeatedAppendUntilVectorIsSize(100000);

    cout << "Experiment 1 complete." << endl;
}

void Experiment1::timeAppendToVectorOfSize(unsigned size) {
    cout << " -- time to append to a full vector of size " << setw(8) << size
         << ":\t" << flush;
    myTimer.reset();
    for (unsigned i = 0; i < REPS; i++) {  // repeatedly...
        vector<int> v(size);               // construct new size-n vector
        myTimer.start();                   // start timer
        v.push_back(i);                    // append an Item
        myTimer.stop();                    // stop timer
    }
    cout << fixed << showpoint  // display average time
         << myTimer.getTotalTimeInNanos() / (double)REPS
         << " nsecs"
         // if you prefer seconds, use the next two lines instead of the
         // previous line
         //       << setprecision(12)
         //       << myTimer.getTotalTimeInSecs() / (double) REPS << " secs"
         << endl;
}

void Experiment1::timeRepeatedAppendUntilVectorIsSize(unsigned reps) {
    cout << "\n ** average time to append to a vector growing from empty to "
            "size "
         << reps << ": \n\t" << flush;
    myTimer.reset();
    vector<unsigned> v;                    // construct empty vector
    for (unsigned i = 0; i < reps; i++) {  // repeatedly ...
        myTimer.start();                   // start timer
        v.push_back(i);                    // append an Item
        myTimer.stop();                    // stop timer
    }
    cout << fixed << showpoint  // display average time
         << myTimer.getTotalTimeInNanos() / (double)reps
         << " nsecs"
         //       << setprecision(12)
         //       << myTimer.getTotalTimeInSecs() / (double) reps << " secs"
         << '\n'
         << endl;
}
