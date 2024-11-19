#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>

class University {
private:
    std::string name;
    std::string country;
    int worldRanking;

    // Private helper function to validate the ranking (e.g., ensure it's positive)
    bool isValidRanking(int ranking);

public:
    // Constructor with parameters
    University(const std::string& name, const std::string& country, int worldRanking);

    // Default constructor
    University();


    // Getter for name (const correctness)
    std::string getName() const;

    // Getter for world ranking
    int getWorldRanking() const;

    // Setter for world ranking
    void setWorldRanking(int ranking);

    // Setter for name
    void setName(const std::string& newName);
};

#endif // UNIVERSITY_H