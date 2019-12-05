#pragma once

#include "circDLList.h"
template <class T>
class Genre
{
public:

	string getGenreName();
	void addMovie(T, T, T, T, T);
	void setGenreName(string genreName);
	void printAllMovies();
	void searchMovie(T movieName);
	void editMovieData(T, T, T, T, T, T);


private:
	string title;
	circDLList<T> movieList;
};

template<class T>
inline string Genre<T>::getGenreName()
{
	return title;
}

template<class T>
inline void Genre<T>::addMovie(T Name, T Plot, T Editor, T ReleaseYear, T movieGenre)
{
	movieList.sortInsert(Name, Plot, Editor, ReleaseYear, movieGenre);
}

template<class T>
inline void Genre<T>::setGenreName(string genreName)
{
	title = genreName;
}

template<class T>
inline void Genre<T>::printAllMovies()
{
	movieList.printRevList();
}

template<class T>
inline void Genre<T>::searchMovie(T movieName)
{
	movieList.printSpecificMovie(movieName);
}

template<class T>
inline void Genre<T>::editMovieData(T Name, T NewName, T Plot, T Editor, T ReleaseYear, T movieGenre)
{
	movieList.modifyMovieData(Name, NewName, Plot, Editor, ReleaseYear, movieGenre);
}
