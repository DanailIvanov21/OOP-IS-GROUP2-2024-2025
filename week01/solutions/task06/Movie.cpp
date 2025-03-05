#include "Movie.h"
#include <cstring>

void initMovie(Movie& movie)
{
	int genre, age;
	std::cout << "Enter title, genre (0-ACTION, 1-COMEDY, 2-DRAMA, 3-HORROR, 4-SCI_FI, 5-ANIMATION), age rating (0-G, 1-PG, 2-PG_13, 3-R, 4-NC_17), IMDb rating, duration: ";
	std::cin >> movie.title >> genre >> age >> movie.imdbRating >> movie.duration;
	movie.genre = Genre(genre);
	movie.ageRating = AgeRating(age);
}

void addMovies(Movie movies[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		initMovie(movies[i]);
	}
}

void printMovieAgeRating(const Movie& movie)
{	
	switch (movie.ageRating)
	{
	case G: std::cout << "G" << std::endl;
		break;
	case PG: std::cout << "PG" << std::endl;
		break;
	case PG_13: std::cout << "PG_13" << std::endl;
		break;
	case R: std::cout << "R" << std::endl;
		break;
	case NC_17: std::cout << "NC_17" << std::endl;
		break;
	default: std::cout << "NOT DEFINED" << std::endl;
		break;
	}
}

void printMovieGenre(const Movie& movie)
{
	switch (movie.genre)
	{
	case ACTION: std::cout << "ACTION" << std::endl;
		break;
	case COMEDY: std::cout << "COMEDY" << std::endl;
		break;
	case DRAMA: std::cout << "DRAMA" << std::endl;
		break;
	case HORROR: std::cout << "HORROR" << std::endl;
		break;
	case SCI_FI: std::cout << "SCI_FI" << std::endl;
		break;
	case ANIMATION: std::cout << "ANIMATION" << std::endl;
		break;
	default: std::cout << "NOT DEFINED" << std::endl;
		break;
	}
}

void printMovie(const Movie& movie)
{
	std::cout << movie.title << std::endl
		<< movie.imdbRating << std::endl << movie.duration << " min" << std::endl;
	printMovieAgeRating(movie);
	printMovieGenre(movie);
}

void printMovies(const Movie movies[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		printMovie(movies[i]);
	}
}

void sortMoviesByRating(Movie movies[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (movies[i].imdbRating < movies[j].imdbRating) 
			{
				std::swap(movies[i], movies[j]);
			}
		}
	}
}

int countFamilyAnimations(const Movie movies[], int size) 
{
	int count = 0;

	for (int i = 0; i < size; i++) 
	{
		if (movies[i].genre == ANIMATION && (movies[i].ageRating == G || movies[i].ageRating == PG)) 
		{
			count++;
		}
	}

	return count;
}
void filterHorrorStrictAge(const Movie movies[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		if (movies[i].genre == HORROR && movies[i].ageRating == NC_17) 
		{
			printMovies(&movies[i], 1);
		}
	}
}

void compareMovies(const Movie& movie1, const Movie& movie2) 
{
	if (movie1.imdbRating > movie2.imdbRating) 
	{
		std::cout << movie1.title << " is rated higher than " << movie2.title << ".\n";
	}
	else if (movie1.imdbRating < movie2.imdbRating) 
	{
		std::cout << movie2.title << " is rated higher than " << movie1.title << ".\n";
	}
	else 
	{
		std::cout << movie1.title << " and " << movie2.title << " have the same rating.\n";
	}
}

double averageSciFiPG13Duration(const Movie movies[], int size) 
{
	int sum = 0, count = 0;

	for (int i = 0; i < size; i++) 
	{
		if (movies[i].genre == SCI_FI && movies[i].ageRating == PG_13) 
		{
			sum += movies[i].duration;
			count++;
		}
	}

	double average = 0.0;

	if (count > 0)
	{
		average = sum / count;
	}

	return average;
}
