/**********************

...............................
.   Jonathan Vazquez Rivera   .
. jvazquez441@email.suagm.edu .
...............................
COSC 335
Singly linked node
This class implements the singly linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head point to null in an empty list
2. There is not need of a tail pointer
******************/

#include "circDLLNode.h"

template <class T>
class circDLList {
public:
	//Default constructor: creates an empty list
	circDLList();

	//Destructor: deallocate memory
	~circDLList();

	//addToHead(T val): creates a new node with val as info, 
	//and this new node is the new head 
	void addToHead(T val, T Plot, T Editor, T ReleaseY, T Genre);

	//addToTail(T val): creates a new node with val as info, 
	//and this new node is the new tail 	
	void addToTail(T val, T Plot, T Editor, T ReleaseY, T Genre);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//sortInsert(T val): creates a new node, and it is inserted sortly
	void sortInsert(T val, T Plot, T Editor, T ReleaseY, T Genre);

	//insert(int pos, T val): creates a new node, and it is inserted in position pos
	void insert(int pos, T val, T Plot, T Editor, T ReleaseY, T Genre);

	//printList(): prints all nodes in the list from head to tail
	void printList();

	//printList(): prints all nodes in the list from tail to head
	void printRevList();

	void printSpecificMovie(T movieTitle);


