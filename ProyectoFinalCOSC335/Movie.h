#pragma once
#include <string>
using namespace std;

template <class T>
class Movie
{
public:
	Movie();
	~Movie();

private:
	string title, plot, editor, releaseYear, genre;
};

template<class T>
inline Movie<T>::Movie()
{
}
