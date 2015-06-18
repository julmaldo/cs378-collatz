
//#define _cashe 

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

#include "Collatz.h"

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

inline int reg_cycle_length(int i)
{
int temp = 1; 
while (i != 1){

      if (i%2 ==0) {
            i = i/2;
            temp++;
        }   
        else {
            i=i *3+1;
            temp++;
        }
    }
    return temp;
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
	#ifdef _cashe 
	int length = cycle_length(a);
    #else 
    int length = reg_cycle_length(a);
    #endif

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
