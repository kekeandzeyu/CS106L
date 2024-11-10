/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <random>
#include <algorithm>

#include "utils.h"

std::string kYourName = "Zeyu Li"; 

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
    std::ifstream file(filename);
    std::set<std::string> applicants;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return applicants;
    }

    /* Get applicants' names line by line */
    std::string name;
    while (std::getline(file, name)) {
        applicants.insert(name);
    }

    return applicants;
}

/**
 * Helper function to check if two strings have the same initials.
 * 
 * @param name1 The first name to compare.
 * @param name2 The second name to compare.
 * @return      True if the two names have the same initials, false otherwise.
 */
bool same_initials(const std::string& name1, const std::string& name2) {
    size_t name1_space = name1.find(' ');
    size_t name2_space = name2.find(' ');

    /* Handle cases where there is only a first name, no name, etc. */
    if (name1_space == std::string::npos || name2_space == std::string::npos) {
        return false;
    }

    return name1[0] == name2[0] && name1[name1_space + 1] == name2[name2_space + 1];
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
    std::queue<const std::string*> matches;

    for (const std::string& student : students) {
        if (same_initials(name, student)) {
            /* Push the address of the student */
            matches.push(&student);
        }
    }

    // Alternate Implementation Using Iterators, cbegin & cend for read only
    // for (auto student = students.cbegin(); student != students.cend(); ++student) {
    //     if (same_initials(name, *student)) {
    //         matches.push(&(*student));
    //     }
    // }

    return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
    if (matches.empty()) {
        return "NO STUDENT FOUND.";
    }

    /* Random Selection (using std::shuffle for better randomness) */
    std::vector<const std::string*> match_vec;
    while (!matches.empty()) {
        match_vec.push_back(matches.front());
        matches.pop();
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(match_vec.begin(), match_vec.end(), g);

    return *match_vec[0];

    /* Alternate Implementation */
    // const std::string* longest_match = nullptr;
    // size_t max_length = 0;
    // 
    // while (!matches.empty()) {
    //     const std::string* current_match = matches.front();
    //     matches.pop();
    // 
    //     if (current_match->length() > max_length) {
    //         max_length = current_match->length();
    //         longest_match = current_match;
    //     }
    // }
    // 
    // return (longest_match) ? *longest_match: "NO MATCHES FOUND."; // Return longest or default message
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
