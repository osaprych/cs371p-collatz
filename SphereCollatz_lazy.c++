// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

//#include "Collatz.h"

int lazy_cache[10000] = { 0 };

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    using namespace std;

    if (i > j){
    	int temp = j;
    	j = i;
    	i = temp;    	
    }
	if (j/2 > i){
		i = j/2;
	}
    int v = 1;
	int max = 1;
	int count = 0;
	for (; i <= j; i++){
		// v = stores cycle length	
		v = 1;
		count = i;
		while (count > 1){
			if ((count < 10000) && (lazy_cache[(unsigned)count] != 0)){
				v += lazy_cache[(unsigned)count];
				count = 1;
			}
			if (count%2 == 0){
				count = count>>1;
				v++;
			}
			else{
				count = count + (count >> 1) + 1;// (3n+1)/2
				v += 2;
			}
		}
		if (v > max){
			max = v;
		}
		if (v <= 10000 && i < 10000){
			lazy_cache[(unsigned)count] = v;
		}
	}
	assert(max > 0);
	return max;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    using namespace std;
	int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
	//cout << v << endl;
        collatz_print(w, i, j, v);}}

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}