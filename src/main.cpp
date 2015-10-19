#include <iostream>
#include <chrono>
#include "stime.cpp"
#include "structures.cpp"
#include "exact.cpp"
#include "approx.cpp"

using namespace std;


int main() {
        // int max = 20000;
    // int maxtime = 5000000;
    cout << measure<>::execution(exact, cin, cout) << endl;

    // int iter = 100000;
    // int i;
    // chrono::seconds s (0);
    // chrono::microseconds avg = chrono::duration_cast<chrono::microseconds> (s);;
    // for (i = 0; i < iter; ++i) {
    //     avg += measure<>::duration(functor, max);
    //     if (avg.count() > maxtime) break;
    // }
    // cout << "it: " << i << ", " << avg.count()/(double)i << endl;
}
