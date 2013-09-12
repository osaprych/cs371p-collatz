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

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

//std::cout;
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

// int collatz_eval (int i, int j) {
//     // <your code>
//     int lazy_cache[1000] = { 0 };
//     if (i > j){
//     	int temp = j;
//     	j = i;
//     	i = temp;    	
//     }
//     if (j/2 > i){
//     	i = j/2;
//     }
//     int v = 1;
// 	int max = 1;
// 	int count = 0;
// 	for (; i <= j; i++){
// 		// v = stores cycle length	
// 		v = 1;
// 		count = i;
// 		while (count > 1){
// 			if (lazy_cache[count] != 0){
// 				v += lazy_cache[count];
// 				count = 1;
// 			}
// 			else if (count%2 == 0){
// 				count = count/2;
// 				v++;
// 			}
// 			else{
// 				count = 3*count + 1;
// 				v++;
// 			}
// 		}
// 		if (v > max){
// 			max = v;
// 		}
// 		if (v <= sizeof(lazy_cache) - 1){
// 			lazy_cache[i] = v;
// 		}
// 	}
// 	assert(max > 0);
// 	return max;}
int collatz_eval (int i, int j) {
    // <your code>
    using namespace std;
    int lazy_cache[10000] = { 0 };
    //cout << sizeof(lazy_cache) << endl;
    // for (int i = 1; i < 50; i++){
    // 	cout << lazy_cache[i] << endl;
    // }
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
			// if (lazy_cache[count] != 0){
			// 	return lazy_cache[count] + v;
			// }
			if ((count < 1000) && (lazy_cache[(unsigned)count] != 0)){
				v += lazy_cache[(unsigned)count];
				cout << "lazy_cache " << count << "  " << (unsigned)count << endl;
				//cout << lazy_cache[count] << endl;
				//cout << sizeof(lazy_cache) << endl;
				count = 1;
			}
			if (count%2 == 0){
				count = count/2;
				v++;
			}
			else{
				count = count + (count >> 1) + 1;//3*count + 1;
				v += 2;
				// count = 3*count + 1;
				// v++;
			}
		}
		if (v > max){
			max = v;
		}
		if (v <= 1000 && i < 1000){
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