	void modifyMovieData(T val, T NewName, T Plot, T Editor, T ReleaseY, T Genre);

private:
	IntDLLNode<T>* head; //A pointer to the first node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
circDLList<T>::circDLList()
{
	head = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
circDLList<T>::~circDLList()
{
	while (!isEmpty())
		this->deleteFromHead();
}

/***********************

Implement other methods

***********************/


template<class T>
inline void circDLList<T>::addToHead(T val, T Plot, T Editor, T ReleaseY, T Genre)
{

	if (head != 0) {
		//Not an empty list
		IntDLLNode<T>* tmp;
		tmp = new IntDLLNode<T>(head->getPrev(), val, Plot, Editor, ReleaseY, Genre, head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
		head = tmp;
	}
	else { //An empty list
		cout << "Empty list" << endl;
		head = new IntDLLNode<T>(0, val, Plot, Editor, ReleaseY, Genre, 0);
		head->setPrev(head);
		head->setNext(head);
	}
}

template<class T>
inline void circDLList<T>::addToTail(T val, T Plot, T Editor, T ReleaseY, T Genre)
{
	if (head != 0) {
		//Not an empty list
		IntDLLNode<T>* tmp;
		tmp = new IntDLLNode<T>(head->getPrev(), val, Plot, Editor, ReleaseY, Genre, head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
	}
	else {
		//An empty list
		head = new IntDLLNode<T>(0, val, Plot, Editor, ReleaseY, Genre, 0);
		head->setPrev(head);
		head->setNext(head);
	}
}

template<class T>
inline void circDLList<T>::deleteFromHead()
{
	if (head != 0) {
		IntDLLNode<T>* tmp;
		tmp = head;
		if (head == head->getNext())
		{//One node list
			head = 0;
		}
		else { //list with more than one node
			head->getNext()->setPrev(head->getPrev());
			head->getPrev()->setNext(head->getNext());
			head = head->getNext();
		}
		delete tmp;
	}
}

template<class T>
inline void circDLList<T>::deleteFromTail()
{
	if (head != 0) {
		IntDLLNode<T>* tmp;
		tmp = head->getPrev();
		if (head == head->getNext()) {
			//One node list
			head = 0;
		}
		else { //A list with more than one node
			tmp->getPrev()->setNext(head);
			head->setPrev(tmp->getPrev());
		}
		delete tmp;
	}
}

template<class T>
inline bool circDLList<T>::isEmpty()
{
	bool res;
	res = false;
	if (head == 0)
	{
		res = true;
	}
	return res;
}

template<class T>
inline void circDLList<T>::sortInsert(T val, T Plot, T Editor, T ReleaseY, T Genre)
{
	if (head == 0)
	{
		addToHead(val, Plot, Editor, ReleaseY, Genre);
	}
	else
	{
		IntDLLNode<T>* tmp, * tmp2;
		tmp = head;
		tmp2 = 0;
		while ((val < tmp->getInfo()) && (tmp->getNext() != head))
		{
			tmp2 = tmp;
			tmp = tmp->getNext();
		}
		if ((tmp->getNext() == head) && (val < tmp->getInfo()))
		{
			addToTail(val, Plot, Editor, ReleaseY, Genre);
		}
		else
		{
			if ((tmp == head) && (val > tmp->getInfo())) {
				addToHead(val, Plot, Editor, ReleaseY, Genre);
			}
			else {
				IntDLLNode<T>* newNode = new IntDLLNode<T>(tmp2, val, Plot, Editor, ReleaseY, Genre, tmp);
				tmp2->setNext(newNode);
				tmp->setPrev(newNode);
			}
		}
	}
}

template<class T>
inline void circDLList<T>::printList()
{
	IntDLLNode<T>* ptrNode;
	ptrNode = head;
	if (ptrNode != 0) {
		while (ptrNode->getNext() != head) {
			cout << ptrNode->getInfo() << " ";
			ptrNode = ptrNode->getNext();
		}
		cout << ptrNode->getInfo() << " ";
	}
}

template<class T>
inline void circDLList<T>::printRevList()
{
	IntDLLNode<T>* ptrNode;
	ptrNode = head;
	if (ptrNode != 0) 
	{
		while (ptrNode->getPrev() != head) {
			ptrNode = ptrNode->getPrev();
			cout << "\nTitle: " << ptrNode->getInfo() 
				 << "\nEditor: " << ptrNode->getEditor() 
				 << "\nPlot: " << ptrNode->getPlot() 
				 << "\nRelease Year: " << ptrNode->getReleaseYear() 
				 << "\nGenre: " << ptrNode->getMovieGenre() << endl;
		}
		cout << "\nTitle: " << head->getInfo() 
			 << "\nEditor: " << head->getEditor() 
			 << "\nPlot: " << head->getPlot() 
			 << "\nRelease Year: " << head->getReleaseYear() 
			 << "\nGenre: " << head->getMovieGenre() << endl;
	}
}

template<class T>
inline void circDLList<T>::printSpecificMovie(T movieTitle)
{
	IntDLLNode<T>* ptrNode, * movieFound;
	ptrNode = movieFound = head;
	;
	if (ptrNode != 0)
	{
		while (ptrNode->getPrev() != head) 
		{
			if (ptrNode->getInfo() == movieTitle)
			{
				movieFound = ptrNode;
			}
			ptrNode = ptrNode->getPrev();
		}

		if (head->getInfo() == movieTitle)
		{
			cout << "\nTitle: " << head->getInfo()
				 << "\nEditor: " << head->getEditor()
				 << "\nPlot: " << head->getPlot()
				 << "\nRelease Year: " << head->getReleaseYear()
				 << "\nGenre: " << head->getMovieGenre() << endl;
		}
		else if (movieFound->getInfo() == movieTitle)
		{
			cout << "\nTitle: " << movieFound->getInfo()
				 << "\nEditor: " << movieFound->getEditor()
				 << "\nPlot: " << movieFound->getPlot()
				 << "\nRelease Year: " << movieFound->getReleaseYear()
				 << "\nGenre: " << movieFound->getMovieGenre() << endl;
		}
		else if (ptrNode->getInfo() == movieTitle)
		{
			cout << "\nTitle: " << ptrNode->getInfo()
				<< "\nEditor: " << ptrNode->getEditor()
				<< "\nPlot: " << ptrNode->getPlot()
				<< "\nRelease Year: " << ptrNode->getReleaseYear()
				<< "\nGenre: " << ptrNode->getMovieGenre() << endl;
		}
		else
		{
			cout << "Movie Not found \n\n";
		}
	}
}

template<class T>
inline void circDLList<T>::modifyMovieData(T val, T NewName,  T Plot, T Editor, T ReleaseY, T Genre)
{
	IntDLLNode<T>* ptrNode, * movieToEdit;
	ptrNode = head;
	movieToEdit = 0;
	if (ptrNode != 0) {
		while (ptrNode->getPrev() != head) {
			if (ptrNode->getInfo() == val)
			{
				movieToEdit = ptrNode;
			}
			ptrNode = ptrNode->getPrev();
		}

		if (movieToEdit == 0)
		{
			cout << "Movie not found\n\n";
		}
		else
		{
			movieToEdit->setMovieDetails(NewName, Plot, Editor, ReleaseY, Genre);
			cout << "Movie " << val << "edited sucessfuly";
		}
	}

}

template<class T>
inline void circDLList<T>::insert(int pos, T val, T Plot, T Editor, T ReleaseY, T Genre)
{
	IntDLLNode<T>* currentPtr, * previousPtr, * ptrNode;
	int size = 0;

	//Counts how many nodes are on the list

	ptrNode = head;
	if (ptrNode != 0) {
		while (ptrNode->getNext() != head)
		{
			ptrNode = ptrNode->getNext();
			size++;
		}
	}

	currentPtr = head;
	previousPtr = 0;

	if (pos == 1)
	{
		addToHead(val);
	}

	else if (pos > size)
	{
		cout << "\nPosition desired is out of bounds\n";
	}

	// If position desired is greater by one of the size,
	// adds the node to the Tail
	else if (pos == size + 1)
	{
		addToTail(val);
	}
	else
	{
		for (int i = 1; i < pos; i++)
		{
			for (int i = 1; i < pos; i++)
			{
				previousPtr = currentPtr;
				currentPtr = currentPtr->getNext();
			}
			previousPtr->setNext(new IntDLLNode<T>(previousPtr, val, currentPtr));
		}
	}



}