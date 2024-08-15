#include "sevenseg_solver.h"
#include <iostream>

int main() {
    SevenSegSolver solver;
    // manual test cases
    std::cout << solver.solve("4 + 4 + 4 - 4 = 18") << std::endl << std::endl;
    std::cout << solver.solve("7 + 1 = 5") << std::endl << std::endl;
    std::cout << solver.solve("2 + 10 + 100 = 12 + 101") << std::endl << std::endl;
    std::cout << solver.solve("3 - 7 + 10 = 18 + 10") << std::endl << std::endl;
    std::cout << solver.solve("3 - 7 = 18") << std::endl << std::endl;
    std::cout << solver.solve("8 = 5") << std::endl << std::endl;
    std::cout << solver.solve("3 - 7 + 10 = 28") << std::endl << std::endl;
    std::cout << solver.solve("28 = 3 - 7 + 10") << std::endl << std::endl;
}