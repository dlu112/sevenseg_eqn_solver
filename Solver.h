#ifndef SOLVER_H
#define SOLVER_H

#include <map>
#include <string>
#include <vector>

class Solver {
    private:
        // maps used for validating adding, removing, and swapping segments
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
            {'8', {'6', '9', '0'}},
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

        bool solved = false;

        int solve_string_eqn(std::string const& eqn);
        bool check_eqn(std::string const& eqn);
        std::string swap_and_check(std::map<char, std::vector<char>> const& map, 
                                    std::string const& eqn,
                                    size_t const& it);

    public:
        std::string solve(std::string const& eqn);
};

#endif