#include <iostream>
#include "Genre.h"
using namespace std;

//Jonathan Vazquez Rivera
//jvazquez441@email.suagm.edu

template <class T>
class BSTNode : public Genre<T>
{
public:
	BSTNode(); // Default Constructor
	BSTNode(BSTNode<T> *l, T i, BSTNode<T>*r); // Special constructor
	T getInfo();
	void addMovieData(T Name, T Plot, T Editor, T ReleaseYear, T movieGenre);
	void editMovieData(T Name, T NewName, T Plot, T Editor, T ReleaseYear, T movieGenre);
	BSTNode<T>* getLeft();
	BSTNode<T>* getRight();
	void setInfo(T i);
	void setLeft(BSTNode<T>* l);
	void setRight(BSTNode<T>* r);
	void printGenreMovies();
	void searchMovie(T movieTitle);
	
private:
	BSTNode<T>* left;
	Genre<T> info;
	BSTNode<T>* right;
};

template<class T>
inline BSTNode<T>::BSTNode()
{
	right = left = 0;
}

template<class T>
inline BSTNode<T>::BSTNode(BSTNode<T>*l, T i, BSTNode<T>*r)
{
	info.setGenreName(i);
	left = l;
	right = r;
}

template<class T>
inline T BSTNode<T>::getInfo()
{
	return info.getGenreName();
}

template<class T>
inline void BSTNode<T>::addMovieData(T Name, T Plot, T Editor, T ReleaseYear, T movieGenre)
{
	info.addMovie(Name, Plot, Editor, ReleaseYear, movieGenre);
}

template<class T>
inline void BSTNode<T>::editMovieData(T Name, T NewName, T Plot, T Editor, T ReleaseYear, T movieGenre)
{
	info.editMovieData(Name, NewName, Plot, Editor, ReleaseYear, movieGenre);
}

template<class T>
inline BSTNode<T>* BSTNode<T>::getLeft()
{
	return left;
}

template<class T>
inline BSTNode<T>* BSTNode<T>::getRight()
{
	return right;
}

template<class T>
inline void BSTNode<T>::setInfo(T i)
{
	info.setGenreName(i);
}

template<class T>
inline void BSTNode<T>::setLeft(BSTNode<T>*l)
{
	left = l;
}

template<class T>
inline void BSTNode<T>::setRight(BSTNode<T>*r)
{
	right = r;
}

template<class T>
inline void BSTNode<T>::printGenreMovies()
{
	info.printAllMovies();
}

template<class T>
inline void BSTNode<T>::searchMovie(T movieTitle)
{
	info.searchMovie(movieTitle);
}
