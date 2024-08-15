#include "Solver.h"
#include <iostream>
#include <cassert>

// TODO: write proper unit tests
int main() {
    Solver solver;
    // manual test cases
    assert(solver.solve("4 + 4 + 4 - 4 = 18") == "4 + 4 + 4 + 4 = 16");
    assert(solver.solve("7 + 1 = 5") == "7 - 1 = 6");
    assert(solver.solve("2 + 10 + 100 = 12 + 101") == "3 + 10 + 100 = 12 + 101");
    assert(solver.solve("3 - 7 + 10 = 18 + 10") == "3 + 7 + 10 = 10 + 10");
    assert(solver.solve("3 - 7 = 18") == "3 + 7 = 10");
    assert(solver.solve("8 = 5") == "6 = 6");
    assert(solver.solve("3 - 7 + 10 = 28") == "3 + 7 + 10 = 20");
    assert(solver.solve("28 = 3 - 7 + 10") == "20 = 3 + 7 + 10");
}