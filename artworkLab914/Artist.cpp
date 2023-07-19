#include "Artist.h"
#include <iostream>
#include <string>

Artist::Artist() {
    artistName = "unknown" ;
    birthYear = -1;
    deathYear = -1;
}

Artist::Artist(std::string artistName, int birthYear, int deathYear) {
    artistName = artistName;
    birthYear = birthYear;
    deathYear = deathYear;
}

std::string Artist::GetName() const {
    return artistName;
}

int Artist::GetBirthYear() const {
    return birthYear;
}

int Artist::GetDeathYear() const{
    return deathYear;
}

void Artist::PrintInfo() const {
    std::cout << "Artist: ";
    if (birthYear == -1) {
        std::cout << "unknown" << std::endl;
    } else if (deathYear == -1){
        std::cout << "(" << birthYear << " to present)" << std::endl;
    } else {
        std::cout << "(" << birthYear << " to " << deathYear << ")" << std::endl;
    }
}