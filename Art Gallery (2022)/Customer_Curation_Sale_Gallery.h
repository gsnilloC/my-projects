//
//  Customer_Curation_Sale_Gallery.h
//  ArtGallerySimplified
//
//  Declare the following classes in the namespace NS_ARTGALLERY:
//  1. class Customer; 2. class Curation; 3. class Sale; 4. class ArtGallery
//
//

#ifndef Customer_Curation_Sale_Gallery_h
#define Customer_Curation_Sale_Gallery_h

#include "util_date_uniqueIDs.h"
#include "Artwork_Artist.h"
#include <vector>
#include <algorithm>
#include <set>

namespace NS_ARTGALLERY{
//using namespace std;
  /*
   Type 3. Customer
     Relevant data properties:
      ID; //customer’s unique ID
      name; //customer’s full name: first last
      email; //customer’s email
      address; //customer’s address
    
    Relevant data operations:
      set the initial value of a customer's properties  ----->constructors
      retrieve an individual property    -----> accessors
      revise an individual property ---->mutators
   */
class Customer{
public:
    //default constructor: ID(-1),name("na"),email("na"),address("na")
    Customer();
    //parameterized constructor: ID(theID),name(theName),email(theEmail), address("theAddr")
    Customer(int theID, string theName, string theEmail, const string theAddr);
    
    //accessors
    //returns a customer's ID
    int getID() const;
    //returns a customer's name
    string getName() const;
    //returns a customer's email
    string getEmail() const;
    //returns a customer's address
    string getAddress() const;
  
    //mutators
    //change a customer's ID to theID
    void setID( int theID);
    //change a customer's name to theName
    void setName( string theName);
    //change a customer's email to theEmail
    void setEmail(string theEmail);
    //change a customer's address to theAddress
    void setAddress( string theAddress);
private:
    int ID; //a generated, unique ID
    string name; //customer’s full name: first last
    string email; //customer’s email
    string address; //customer’s address
};

/*
 Type 4: Curation
 Relevant data properties:
 artworkID; //ID of the artwork being curated
 artistID; //ID of the artist who created this artwork
 curationDate; //date of curation: {day, month, year}
  
  Relevant data operations:
 set the initial value of an art-curation's properties  ----->constructors
 retrieve an individual property    -----> accessors
 revise an individual property except its unique ID---->mutators
 */
class Curation{
public:
    //default constructor: artworkID(-1),artistID(-1),curationDate({1,1,2022})
    Curation();
    //parameterized constructor: artworkID(theArtworkID),artistID(theArtistID),curationDate(theDate)
    Curation(int theArtworkID, int theArtistID, Date theDate);
    
    //accessors
    //return a curation's artworkID
    int getArtworkID() const;
    //return a curation's artistID
    int getArtistID() const;
    //return a curation's date
    Date getCurationDate() const;
    
    //mutators
    //changes a curation's artworkID to theID
    void setArtworkID( int theID);
    //changes a curation's artistID to theID
    void setArtistID( int theID);
    //changes a curation's date to theDate
    void setCurationDate(Date theDate);
private:
    int artworkID; //ID of the artwork being curated
    int artistID; //ID of the artist who created this artwork
    Date curationDate; //date of curation: {day, month, year}    
};

/*
 Type 5. Sale   //a type of activity —>class Sale;
  Relevant data properties:
 customerID
 artworkID
 saleDate; //date of sale: {day, month, year}
  
  Relevant data operations:
 set the initial value of an art-purchase/transaction's properties  ----->constructors
 retrieve an individual property    -----> accessors
 revise an individual property except its unique ID---->mutators
 */
class Sale{
public:
    //default constructor: customerID(-1), artworkID(-1),saleDate({1,1,2022})
    Sale();
    //parameterized constructor: customerID(theCustomerID),artworkID(theArtworkID),saleDate(theDate)
    Sale(int theCustomerID, int theArtworkID,  Date theDate);
    
    //accessors
    //return a sale's customerID
    int getCustomerID() const;
    
    //return a sale's artworkID
    int getArtworkID() const;

    //return a sale's date
    Date getSaleDate() const;
    
    //mutators
    //changes a sale's customerID to theID
    void setCustomerID( int theID);
    
    //changes a sale's artworkID to theID
    void setArtworkID( int theID);

    //changes a sale's date to theDate
    void setSaleDate(Date theDate);
private:
    int customerID; //ID of the customer who made this purchase
    int artworkID; //ID of the artwork being purchased
    Date saleDate; //date of sale: {day, month, year}
};

/*
 Type 6. Gallery
  Relevant data properties:
 ID; //the unique ID of an art gallery
 name; //name of the gallery
 address;
 webURL; //website of the gallery
 artistList; //the list of artists who have at least one artwork curated by the gallery
 customerList; //the list of customers who have ever purchased an artwork from the gallery
 artworkListCurated; //the list of artworks that have ever been curated by the gallery. We are going to assume every artwork is unique. In other words, we don't have multiple copies of the same artwork.
 artworkListForSale; //the list of artworks that are available for purchase. note the difference between this list and the above.
 curationRecords; //collection of art curation records
 salesRecords; //collection of art sales records
 */
class Gallery{
public:
    //default constructor: ID(-1),name("na"),address("na"),webURL("na")
    Gallery();
    
