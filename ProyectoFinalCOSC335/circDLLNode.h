/**********************
COSC 335
Singly linked node
This class implements the singly linked node using templates
Each nodes two attributes:
	-info: stores the actual value
	-next: a pointer to the next node in the list
******************/


#include <iostream>
using namespace std;
/**********************************
Class Declaration

***********************/
template <class T>
class IntDLLNode {
public:
	IntDLLNode(); //Default constructor
	IntDLLNode(IntDLLNode<T>*, T i, T Plot, T Editor, T ReleaseY, T Genre, IntDLLNode<T>*); //Special constructor
	void setMovieDetails(T Info, T Plot, T Editor, T ReleaseY , T Genre);
	T getInfo(); //getInfo 
	T getPlot();
	T getEditor();
	T getReleaseYear();
	T getMovieGenre();
	IntDLLNode<T>* getNext(); // getNext
	IntDLLNode<T>* getPrev(); // getPrev
	void setInfo(T); //setInfo 
	void setNext(IntDLLNode<T>*); //Set next
	void setPrev(IntDLLNode<T>*); //Set Prev
private:

	IntDLLNode<T>* prev;//Points to the previous node in the list
	T info, plot, edit, releaseYear, genre; //Actual data	
	IntDLLNode<T>* next; //Points to the next node in the list
};


/*****
	Default constructor
	Creates a empty node
*****/
template <class T>
IntDLLNode<T>::IntDLLNode()
{
	next = prev = 0;
}

/******
	Special constructor:
	Creates a node with value i in the info attribute and next pointing to null
	@params:
		*p: pointer to the previous node
		i: actual value to be stored
		*n: pointer to the next node
*******/
template <class T>
IntDLLNode<T>::IntDLLNode(IntDLLNode<T>* p, T i, T Plot, T Editor, T ReleaseY, T Genre, IntDLLNode<T>* n)
{
	info = i;
	prev = p;
	next = n;
	plot = Plot;
	edit = Editor;
	genre = Genre;
	releaseYear = ReleaseY;
}

template<class T>
inline void IntDLLNode<T>::setMovieDetails(T Info, T Plot, T Editor, T ReleaseY , T Genre)
{
	info = Info;
	plot = Plot;
	edit = Editor;
	genre = Genre;
	releaseYear = ReleaseY;
}



/********
	getInfo
	returns the info value
*********/
template <class T>
T IntDLLNode<T>::getInfo()
{
	return info;
}

template<class T>
inline T IntDLLNode<T>::getPlot()
{
	return plot;
}

template<class T>
inline T IntDLLNode<T>::getEditor()
{
	return edit;
}

template<class T>
inline T IntDLLNode<T>::getReleaseYear()
{
	return releaseYear;
}

template<class T>
inline T IntDLLNode<T>::getMovieGenre()
{
	return genre;
}

/********
	getNext
	returns a point to next node the list
**********/
template <class T>
IntDLLNode<T>* IntDLLNode<T>::getNext()
{
	return next;
}

/********
	getPrev
	returns a point to prev node the list
**********/
template <class T>
IntDLLNode<T>* IntDLLNode<T>::getPrev()
{
	return prev;
}


/********
	setInfo
	Set i as the node info
*******/
template <class T>
void IntDLLNode<T>::setInfo(T i)
{
	info = i;
}

/********
	setNext
	Points next attribute to the next list node
********/
template <class T>
void IntDLLNode<T>::setNext(IntDLLNode<T>* n)
{
	next = n;
}

/********
	setPrev
	Points next attribute to the prev list node
********/
template <class T>
void IntDLLNode<T>::setPrev(IntDLLNode<T>* p)
{
	prev = p;
}
