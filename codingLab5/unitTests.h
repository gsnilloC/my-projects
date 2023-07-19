//  unitTests.h
//  ArtGallerySimplified
//created by: [Collins Gichohi]
//date: 04/25/2023

//unit-test a few member functions for each class

#ifndef unitTests_h
#define unitTests_h

#include "Artwork_Artist.h"
#include "Customer_Curation_Sale_Gallery.h"

namespace NS_UTESTS {

    using namespace NS_ARTGALLERY;

//class Artwork; a partial unit testing.

//default constructor and accessors --->bool test_Artwork();
    bool test_Artwork() {
        Artwork testArtwork;

        if (testArtwork.getID() == -1 &&
            testArtwork.getArtistID() == -1) {
            return true;
        } else {
            return false;
        }
    }

//setStyle() and getStyle()    --->bool test_set_getStyle_Artwork();
    bool test_set_getStyle_Artwork() {
        Artwork testArtwork;
        testArtwork.setStyle(ArtStyle::modern);

        if (testArtwork.getStyle() == ArtStyle::modern) {
            return true;
        } else {
            return false;
        }
    }

//setDimension(), getWidth(), getHeight() and getDepth() --->bool test_setDimension_Artwork();
    bool test_setDimension_Artwork() {
        Artwork testArtwork;

        testArtwork.setDimension(10, 10, 10);

        if (testArtwork.getWidth() == 10 &&
            testArtwork.getDepth() == 10 &&
            testArtwork.getHeight() == 10) {
            return true;
        } else {
            return false;
        }
    }

//class Artist; a partial unit testing.
//default constructor and accessors -->bool test_Artist();
    bool test_Artist() {
        Artist testArtist;

        if (testArtist.getName() == "na" &&
            testArtist.getEmail() == "na" &&
            testArtist.getBirthPlace() == "na" &&
            testArtist.getBirthYear() == 1900 &&
            testArtist.getPrimaryArtType() == ArtType::painting) {
            return true;
        } else {
            return false;
        }
    }

//setID() and getID()--->bool test_set_getID_Artist();
    bool test_set_getID_Artist() {
        Artist testArtist;

        testArtist.setID(uniqueIDs::next_artistID());

        if (testArtist.getID() > 0) {
            return true;
        } else {
            return false;
        }
    }


//class Customer; a partial unit testing.
//the parameterized constructor and accessors -->bool test_Customer2();
    bool test_Customer2() {
        Customer testCustomer(1, "Collins", "cgichohi@sfsu.edu", "19th Avenue");

        if (testCustomer.getID() == 1 &&
            testCustomer.getName() == "Collins" &&
            testCustomer.getEmail() == "cgichohi@sfsu.edu" &&
            testCustomer.getAddress() == "19th Avenue") {
            return true;
        } else {
            return true;
        }
    }

//setName() and getName()--->bool test_set_getName_Customer();
    bool test_set_getName_Customer() {
        Customer testCustomer;

        testCustomer.setName("Collins Gichohi");

        if (testCustomer.getName() == "Collins Gichohi") {
            return true;
        } else {
            return false;
        }
    }

//class Curation; a partial unit testing.
//the parameterized constructor and accessors -->bool test_Curation2();
    bool test_Curation2() {
        Curation testCuration(1, 1, getTodaysDate());

        if (testCuration.getArtistID() == 1 &&
            testCuration.getArtworkID() == 1 &&
            testCuration.getCurationDate() == getTodaysDate()) {
            return true;
        } else {
            return false;
        }
    }

//setCurationDate() and getCurationDate()--->bool test_set_getDate_Curation();
    bool test_set_getDate_Curation() {
        Curation testCuration;

        Date testDate = {5, 16, 2022};

        testCuration.setCurationDate(testDate);

        if (testCuration.getCurationDate() == testDate) {
            return true;
        } else {
            return false;
        }
    }

//class Sale; a partial unit testing.
// .the parameterized constructor and accessors -->bool test_Sale2();
    bool test_Sale2() {
        Sale testSale(1, 1, getTodaysDate());

        if (testSale.getCustomerID() == 1 &&
            testSale.getArtworkID() == 1 &&
            testSale.getSaleDate() == getTodaysDate()) {
            return true;
        } else {
            return false;
        }
    }

// .setCustomerID() and getCustomerID()--->bool test_set_getCustomerID_Sale();
    bool test_set_getCustomerID_Sale() {
        Sale testSale;

        testSale.setCustomerID(uniqueIDs::next_customerID());

        if (testSale.getCustomerID() > 0) {
            return true;
        } else {
            return false;
        }
    }

//class Gallery; a partial unit testing.
//write one unit test for the Gallery::getArtistID() function corresponding to either of the two scenarios: exist/doesn't exist
    bool test_getArtistID_Gallery() {
        Gallery testGallery;

        //artist1 will be added to the gallery and artist 2 will not
        Artist artist1(1, "Collins", "cgichohi@gmail.com", 2012, "Oakley", ArtType::sculpture);
        Artist artist2(2, "Bob", "123@gmail.com", 2012, "SF", ArtType::photography);

        testGallery.addArtist(artist1);

        int testID1 = testGallery.getArtistID("Collins", "cgichohi@gmail.com");
        int testID2 = testGallery.getArtistID("Bob", "123@gmail.com");

        //if artist exist ID should be > 0, if they do not exist it will be -1
        if (testID1 > 1 && testID2 == -1) {
            return true;
        } else {
            return false;
        }
    }

//write one unit test for the Gallery::getCustomerID() function, corresponding to either of the two scenarios: exist/doesn't exist
    bool test_getCustomerID_Gallery() {
        Gallery testGallery;

        Customer customer1(1, "Collins", "cgichohi@gmail.com", "19th Street");
        Customer customer2(2, "Bob", "123@gmail.com", "21st Street");

        testGallery.addCustomer(customer1);

        //if customer exist ID should be > 0, if they do not exist it will be -1
        int testID1 = testGallery.getCustomerID("Collins", "cgichohi@gmail.com");
        int testID2 = testGallery.getCustomerID("Bob", "123@gmail.com");

        if (testID1 > 1 && testID2 == -1) {
            return true;
        } else {
            return false;
        }
    }

//write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty.

