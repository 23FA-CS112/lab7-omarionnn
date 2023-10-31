/* Experiment2.cpp defines the methods that measure the time required
 *  to prepend an item to a vector or list.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Experiment2.h"

#include <iomanip>  // setw(), fixed, showpoint, setprecision()
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void Experiment2::run() {
    cout << "2a. Timing vector prepend operations using the average of " << REPS
         << " trials..." << endl;

    timePrependToVectorOfSize(10);
    timePrependToVectorOfSize(100);
    timePrependToVectorOfSize(1000);
    timePrependToVectorOfSize(10000);
    timePrependToVectorOfSize(100000);

    timeRepeatedPrependUntilVectorIsSize(100000);

    cout << "2b. Timing list prepend operations using the average of " << REPS
         << " trials..." << endl;

    timePrependToListOfSize(10);
    timePrependToListOfSize(100);
    timePrependToListOfSize(1000);
    timePrependToListOfSize(10000);
    timePrependToListOfSize(100000);

    timeRepeatedPrependUntilListIsSize(100000);

    cout << "Experiment 2 complete." << endl;
}

void Experiment2::timePrependToVectorOfSize(unsigned size) {
    cout << " - time to prepend to a full vector of size " << setw(8) << size
         << ":\t" << flush;
    myTimer.reset();
    for (unsigned i = 0; i < REPS; i++) {  // repeatedly...
        vector<unsigned> v(size);          // construct new size-n vector
        myTimer.start();                   // start timer
        v.insert(v.begin(), i);            // prepend item
        myTimer.stop();                    // stop timer
    }
    cout << fixed << showpoint  // compute average time
         << myTimer.getTotalTimeInNanos() / (double)REPS
         << " nsecs"
         // if you prefer seconds, use the next two lines instead of the
         // previous line
         //         << setprecision(12)
         //         << myTimer.getTotalTimeInSecs() / (double) REPS << " secs"
         << endl;
}

void Experiment2::timeRepeatedPrependUntilVectorIsSize(unsigned reps) {
    cout << "\n ***  average time to prepend to a vector growing from empty to "
            "size "
         << reps << ":\n\t" << flush;
    myTimer.reset();
    vector<unsigned> v;                    // costruct new empty vector
    for (unsigned i = 0; i < reps; i++) {  // repeatedly...
        myTimer.start();                   // start timer
        v.insert(v.begin(), i);            // prepend item
        myTimer.stop();                    // stop timer
    }
    cout << fixed << showpoint  // compute average time
         << myTimer.getTotalTimeInNanos() / (double)reps
         << " nsecs"
         // if you prefer seconds, use the next two lines instead of the
         // previous line
         //         << setprecision(12)
         //         << myTimer.getTotalTimeInSecs() / (double) reps << " secs"
         << '\n'
         << endl;
}

void Experiment2::timePrependToListOfSize(unsigned size){
    cout << "- time to append to a full list of size " << setw(8) << size
         << ":\t" << flush;
    myTimer.reset();
    for (unsigned i = 0; i < REPS; i++) {  // repeatedly ...
        list <unsigned> l(size);                 // construct a new n-size list
        myTimer.start();                   // start timer
        //l.push_back(i);                    // append an Item
        myTimer.stop();                    // stop timer
        l.push_front(i);
    }
    cout << fixed << showpoint  // display average time
         << myTimer.getTotalTimeInNanos() / (double)REPS
         << " nsecs"
         // if you prefer sec, use the next two lines instead of the previous line 
         //       << setprecision(12)
         //       << myTimer.getTotalTimeInSecs() / (double) reps << " secs"
         << endl;
}

void Experiment2::timeRepeatedPrependUntilListIsSize(unsigned reps){
    cout << "\n *** average time to append to a list growing from empty to " 
         "size"
         <<reps<< ": \n\t" << flush;
    myTimer.reset();
    list <unsigned> l;                     // constructing of empty vector 
    for (unsigned i = 0; i < reps; i++) {  // repeatedly ...              
        myTimer.start();                   // start timer
        l.push_back(i);                    // append an Item
        myTimer.stop();                    // stop timer
    }

    cout << fixed << showpoint  //display average time  
    << myTimer.getTotalTimeInNanos() / (double)reps
    << " nsecs"
    //       << setprecision(12)
    //       << myTimer.getTotalTimeInSecs() / (double) reps << " secs"
    << '\n'
    << endl;
}