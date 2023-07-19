
#ifndef ARTWORKLAB914_ARTWORK_H
#define ARTWORKLAB914_ARTWORK_H

#include "Artist.h"

class Artwork{
   public:
      Artwork();

      Artwork(std::string title, int yearCreated, Artist artist);

      std::string GetTitle();

      int GetYearCreated();

      void PrintInfo();

   private:
      // TODO: Declare private data members - title, yearCreated
      std::string title;
      int yearCreated;
      // TODO: Declare private data member artist of type Artist
      Artist artist;
};


#endif //ARTWORKLAB914_ARTWORK_H
