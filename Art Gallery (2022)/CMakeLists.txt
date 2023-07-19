cmake_minimum_required(VERSION 3.24)
project(codingLab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(codingLab5
        Customer_Curation_Sale_Gallery.cpp
        Customer_Curation_Sale_Gallery.h
        main.cpp
        unitTests.h
        Artwork_Artist.cpp
        Artwork_Artist.h util_date_uniqueIDs.cpp util_date_uniqueIDs.h)