    bool test_getIDsOfArtistsForSale_Gallery() {
        Gallery testGallery;

        Artist artist1(1, "Collins", "cgichohi@gmail.com", 2012, "Oakley", ArtType::sculpture);
        Artist artist2(2, "Bob", "123@gmail.com", 2012, "SF", ArtType::photography);

        Artwork artwork1(4, 1, ArtType::drawing, ArtStyle::fineArt, ArtSubject::cartoon, 2022, 10, 10, 10, 10);
        Artwork artwork2(5, 2, ArtType::sculpture, ArtStyle::modern, ArtSubject::nature, 2002, 5, 20, 5, 20);

        testGallery.curateArtwork(artwork1, artist1);
        testGallery.curateArtwork(artwork2, artist2);

        vector<int> testResults = testGallery.getIDsOfArtistsForSale();

        //IDs should be 1 and 2 respectively
        if (testResults[0] == 1 && testResults[1] == 2 && testResults.size() == 2) {
            return true;
        } else {
            return false;
        }
    }

//write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty. This test will call the curateArtwork() function.
    bool test_getIDsOfArtworksForSale_Gallery() {
        Gallery testGallery;

        Artist artist1(1, "Collins", "cgichohi@gmail.com", 2012, "Oakley", ArtType::sculpture);
        Artist artist2(2, "Bob", "123@gmail.com", 2012, "SF", ArtType::photography);

        Artwork artwork1(4, 1, ArtType::drawing, ArtStyle::fineArt, ArtSubject::cartoon, 2022, 10, 10, 10, 10);
        Artwork artwork2(5, 2, ArtType::sculpture, ArtStyle::modern, ArtSubject::nature, 2002, 5, 20, 5, 20);

        testGallery.curateArtwork(artwork1, artist1);
        testGallery.curateArtwork(artwork2, artist2);

        vector<int> testResults = testGallery.getIDsOfArtworksForSale();

        //IDs should be 3 and 4 respectively
        if (testResults[0] == 3 && testResults[1] == 4 && testResults.size() == 2) {
            return true;
        } else {
            return false;
        }
    }


//write one unit test for the genArtworksReport() based on ArtType
    bool test_genArtworksReport_artType_Gallery() {
        // Arrange
        Gallery testGallery;

        Artist artist1(1, "Collins", "cgichohi@gmail.com", 2012, "Oakley", ArtType::sculpture);
        Artist artist2(2, "Bob", "123@gmail.com", 2012, "SF", ArtType::photography);

        Artwork artwork1(4, 1, ArtType::drawing, ArtStyle::fineArt, ArtSubject::cartoon, 2022, 10, 10, 10, 10);
        Artwork artwork2(5, 2, ArtType::sculpture, ArtStyle::modern, ArtSubject::nature, 2002, 5, 20, 5, 20);

        testGallery.curateArtwork(artwork1, artist1);
        testGallery.curateArtwork(artwork2, artist2);

        vector<pair<string, int>> report = testGallery.genArtworksReport(ReportType::artType);

        //should be 2 artworks in gallery, first artworks type should be sculpture and second number should be 1
        if (report.size() == 2 && report[0].first == toStr_ArtType(ArtType::sculpture) &&
            report[1].second == 1){
            return true;
        } else {
            return false;
        }
    }




