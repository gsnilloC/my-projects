//created by: [Collins Gichohi]
//date: 04/25/2023

#include "Customer_Curation_Sale_Gallery.h"

namespace NS_ARTGALLERY {
    //default constructor: ID(-1),name("na"),email("na"),address("na")
    Customer::Customer() :
            ID(-1),
            name("na"),
            email("na"),
            address("na") {}

    //parameterized constructor: ID(theID),name(theName),email(theEmail), address("theAddr")
    Customer::Customer(int theID, string theName, string theEmail, const string theAddr) {
        ID = theID;
        name = theName;
        email = theEmail;
        address = theAddr;
    }

    //accessors
    int Customer::getID() const { return ID; }

    string Customer::getName() const { return name; }

    string Customer::getEmail() const { return email; }

    string Customer::getAddress() const { return address; }

    //mutators
    void Customer::setID(int theID) { ID = theID; }

    void Customer::setName(string theName) { name = theName; }

    void Customer::setEmail(string theEmail) { email = theEmail; }

    void Customer::setAddress(string theAddress) { address = theAddress; }

    //default constructor: artworkID(-1),artistID(-1),curationDate({1,1,2022})
    Curation::Curation() :
            artworkID(-1),
            artistID(-1),
            curationDate({1, 1, 2022}) {}

    //parameterized constructor: artworkID(theArtworkID),artistID(theArtistID),curationDate(theDate)
    Curation::Curation(int theArtworkID, int theArtistID, Date theDate) {
        artworkID = theArtworkID;
        artistID = theArtistID;
        curationDate = theDate;
    }

    //accessors
    int Curation::getArtworkID() const { return artworkID; }

    int Curation::getArtistID() const { return artistID; }

    Date Curation::getCurationDate() const { return curationDate; }

    //mutators
    void Curation::setArtistID(int theID) { artistID = theID; }

    void Curation::setCurationDate(Date theDate) { curationDate = theDate; }

    void Curation::setArtworkID(int theID) { artworkID = theID; }

    //default constructor: customerID(-1), artworkID(-1),saleDate({1,1,2022})
    Sale::Sale() :
            customerID(-1),
            artworkID(-1),
            saleDate({1, 1, 2022}) {}

    //parameterized constructor: customerID(theCustomerID),artworkID(theArtworkID),saleDate(theDate)
    Sale::Sale(int theCustomerID, int theArtworkID, Date theDate) {
        customerID = theCustomerID;
        artworkID = theArtworkID;
        saleDate = theDate;
    }

    //accessors
    int Sale::getCustomerID() const { return customerID; }

    int Sale::getArtworkID() const { return artworkID; }

    Date Sale::getSaleDate() const { return saleDate; }

    //mutators
    void Sale::setCustomerID(int theID) { customerID = theID; }

    void Sale::setArtworkID(int theID) { artworkID = theID; }

    void Sale::setSaleDate(Date theDate) { saleDate = theDate; }

    //default constructor: ID(-1),name("na"),address("na"),webURL("na")
    Gallery::Gallery() :
            ID(-1),
            name("na"),
            address("na"),
            webURL("na") {}

    //accessors
    int Gallery::getID() const { return ID; }

    string Gallery::getName() const { return name; }

    string Gallery::getAddress() const { return address; }

    string Gallery::getWebURL() const { return webURL; }

    //mutators
    void Gallery::setID(int theID) { ID = theID; }

    void Gallery::setName(string theName) { name = theName; }

    void Gallery::setAddress(string theAddr) { address = theAddr; }

    void Gallery::setWebURL(string theURL) { webURL = theURL; }

    //return number of elements in given list
    unsigned long Gallery::num_artists() const { return artistsList.size(); }

    unsigned long Gallery::num_artworksCurated() const { return artworksCurated.size(); }

    unsigned long Gallery::num_artworksForSale() const { return artworksForSale.size(); }

    unsigned long Gallery::num_customers() const { return customersList.size(); }

    unsigned long Gallery::num_curations() const { return curationsRecords.size(); }

    unsigned long Gallery::num_sales() const { return salesRecords.size(); }

