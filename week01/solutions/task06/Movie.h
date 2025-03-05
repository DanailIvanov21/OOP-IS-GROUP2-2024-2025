#pragma once
#include <iostream>
constexpr unsigned LENGHT = 64;

enum Genre {
    ACTION,
    COMEDY, 
    DRAMA,
    HORROR,
    SCI_FI,
    ANIMATION
};

enum AgeRating {
    G,
    PG,
    PG_13, 
    R,
    NC_17
};

struct Movie {
    char title[LENGHT];
    Genre genre;
    AgeRating ageRating;
    double imdbRating;
    int duration;
};

void initMovie(Movie& movie);
void addMovies(Movie movies[], int size);
void printMovieGenre(const Movie& movie);
void printMovieAgeRating(const Movie& movie);
void printMovie(const Movie& movie);
void printMovies(const Movie movies[], int size);
void sortMoviesByRating(Movie movies[], int size);
int countFamilyAnimations(const Movie movies[], int size);
void filterHorrorStrictAge(const Movie movies[], int size);
void compareMovies(const Movie& lhs, const Movie& rhs);
double averageSciFiPG13Duration(const Movie movies[], int size);
