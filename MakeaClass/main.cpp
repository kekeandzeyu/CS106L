/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include "class.h"

/* #### Please don't change this line! #### */
int run_autograder();

int main() {
    // The following data is from QS World Ranking 2024. Just for fun!

    // Constructing University objects using different methods
    University mit("Massachusetts Institute of Technology", "USA", 1);
    University oxford("University of Oxford", "UK", 2); 
    University defaultUni; 

    // Add Peking University
    University pku("Peking University", "China", 17);  

    std::cout << mit.getName() << " is ranked #" << mit.getWorldRanking() << std::endl;
    // Massachusetts Institute of Technology is ranked #1
    std::cout << oxford.getName() << " is ranked #" << oxford.getWorldRanking() << std::endl;
    // University of Oxford is ranked #2
    std::cout << pku.getName() << " is ranked #" << pku.getWorldRanking() << std::endl;
    // Peking University is ranked #17

    // Using the setter
    oxford.setWorldRanking(3); // True Ranking!
    std::cout << oxford.getName() << " is now ranked #" << oxford.getWorldRanking() << std::endl;
    // University of Oxford is now ranked #3


    // Demonstrating use of the default constructor and setters
    std::cout << defaultUni.getName() << " is ranked #" << defaultUni.getWorldRanking() << std::endl; 
    // Unknown is ranked #0
    defaultUni.setName("Tsinghua University");
    defaultUni.setWorldRanking(25);
    std::cout << defaultUni.getName() << " is now ranked #" << defaultUni.getWorldRanking() << std::endl;
    // Tsinghua University is now ranked #25

    /* #### Please don't change this line! #### */
    return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"