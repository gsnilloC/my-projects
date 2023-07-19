//  main.cpp
//  ArtGallerySimplified
//
//created by: [Collins Gichohi]
//date: 04/25/2023

#include <iostream>
#include "util_date_uniqueIDs.h"
#include "unitTests.h"

int main() {
    using namespace NS_ARTGALLERY;
    using namespace NS_UTESTS;

    std::cout << "-------------- ARTWORK TESTS --------------" << std::endl;

    if (test_Artwork()) {
        std::cout << "   test_ArtWork():                Passed" << std::endl;
    } else {
        std::cout << "   test_ArtWork():                Failed" << std::endl;
    }

    if (test_set_getStyle_Artwork()) {
        std::cout << "   test_set_getStyle_Artwork():   Passed" << std::endl;
    } else {
        std::cout << "   test_set_getStyle_Artwork():   Failed" << std::endl;
    }

    if (test_setDimension_Artwork()) {
        std::cout << "   test_setDimension_Artwork():   Passed" << std::endl;
    } else {
        std::cout << "   test_setDimension_Artwork():   Failed" << std::endl;
    }

    std::cout << "-------------- ARTISTS TESTS --------------" << std::endl;

    if (test_Artist()){
        std::cout << "   test_Artist():                 Passed" << std::endl;
    } else {
        std::cout << "   test_Artist():                 Failed" << std::endl;
    }

    if (test_set_getID_Artist()){
        std::cout << "   test_set_getID_Artist():       Passed" << std::endl;
    } else {
        std::cout << "   test_set_getID_Artist():       Failed" << std::endl;
    }

    std::cout << "-------------  CUSTOMERS TESTS ------------" << std::endl;

    if (test_Customer2()){
        std::cout << "   test_Customer2():              Passed" << std::endl;
    } else {
        std::cout << "   test_Customer2():              Failed" << std::endl;
    }

    if (test_set_getName_Customer()){
        std::cout << "   test_set_getName_Customer():   Passed" << std::endl;
    } else {
        std::cout << "   test_set_getName_Customer():   Failed" << std::endl;
    }


    std::cout << "-------------  CURATION TESTS ------------" << std::endl;
    if (test_Curation2()){
        std::cout << "   test_Curation2():              Passed" << std::endl;
    } else {
        std::cout << "   test_Curation2():              Failed" << std::endl;
    }

    if (test_set_getDate_Curation()){
        std::cout << "   test_set_getDate_Curation():   Passed" << std::endl;
    } else {
        std::cout << "   test_set_getDate_Curation():   Failed" << std::endl;
    }

    std::cout << "---------------  SALE TESTS --------------" << std::endl;

    if (test_Sale2()){
        std::cout << "   test_Sale2():                  Passed" << std::endl;
    } else {
        std::cout << "   test_Sale2():                  Failed" << std::endl;
    }

    if (test_set_getCustomerID_Sale()){
        std::cout << "   test_set_getCustomerID_Sale(): Passed" << std::endl;
    } else {
        std::cout << "   test_set_getCustomerID_Sale(): Failed" << std::endl;
    }

    if (test_getArtistID_Gallery()){
        std::cout << "   test_getArtistID_Gallery():    Passed" << std::endl;
    } else {
        std::cout << "   test_getArtistID_Gallery():    Failed" << std::endl;
    }

    if (test_getCustomerID_Gallery()){
        std::cout << "   test_getCustomerID_Gallery():  Passed" << std::endl;
    } else {
        std::cout << "   test_getCustomerID_Gallery():  Failed" << std::endl;
    }

    if(test_getIDsOfArtistsForSale_Gallery()){
        std::cout << "   test_getIDsOfArtistsForSale_Gallery():  Passed" << std::endl;
    } else {
        std::cout << "   test_getIDsOfArtistsForSale_Gallery():  Failed" << std::endl;
    }

    if(test_getIDsOfArtworksForSale_Gallery()){
        std::cout << "   test_getIDsOfArtworksForSale_Gallery():  Passed" << std::endl;
    } else {
        std::cout << "   test_getIDsOfArtworksForSale_Gallery():  Failed" << std::endl;
    }

    if(test_curateArtwork_Gallery()){
        std::cout << "   test_curateArtwork_Gallery():   Passed" << std::endl;
    } else {
        std::cout << "   test_curateArtwork_Gallery():   Failed" << std::endl;
    }

    if (test_sellArtwork_Gallery()){
        std::cout << "   test_sellArtwork_Gallery():     Passed" << std::endl;
    } else {
        std::cout << "   test_sellArtwork_Gallery():     Failed" << std::endl;
    }

    if(test_genArtworksReport_artType_Gallery()){
        std::cout << "   test_genArtworksReport_artType_Gallery():       Passed" << std::endl;
    } else {
        std::cout << "   test_genArtworksReport_artType_Gallery():       Failed" << std::endl;
    }


    return 0;
}
  



  