    //get artist ID by checking but ensure that artist string and name are in list, if not return -1
    vector<Artist> artistsList;

    int Gallery::getArtistID(string name, string email) const {
        for (size_t i = 0; i < artistsList.size(); i++) {
            if (artistsList[i].getName() == name && artistsList[i].getEmail() == email) {
                return artistsList[i].getID();
            }
        }
        return -1; // artist not found
    }


    //get customer ID by checking but ensure that artist string and name are in list, if not return -1
    int Gallery::getCustomerID(string name, string email) const {
        for (size_t i = 0; i < customersList.size(); i++) {
            if (customersList[i].getName() == name && customersList[i].getEmail() == email) {
                return customersList[i].getID();
            }
        }
        return -1; // customer not found
    }

    int Gallery::addArtist(Artist artist) {
        string name = artist.getName();
        string email = artist.getEmail();

        for (size_t i = 0; i < artistsList.size(); ++i) {
            if (artistsList[i].getName() == name && artistsList[i].getEmail() == email) {
                return -1; // artist already in list
            }
        }

        //if artist is new add to artistList then generate and return unique ID
        artist.setID(uniqueIDs::next_artistID());
        artistsList.push_back(artist);
        return artist.getID();
    }

    int Gallery::addCustomer(Customer customer) {
        string name = customer.getName();
        string email = customer.getEmail();

        for (size_t i = 0; i < customersList.size(); ++i) {
            if (customersList[i].getName() == name && customersList[i].getEmail() == email) {
                return -1; // customer already in list
            }
        }

        //if customer is new add to customersList then generate and return unique ID
        customer.setID(uniqueIDs::next_customerID());
        customersList.push_back(customer);
        return customer.getID();
    }


    vector<Artwork> artworksForSale;

    //return IDs of artworks that are for sale
    vector<int> Gallery::getIDsOfArtworksForSale() const {
        vector<int> result;

        for (size_t i = 0; i < artworksForSale.size(); ++i) {
            result.push_back(artworksForSale[i].getID());
        }
        return result;
    }

    //return unique IDs of artists with artwork on sale
    //make sure that IDs are not duplicated
    vector<int> Gallery::getIDsOfArtistsForSale() const {
        vector<int> result;
        set<int> listIDs;

        for (size_t i = 0; i < artworksForSale.size(); ++i) {
            int artistsID = artworksForSale[i].getID();
            if (listIDs.find(artistsID) == listIDs.end()) {
                listIDs.insert(artistsID);
                result.push_back(artistsID);
            }
        }
        return result;
    }

    vector<pair<string, int>> Gallery::genArtworksReport(ReportType reportType) {
        vector<pair<string, int>> result;
        unordered_map<string, int> summary;

        if (reportType == ReportType::artType) {
            for (size_t i = 0; i < artworksCurated.size(); ++i) {
                ArtType artType = artworksCurated[i].getType();
                string artTypeString = toStr_ArtType(artType);

                //if not in summary add it with the value of 1
                if (summary.find(artTypeString) == summary.end()) {
                    summary[artTypeString] = 1;
                } else {
                    //if the subject is in the summary, increment its count by 1
                    summary[artTypeString]++;
                }
            }
        } else if (reportType == ReportType::artStyle) {
            // Set default values for all art styles
            summary[toStr_ArtStyle(ArtStyle::abstract)] = 0;
            summary[toStr_ArtStyle(ArtStyle::fineArt)] = 0;
            summary[toStr_ArtStyle(ArtStyle::modern)] = 0;
            summary[toStr_ArtStyle(ArtStyle::popArt)] = 0;
            summary[toStr_ArtStyle(ArtStyle::other)] = 0;

            for (size_t i = 0; i < artworksCurated.size(); ++i) {
                ArtStyle artStyle = artworksCurated[i].getStyle();
                string artStyleString = toStr_ArtStyle(artStyle);
                if (summary.find(artStyleString) == summary.end()) {
                    summary[artStyleString] = 1;
                } else {
                    summary[artStyleString]++;
                }

            }
        } else if (reportType == ReportType::artSubject) {
            // Set default values for all art subjects
            summary[toStr_ArtSubject(ArtSubject::nature)] = 0;
            summary[toStr_ArtSubject(ArtSubject::portrait)] = 0;
            summary[toStr_ArtSubject(ArtSubject::cartoon)] = 0;
            summary[toStr_ArtSubject(ArtSubject::animal)] = 0;
            summary[toStr_ArtSubject(ArtSubject::other)] = 0;

            for (size_t i = 0; i < artworksCurated.size(); ++i) {
                ArtSubject artSubject = artworksCurated[i].getSubject();
                string artSubjectString = toStr_ArtSubject(artSubject);

                if (summary.find(artSubjectString) == summary.end()) {
                    summary[artSubjectString] = 1;
                } else {
                    summary[artSubjectString]++;
                }
            }
        }

        //convert the summary unordered_map to a vector<pair<string, int>> and return it
        for (const auto &entry: summary) {
            result.push_back(make_pair(entry.first, entry.second));
        }

        return result;
    }


