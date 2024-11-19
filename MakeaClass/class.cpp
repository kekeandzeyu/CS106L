#include "class.h"
#include <iostream> 

University::University(const std::string& universityName, const std::string& universityCountry, int universityWorldRanking) : name(universityName), country(universityCountry), worldRanking(universityWorldRanking) {
    if (!isValidRanking(worldRanking)) {
        std::cerr << "Invalid ranking provided. Setting to 0." << std::endl;
        worldRanking = 0; // Or throw an exception for more robust error handling
    }
}


University::University() : name("Unknown"), country("Unknown"), worldRanking(0) {}

std::string University::getName() const {
    return name;
}


int University::getWorldRanking() const {
    return worldRanking;
}


void University::setWorldRanking(int ranking) {
    if (isValidRanking(ranking)) {
        worldRanking = ranking;
    } else {
        std::cerr << "Invalid ranking provided.  Ranking not updated." << std::endl;
    }
}

void University::setName(const std::string& newName) {
    name = newName;
}


bool University::isValidRanking(int ranking) {
    return ranking > 0; 
}