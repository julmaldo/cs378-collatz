// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

//#include <iostream> // cin, cout


// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair



using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}
int cycle_cache[1000001];

// -------------
// cycle_length 
// -------------

inline int cycle_length(int i)
{
    int j = i;
    int length = 1;
    if ( i <= 1000000 && cycle_cache[i] != 0) return cycle_cache[i];
    while (i > 1)
    {
        if(i <= 1000000 && cycle_cache[i] != 0)
        {
            length += cycle_cache[i] - 1;
            break;
        }
        if(i % 2 == 0)
        {
            i >>= 1;
            ++length;
        }
        else 
        {
            i = i + (i >> 1) + 1;
            length += 2;
        }
    }
    cycle_cache[j] = length;
    return length;
}


// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
int first=0; int last=0;
if (i<=j) {
     first = i; last = j;
} 
else { 
    first = j; last = i;
} 
if (last/2 >first){
    first=last/2 +1;
}

int High = 0;
for ( int a = first; a <= last; a= a+1)
{

    int length = cycle_length(a);
 
   

    if (length >= High){
        High = length;
    }
}
    return High;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
        
        
        // -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout




// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}

/*
% g++-4.8 -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% cat RunCollatz.in
1 10
100 200
201 210
900 1000



% RunCollatz < RunCollatz.in > RunCollatz.out



% cat RunCollatz.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/



