/* NanoTimer.h provides a simple nanosecond-granularity
 * stopwatch-timer using C++=11's standard chrono library.
 *
 *  Created on: Mar 8, 2022
 *  Author: Joel Adams, Calvin University
 *
 *  Usage:
 *    NanoTimer nt;   // create a timer
 *    nt.start();     // start the timer
 *    nt.stop();      // stop the timer
 *    nt.get...       // read the timer's value (see below)
 *    nt.reset();     // reset the timer's accumulator
 */

#ifndef NANOTIMER_H_
#define NANOTIMER_H_

#include <chrono>    // nano-scale timing
#include <iomanip>   // output formatting
#include <iostream>  // I/O classes
using namespace std;

const long double NANOS_PER_SEC = 1.0e9;

class NanoTimer {
   public:
    // stopwatch constructor: initialize accumulator
    NanoTimer() { myTotalTime = 0.0; }

    // stopwatch start: save start time
    void start() { myStart = chrono::steady_clock::now(); }

    // stopwatch stop: save end time;
    //  then add difference of stop-start to accumulator
    void stop() {
        myStop = std::chrono::steady_clock::now();
        unsigned long long diff =
            std::chrono::duration_cast<std::chrono::nanoseconds>(myStop -
                                                                 myStart)
                .count();
        myTotalTime += diff;
    }

    // stopwatch reset: clear accumulator
    void reset() { myTotalTime = 0.0; }

    // *** Use these to get the accumulated time when the timer is stopped

    // return the accumulated time in nanoseconds when timer is stopped
    unsigned long long getTotalTimeInNanos() const { return myTotalTime; }

    // return the accumulated time in seconds when timer is stopped
    long double getTotalTimeInSecs() const {
        return myTotalTime / NANOS_PER_SEC;
    }

    // *** Use these to get the elapsed time while the timer is running

    // return the elapsed time in nanoseconds while timer is running
    unsigned long long getElapsedTimeInNanos() const {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
                   std::chrono::steady_clock::now() - myStart)
            .count();
    }

    // return the elapsed time in seconds while timer is running
    long double getElapsedTimeInSecs() const {
        return chrono::duration_cast<chrono::seconds>(
                   std::chrono::steady_clock::now() - myStart)
            .count();
    }

   private:
    unsigned long long myTotalTime;                    // time accumulator
    chrono::time_point<chrono::steady_clock> myStart;  // starting time
    chrono::time_point<chrono::steady_clock> myStop;   // stopping time
};

/* insertion operator for ostream output
 * Receive: out, an ostream;
 *          aTimer, a NanoTimer.
 * Postcondition: aTimer's double representation
 *                 has been inserted into out.
 * Return: out (for chaining insertions).
 */
inline ostream& operator<<(ostream& out, const NanoTimer& aTimer) {
    out << fixed << showpoint << setprecision(12)
        << aTimer.getTotalTimeInSecs();
    return out;
}

#endif /* NANOTIMER_H_ */
