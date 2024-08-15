#ifndef SEVENSEG_SOLVER_H
#define SEVENSEG_SOLVER_H

#include <map>
#include <string>
#include <vector>

class SevenSegSolver {
    private:
        std::map<char, std::vector<char>> add_vals = {
            {'1', {'7'}},
            {'3', {'9'}},
            {'5', {'6', '9'}},
            {'6', {'8'}},
            {'9', {'8'}},
            {'0', {'8'}},
            {'-', {'+'}}
        };
        std::map<char, std::vector<char>> remove_vals = {
            {'6', {'5'}},
            {'7', {'1'}},
            {'8', {'6', '8', '9'}},
            {'9', {'5'}},
            {'+', {'-'}}
        };
        std::map<char, std::vector<char>> swap_vals = {
            {'2', {'3'}},
            {'3', {'2', '5'}},
            {'5', {'3'}},
            {'6', {'9'}},
            {'9', {'6'}},
            {'0', {'6', '9'}}
        };

        int solve_string_eqn(std::string const& eqn);
        bool check_eqn(std::string const& eqn);

    public:
        std::string solve(std::string const& eqn);
};

#endif