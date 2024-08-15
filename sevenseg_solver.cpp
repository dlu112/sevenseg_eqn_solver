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

// Solve the 7-Segment Equation Problem
// Assumes inputs are in correct format and that a valid answer exists
// TODO: handle invalid inputs
std::string SevenSegSolver::solve(std::string const& eqn) {
    // check initial equation for validity
    if (check_eqn(eqn)) return eqn;

    std::string eqn2;
    // iterate through each char in the string
    for (size_t i = 0; i < eqn.size(); i++) {    
        // skip any spaces in the equation
        if (!isspace(eqn[i])) {  
            // reset eqn2
            eqn2 = eqn;

            // TODO: reformat this

            // check for valid val from swapping a stick from c
            if (swap_vals.find(eqn[i]) != swap_vals.end()) {
                // foreach swap_val, swap it into the eqn
                for (char v : swap_vals.find(eqn2[i])->second) {
                    // replace with swapval and check validity of eqn
                    eqn2[i] = v;
                    if (check_eqn(eqn2)) return eqn2;
                }
            }
            
            // also check for valid val from removing a stick from c
            if (remove_vals.find(eqn[i]) != remove_vals.end()) {
                // for each remove_val
                for (char v : remove_vals.find(eqn[i])->second) { 
                    // replace with new val
                    eqn2[i] = v;
                    
                    // iterate through the entire string again
                    for (size_t j = 0; j < eqn2.size(); j++) {
                        // check for valid add_vals
                        if (add_vals.find(eqn2[j]) != add_vals.end()) {
                            // for each add_val replace and check validity of eqn
                            for (char v2 : add_vals.find(eqn2[j])->second) {
                                std::string temp = eqn2;
                                temp[j] = v2;
                                if (check_eqn(temp)) return temp;
                            }
                        }
                    }
                }
            }            
        }
    }
    
    // TODO: handle an equation with no valid result
    return eqn2;
}