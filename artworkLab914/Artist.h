//
// Created by Collins Gichohi on 3/18/23.
//

#ifndef ARTWORKLAB914_ARTIST_H
#define ARTWORKLAB914_ARTIST_H

#include <string>


class Artist{
public:
    Artist();

    Artist(std::string artistName, int birthYear, int deathYear);

    std::string GetName() const;

    int GetBirthYear() const;

    int GetDeathYear() const;

    void PrintInfo() const;

private:
    // TODO: Declare private data members - artistName, birthYear, deathYear
    std::string artistName;
    int birthYear;
    int deathYear;
};



#endif //ARTWORKLAB914_ARTIST_H
