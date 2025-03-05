#include "Movie.h"

int main() {
    const int SIZE = 5;
    Movie movies[SIZE];

    addMovies(movies, SIZE);
    sortMoviesByRating(movies, SIZE);
    printMovies(movies, SIZE);

    std::cout << "Family animations: " << countFamilyAnimations(movies, SIZE) << std::endl;
    std::cout << "Horror movies with NC-17 rating:\n";
    filterHorrorStrictAge(movies, SIZE);

    std::cout << "Comparing first two movies:\n";
    compareMovies(movies[0], movies[1]);

    std::cout << "Average duration of Sci-Fi PG-13 movies: " << averageSciFiPG13Duration(movies, SIZE) << " minutes.\n";

}


