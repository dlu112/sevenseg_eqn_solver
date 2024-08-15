#include "sevenseg_solver.h"
#include <iostream>

// Converts one half of a string equation to an integer result
// TODO: handle negative values
int SevenSegSolver::solve_string_eqn(std::string const& eqn) {    
    std::vector<char> operators;
    std::vector<int> values;
    std::string temp;
    
    // separate values from operators into separate vectors
    for (size_t i = 0; i <= eqn.size(); i++) {
        if (i == eqn.size()) {
            values.push_back(stoi(temp));
        } else if (eqn[i] == '+' || eqn[i] == '-' ) {
            values.push_back(stoi(temp));
            temp.clear();
            operators.push_back(eqn[i]);
        } else if (!isspace(eqn[i])) {
            temp += eqn[i];
        }
    }
    
    // solve the equation
    int result = values[0];
    for (size_t j = 0; j < operators.size(); j++) {
        if (operators[j] == '+') result += values[j+1];
        else result -= values[j+1];
    }
    
    return result;
}

// Checks if a given string equation of form "x = y" is valid
bool SevenSegSolver::check_eqn(std::string const& eqn) {
    // std::cout << "Checking equation: " << eqn << std::endl;
    // split string into the two halves of the equation
    int splitter = eqn.find('=');
    std::string lhs_str = eqn.substr(0, splitter);
    std::string rhs_str = eqn.substr(splitter + 1, eqn.back());
    
    // convert each half to an integer result
    int lhs_eqn = solve_string_eqn(lhs_str);
    int rhs_eqn = solve_string_eqn(rhs_str);
    
    // compare halves
    return lhs_eqn == rhs_eqn;
}

std::string SevenSegSolver::swap_and_check(std::map<char, std::vector<char>> const& map, 
                                            std::string const& eqn,
                                            size_t const& it) {
    if (map.find(eqn[it]) != map.end()) {
        // for each add_val replace and check validity of eqn
        for (char v : map.find(eqn[it])->second) {
            std::string temp = eqn;
            temp[it] = v;
            if (check_eqn(temp)) {
                solved = true;
                return temp;
            }
        }
    }

    return eqn;
}

// Solve the 7-Segment Equation Problem
// Assumes inputs are in correct format and that a valid answer exists
// TODO: handle invalid inputs
std::string SevenSegSolver::solve(std::string const& eqn) {
    solved = false;

    // check initial equation for validity
    std::cout << "Initial equation: " << eqn << std::endl;
    if (check_eqn(eqn)) return eqn;

    // iterate through each char in the string
    for (size_t i = 0; i < eqn.size(); i++) {    
        // skip any spaces in the equation
        if (!isspace(eqn[i])) {  
            // check for valid val from swapping a stick from c
            std::string res = swap_and_check(swap_vals, eqn, i);
            if (solved) return res;
            
            // also check for valid val from removing a stick from c
            if (remove_vals.find(eqn[i]) != remove_vals.end()) {
                std::string eqn2 = eqn;
                // for each remove_val
                for (char v : remove_vals.find(eqn[i])->second) { 
                    // replace with new val
                    eqn2[i] = v;
                    
                    // iterate through the entire string again
                    for (size_t j = 0; j < eqn2.size(); j++) {
                        // check for valid add_vals
                        std::string res = swap_and_check(add_vals, eqn2, j);
                        if (solved) return res;
                    }
                }
            }            
        }
    }
    
    // TODO: handle an equation with no valid result
    return eqn;
}