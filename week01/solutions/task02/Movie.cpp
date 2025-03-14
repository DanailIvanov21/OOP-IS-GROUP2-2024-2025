#include "Movie.h"
#define _CRT_SECURE_NO_WARNINGS

Movie createMovie(const char* title, unsigned int length, Genre genre, double rating)
{
	char newTitle[MAX] = "NO NAME"; 
	
	if (title == nullptr || strlen(title) == 0)
	{
		strcpy_s(newTitle, "NO NAME");		
	}
	else
	{
		strcpy_s(newTitle,title);
		newTitle[sizeof(title) - 1] = '\0'; 
	}
	
	unsigned newLength = length;
	Genre newGenre = genre;
	double newRating = rating;
	return Movie{*newTitle, newLength, (char)newGenre, newRating};	
}

void printMovie(const Movie& movie)
{
	std::cout << "Title: " << movie.title << ", ";
	std::cout << "Length: " << movie.length << ", ";
	std::cout << "Genre: " << (int)movie.genre << ", ";
	std::cout << "Rating: " << movie.rating << std::endl;
}

const Movie* getTopRatedMovie(const Movie* movies, size_t size)
{
	if (size == 0) {
		return nullptr;
	}
	
	double topRating = movies[0].rating;
	const Movie* toRatedMovie = &movies[0];

	for (int i = 1; i < size; i++ ) 
	{
		if (movies[i].rating > topRating) 
		{
			topRating = movies[i].rating;
			toRatedMovie = &movies[i];
		}
	}

	return toRatedMovie;
}
