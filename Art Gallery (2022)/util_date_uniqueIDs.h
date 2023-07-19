//  util_date_uniqueIDs.h
//  Project: ArtGallerySimplified
//created by: [Collins Gichohi]
//date: 04/25/2023

//  Declares helper (or utility) datatypes and functions to manage a simplified art gallery
//       in the namespace NS_ARTGALLERY.

#ifndef date_uniqueIDs_h
#define date_uniqueIDs_h

#include <iostream>
#include <chrono> //system_clock::now()
#include <ctime>  //localtime()
#include <string>

namespace NS_ARTGALLERY {
    using namespace std;

    struct Date {
        int day;
        int month;
        int year;
    };

//compares two Date objects.
//returns true if they have the same value for each of the three data members
    bool operator==(Date lhs, Date rhs);

//returns today's date as a Date object
    Date getTodaysDate();

    class uniqueIDs {
    public:
        static int next_artistID();  //return a new & unique artist ID
        static int next_customerID();//return a new & unique customer ID
        static int next_artworkID();//return a new & unique artwork ID
        static int next_galleryID(); //return a new & unique gallery ID
    private:
        static int artistID;
        static int customerID;
        static int artworkID;
        static int galleryID;
    };

//types of artworks
    enum class ArtType {
        painting, photography, drawing, sculpture, other
    };

//returns a string for each ArtType value. e.g., ArtType::painting-->"ArtType::painting"
    string toStr_ArtType(ArtType);

//list of art styles
    enum class ArtStyle {
        fineArt, abstract, modern, popArt, other
    };

//returns a string for each ArtStyle value. e.g., ArtStyle::fineArt-->"ArtStyle::fineArt"
    string toStr_ArtStyle(ArtStyle);

//list of artwork subjects
    enum class ArtSubject {
        nature, portrait, animal, cartoon, other
    };

//returns a string for each ArtSubject value. e.g., ArtSubject::nature-->"ArtSubject::naturenature"
    string toStr_ArtSubject(ArtSubject);

//list of report types, used by the ArtGallery::genArtworksReport( ReportType reportType);
    enum class ReportType {
        artType, artStyle, artSubject
    };

} //end-of namespace NS_ARTGALLERY

#endif /* date_uniqueIDs_h */

