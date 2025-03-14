#include <iostream>
#include "Movie.h"

int main()
{
    Movie movies[3] = {
        createMovie("Terminator", 120, Genre::ACTION, 8.90),
        createMovie("Titanic", 240, Genre::ROMANTIC, 9.90),
        createMovie("Fred", 87, Genre::COMEDY, 3.12)
    };
    
    for (size_t i = 0; i < 3; i++)
    {
        printMovie(movies[i]);
    }
   
    const Movie* topRatedMovie = getTopRatedMovie(movies, 3);

    if (topRatedMovie != nullptr)
    {
        std::cout << "Top rated movie is: \n";
        printMovie(*topRatedMovie);
    }

    return 0;
}
