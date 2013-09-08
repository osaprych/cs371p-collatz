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
#include <iterator> // istream_iterator
#include <utility>  // make_pair, pair

#include "Collatz2.h"

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream_iterator<int>& q) {
    int i = *q;
    ++q;
    int j = *q;
    ++q;
    return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (std::pair<int, int> p) {
    // <your code>
    int v = 1;
    assert(v > 0);
    return v;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, std::pair<int, int> p, int v) {
    w << p.first << " " << p.second << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    std::istream_iterator<int> b = r;
    std::istream_iterator<int> e;
    while (b != e) {
        const std::pair<int, int> p = collatz_read(b);
        const int                 v = collatz_eval(p);
        collatz_print(w, p, v);}}