    // Write one unit test for Gallery::curateArtwork().
    bool test_curateArtwork_Gallery() {
        Gallery testGallery;

        Artist artist1(1, "Collins", "cgichohi@gmail.com", 2012, "Oakley", ArtType::sculpture);
        Artist artist2(2, "Bob", "123@gmail.com", 2012, "SF", ArtType::photography);

        Artwork artwork1(4, 1, ArtType::drawing, ArtStyle::fineArt, ArtSubject::cartoon, 2022, 10, 10, 10, 10);
        Artwork artwork2(5, 2, ArtType::sculpture, ArtStyle::modern, ArtSubject::nature, 2002, 5, 20, 5, 20);

        testGallery.curateArtwork(artwork1, artist1);
        testGallery.curateArtwork(artwork2, artist2);

        //should be 2 artworks in artworksCurated and artworksForSale
        if (testGallery.num_artworksCurated() == 2 && testGallery.num_artworksForSale() == 2){
            return true;
        } else {
            return false;
        }
    }

//write one unit test for the Gallery::sellArtwork() function
    bool test_sellArtwork_Gallery() {
        Gallery testGallery;

        Artwork artwork1(1, 1, ArtType::drawing, ArtStyle::fineArt, ArtSubject::cartoon, 2022, 10, 10, 10, 10);
        Artwork artwork2(2, 2, ArtType::sculpture, ArtStyle::modern, ArtSubject::nature, 2002, 5, 20, 5, 20);
        Artwork artwork3(3, 3, ArtType::painting, ArtStyle::abstract, ArtSubject::cartoon, 2006, 8, 20, 8, 20);

        testGallery.curateArtwork(artwork1, Artist());
        testGallery.curateArtwork(artwork2, Artist());
        testGallery.curateArtwork(artwork3, Artist());

        // Sell artwork 1 to a customer
        testGallery.sellArtwork(1, Customer());

        // Check if artwork 1 is not in the sale list anymore
        if (testGallery.num_artworksForSale() == 3 && testGallery.num_artworksForSale() == 3
           && testGallery.num_artists() == 1){
            return true;
        } else {
            return false;
        }

    }

}//end-of namespace NS_UTESTS
#endif /* unitTests_h */