    void Gallery::curateArtwork(Artwork newItem, Artist artist) {
        string name = artist.getName();
        string email = artist.getEmail();

        //if artist is already on the list retrieve their ID
        for (size_t i = 0; i < artistsList.size(); ++i) {
            if (artistsList[i].getName() == name && artistsList[i].getEmail() == email) {
                artist.setID(artistsList[i].getID());
                break;
            }
        }

        //if artists is not on list, generate unique ID and artist to list
        if (artist.getID() == -1) {
            artist.setID(uniqueIDs::next_artistID());
            artistsList.push_back(artist);
        }

        //assign new ID to new item
        newItem.setID(uniqueIDs::next_artworkID());
        newItem.setArtistID(artist.getID());

        //add new artwork to artworksCurated and artworksForSale
        artworksCurated.push_back(newItem);
        artworksForSale.push_back(newItem);

        //create new curation and give it the artworks information
        Curation newCuration;
        newCuration.setArtistID(artist.getID());
        newCuration.setArtworkID(newItem.getID());
        newCuration.setCurationDate(getTodaysDate());

        addCuration(newCuration);

    }

    void Gallery::sellArtwork(int artworkID, Customer customer) {
        string name = customer.getName();
        string email = customer.getEmail();

        // Check if customer already exists in the customersList vector
        bool customerExists = false;
        for (size_t i = 0; i < customersList.size(); ++i) {
            if (customersList[i].getName() == name && customersList[i].getEmail() == email) {
                customer.setID(customersList[i].getID());
                customerExists = true;
                break;
            }
        }

        // If customer is new, assign a unique ID and add to the customersList vector
        if (!customerExists) {
            customer.setID(uniqueIDs::next_customerID());
            customersList.push_back(customer);
        }

        // Check if artwork is still for sale
        bool artworkForSale = false;
        for (size_t i = 0; i < artworksForSale.size(); ++i) {
            if (artworksForSale[i].getID() == artworkID) {
                artworkForSale = true;

                // Remove artwork from artworksForSale vector
                artworksForSale.erase(artworksForSale.begin() + i);

                // Create a new Sale object and add to salesRecords vector
                Sale newSale;
                newSale.setArtworkID(artworkID);
                newSale.setCustomerID(customer.getID());
                newSale.setSaleDate(getTodaysDate());
                salesRecords.push_back(newSale);

                // Remove artwork from artworksCurated vector
                for (size_t j = 0; j < artworksCurated.size(); ++j) {
                    if (artworksCurated[j].getID() == artworkID) {
                        artworksCurated.erase(artworksCurated.begin() + j);
                        break;
                    }
                }

                break;
            }
        }

        // If artwork is not for sale, do nothing
        if (!artworkForSale) {
            return;
        }

        // Update the customer object in the customersList vector
        for (size_t i = 0; i < customersList.size(); ++i) {
            if (customersList[i].getID() == customer.getID()) {
                customersList[i] = customer;
                break;
            }
        }
    }


    void Gallery::addCuration(Curation curation) {
        //add new curation to curationRecords
        curationsRecords.push_back(curation);
    }

    void Gallery::addSale(Sale sale) {
        //add new sale to saleRecords
        salesRecords.push_back(sale);
    }

}//end of NS_ARTGALLERY