    //accessors
    
    //returns the unique ID of a gallery
    int getID() const;
    //returns the name of a gallery
    string getName() const;
    //returns the address of a gallery
    string getAddress() const;
    //returns the webURL of a gallery
    string getWebURL() const;
    
    unsigned long num_artists() const; //returns the size of artistsList
    unsigned long num_artworksCurated() const; //returns the size of artworksCurated;
    unsigned long num_artworksForSale() const; //returns the size of artworksForSale;
    unsigned long num_customers() const; //returns the size of customersList
    unsigned long num_curations() const; //returns the size of curationRecords
    unsigned long num_sales() const; //returns the size of salesRecords
    
    //retrieves an artist's ID from the artistList using the provided name and email.
    //We assume that name & email can uniquely identify an artist.
    //returns the ID if found; -1 if not. The latter means that this is a new artist.
    int getArtistID(string name, string email) const;
    
    //retrieves a customer's ID from the customerList using the provided name and email.
    //We assume that name & email can uniquely identify a customer.
    //returns the customer's ID if found; -1 if not. The latter means that this is a new customer.
    int getCustomerID(string name, string email) const;
    
    //returns the IDs of for-sale artworks
    vector<int> getIDsOfArtworksForSale() const;
    //returns the unique IDs of the artists who have artworks for sale
    // Note: make sure that you deduplicate the IDs as one artist may have multiple artworks for sale
    vector<int> getIDsOfArtistsForSale() const;
    
    //Summarize a gallery's curated artworks (i.e., artworkListCurated) by  art type, style, and subject.
    //ReportType is an enum class declared in the util_date_uniqueIDs.h. It consists of {artType, artStyle, artSubject}.
    //For example, if reportType is ReportType::artType, this function will return a vector of the following pairs: ("ArtType::painting", #), ("ArtType::photography", #), ("ArtType::drawing", #), ("ArtType::sculpture", #), ("ArtType::other", #).
    //You can call the string toStr_ArtType( ArtType ) function to convert an ArtType value to a string.
    //Your algorithm is going to replace the # with the actual number of artworks of the corresponding artType.
    vector<pair<string, int> > genArtworksReport( ReportType reportType);
    
    //mutators
    //changes the unique ID of a gallery to theID
    void setID(int theID);
    //changes the name of a gallery to theName
    void setName(string theName);
    //changes the address of a gallery to theAddr
    void setAddress(string theAddr);
    //changes the webURL of a gallery to theURL
    void setWebURL(string theURL);
    
    //add an artist to the artistList. Make sure that (1) this artist is not already on artistList by checking the name & email combination; and (2) this artist has a valid ID by generating a unique ID. Do nothing if the artist is already on the list.
    //returns artistID
    int addArtist(Artist artist);
    
    //adds a customer to the customerList. Make sure that (1) this customer is not already on customerList by checking their name & email combination; and (2) this customer has a valid ID by generating a unique ID. Do nothing if the artist is already on the list.Do nothing if this customer is already on the list.
    //returns customerID.
    int addCustomer(Customer customer);
    

    //artwork curation: curate a new piece of artwork for the gallery. newItem.ID, newItem.artistID, and artist.ID are all set to -1
    // (not available) initially. As a result, you’ll need to assign this newItem a unique ID. Check if the artist is already on the
    // artistList using their name and email. If new, assign this artist a unique ID and add them to the artistList. If not new, retrieve
    // their ID from the artistList. You will also need to update the artworkListCurated and the artworkListForSale. Finally, you will
    // need to update the curationRecords to include this new curation.
    void curateArtwork(Artwork newItem, Artist artist);
    
    //artwork sale: sell a for-sale artwork to a customer. customer.ID is set to -1 initially. So you will need to find out if this
    // customer is new using their name and email address. If new, assign this customer a unique ID and add them to the customerList.
    // If not, retrieve their ID from customerList. You will also need to check if the specified artworkID is still for sale. If yes,
    // update the artworkListForSale by removing this artwork that was just sold, and update the salesRecords to include this new sale.
    // If this artwork is not for sale, do nothing.
    void sellArtwork(int artworkID, Customer customer);
    
    //you can include more functions should you like.  They will not be tested though.
private:
    int ID; //a generated, unique ID of an art gallery
    string name; //name of the gallery
    string address;
    string webURL; //website of the gallery
    vector<Artist> artistsList; //the list of artists who have at least one artwork curated by the gallery
    vector<Customer> customersList; //the list of customers who have ever purchased an artwork from the gallery
    vector<Artwork> artworksCurated; //the list of artworks that have ever been curated by the gallery. We are going to assume every artwork is unique. In other words, we don't have multiple copies of the same artwork.
    vector<Artwork> artworksForSale; //the list of artworks that are available for purchase. note the difference between this list and the above.
    vector<Curation> curationsRecords; //collection of art curation records
    vector<Sale> salesRecords; //collection of art sales records

    //add a new curation record to curationRecords.
    void addCuration(Curation curation);
    
    //add a new sale record to salesRecords
    void addSale(Sale sale);
};

}//end-of namespace NS_ARTGALLERY

#endif /* Customer_Curation_Sale_Gallery_h */
