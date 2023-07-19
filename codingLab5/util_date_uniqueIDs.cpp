//
//  util_date_uniqueIDs.cpp
//  ArtGallerySimplified
//
//


#include "util_date_uniqueIDs.h"

namespace NS_ARTGALLERY{

//returns today's date as a Date object
//references:  https://en.cppreference.com/w/cpp/chrono/time_point
//             https://en.cppreference.com/w/cpp/chrono/c/localtime
Date getTodaysDate()
{
    //retrieve the current time point
    const std::chrono::time_point<std::chrono::system_clock> now =
           std::chrono::system_clock::now();
    
    //convert now to std::time_t in <ctime>, an arithmetic type capable of representing times.
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    
    //convert t_c to calendar date and time
    //std::tm* calendarTime = localtime( &t_c);  //depreciated 
    struct tm buf;
    std::tm* calendarTime = localtime_r( &t_c, &buf);  //
    
    //return today's date in the order of {day, month, year}
    return {calendarTime->tm_mday, calendarTime->tm_mon + 1, calendarTime->tm_year + 1900};
}

//compares two Date objects.
//returns true if they have the same value for each of the three data members
bool operator==(Date lhs, Date rhs)
{
    return (lhs.day==rhs.day && lhs.month==rhs.month && lhs.year==rhs.year);
}

//intialize the IDs to 0
int uniqueIDs::artistID = 0;
int uniqueIDs::customerID = 0;
int uniqueIDs::artworkID = 0;
int uniqueIDs::galleryID = 0;

//returns the next and unique artist ID
int uniqueIDs::next_artistID()
{
    artistID++;
    return artistID;
}

//returns the next and unique customer ID
int uniqueIDs::next_customerID()
{
    customerID++;
    return customerID;
}

//returns the next and unique artwork ID
int uniqueIDs::next_artworkID()
{
    artworkID++;
    return artworkID;
}

//returns the next and unique gallery ID
int uniqueIDs::next_galleryID()
{
    galleryID++;
    return galleryID;
}


//types of artworks
//enum class ArtType {painting, photography, drawing, sculpture, other};

//returns a string for each ArtType value. e.g., ArtType::painting-->"ArtType::painting"
string toStr_ArtType( ArtType type )
{
    switch (type){
        case ArtType::painting:
            return "ArtType::painting";
        case ArtType::photography:
            return "ArtType::photography";
        case ArtType::drawing:
            return "ArtType::drawing";
        case ArtType::sculpture:
            return "ArtType::sculpture";
        case ArtType::other:
            return "ArtType::other";
        default:  //this will not happen. just to make this compiler not generate a warning.
            return "ArtType::other";  
    }
}

//list of art styles
//enum class ArtStyle {fineArt, abstract, modern, popArt, other};
//returns a string for each ArtStyle value. e.g., ArtStyle::fineArt-->"fine art"
string toStr_ArtStyle( ArtStyle style)
{
    switch (style){
        case ArtStyle::fineArt:
            return "ArtStyle::fineArt";
        case ArtStyle::abstract:
            return "ArtStyle::abstract";
        case ArtStyle::modern:
            return "ArtStyle::modern";
        case ArtStyle::popArt:
            return "ArtStyle::popArt";
        case ArtStyle::other:
            return "ArtStyle::other";
        default:  //this will not happen. just to make this compiler not generate a warning.
            return "ArtStyle::other";        
             
    }
}

//list of artwork subjects
//enum class ArtSubject {nature, portrait, animal, cartoon, other};

//returns a string for each ArtSubject value. e.g., ArtSubject::nature-->"nature"
string toStr_ArtSubject( ArtSubject subject)
{
    switch (subject){
        case ArtSubject::nature:
            return "ArtSubject::nature";
        case ArtSubject::portrait:
            return "ArtSubject::portrait";
        case ArtSubject::animal:
            return "ArtSubject::animal";
        case ArtSubject::cartoon:
            return "ArtSubject::cartoon";
        case ArtSubject::other:
            return "ArtSubject::other";
        default:  //this will not happen. just to make this compiler not generate a warning.
            return "ArtSubject::other";
    }
}

}//end-of NS_ARTGALLERY

