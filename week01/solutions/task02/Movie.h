#pragma once


#include <iostream>
#include <cstring>

static const int MAX = 32;

enum class Genre 
{
    COMEDY,
    ACTION,
    HORROR,
    ROMANTIC
};

const static char GENRE_STRINGS[][20] = { "Comedy", "Action", "Horror", "Romantic" };

struct Movie
{
    char title[MAX];  
    unsigned int length;
    Genre genre;
    double rating;
};


Movie createMovie(const char* title, unsigned int length, Genre genre, double rating);
void printMovie(const Movie& movie);
const Movie* getTopRatedMovie(const Movie* movies, size_t size);
