#include "Artwork.h"
#include <iostream>


// TODO: Define default constructor

// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)

// TODO: Define get functions: GetTitle(), GetYearCreated()

// TODO: Define PrintInfo() function
//       Call the PrintInfo() function in the Artist class to print an artist's information
Artwork::Artwork() {
    title = "unknown";
    yearCreated = -1;
    Artist();
}

Artwork::Artwork(std::string title, int yearCreated, Artist artist)
        : title(title), yearCreated(yearCreated), artist(artist)
{
    // Constructor body (if any)
}

std::string Artwork::GetTitle() {
    return title;
}

int Artwork::GetYearCreated() {
    return yearCreated;
}

void Artwork::PrintInfo() {
    artist.PrintInfo();
    std::cout << "Title, " << title << std::endl;
    std::cout << "Year Created: " << yearCreated << std::endl;
}