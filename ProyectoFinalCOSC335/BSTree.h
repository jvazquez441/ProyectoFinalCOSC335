#include "BSTNode.h"

//Jonathan Vazquez Rivera
//jvazquez441@email.suagm.edu


template<class T>
class BSTree
{
public:
	BSTree();
	void insert(T val);
	bool remove(T val);
	BSTNode<T>* search(T val);
	bool isEmpty();
	void insertMovieToGenre(T treeGenre , T movieTitle , T Plot, T Editor, T ReleaseYear);
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void printGenreMovies(T val);
	void editMovieInfo(T treeGenre);
	void printAllMoviesInsideTree();

private:
	BSTNode<T>* root;
	void visitInOrder(BSTNode<T>* node);
	void printAllMoviesInTreeInOrder(BSTNode<T>* node);
	void visitPreOrder(BSTNode<T>* node);
	void visitPostOrder(BSTNode<T>* node);
	BSTNode<T>* recursiveSearch(BSTNode<T> *node, T val);
	bool recursiveSearchForRemove(BSTNode<T>* node, T val);
	BSTNode<T>* findLowest(BSTNode<T>* node);
};

template<class T>
inline BSTree<T>::BSTree()
{
	root = 0;
}

template<class T>
inline void BSTree<T>::insert(T val)
{
	if (root == 0)
	{
		root = new BSTNode<T>(0, val, 0);
	}
	else
	{
		BSTNode<T>* tmp, * sRoot;
		tmp = root;
		sRoot = tmp;
		
		while (tmp != 0)
		{
			sRoot = tmp;
			if (val < sRoot->getInfo())
			{
				tmp = tmp->getLeft();
			}
			else
			{
				tmp = tmp->getRight();
			}
		}
		if (val < sRoot->getInfo())
		{
			sRoot->setLeft(new BSTNode<T>(0, val, 0));
		}
		else
		{
			sRoot->setRight(new BSTNode<T>(0, val, 0));
		}
	}
}

template<class T>
inline bool BSTree<T>::remove(T val)
{
	bool res = false;
	if (root!=0)
	{
		if (root->getInfo()==val)
		{
			if ((root->getLeft()== 0) && (root->getRight() == 0))
			{
				delete root;
				root = 0;
			}
			else
			{
				BSTNode<T>* tmp;
				tmp = root;
				if (root->getLeft() == 0)
				{
					root = root->getRight();
				}
				else if(root->getRight() == 0)
				{
					root = root->getLeft();
				}
				else
				{
					BSTNode<T>* lowest;
					lowest = findLowest(root->getRight());

					if (root->getRight() == lowest)
					{
						lowest->setLeft(root->getLeft());
						root = lowest;
					}
					else
					{
						root = lowest;
						root->setLeft(tmp->getLeft());
						root->setRight(tmp->getRight());
					}
					delete tmp;
				}
			}
			res = true;
		}
		else
		{
			res = recursiveSearchForRemove(root, val);
		}
	}
	return res;
}

template<class T>
inline BSTNode<T>* BSTree<T>::search(T val)
{
	return recursiveSearch(root,val);
}

template<class T>
inline bool BSTree<T>::isEmpty()
{
	bool res = false;

	if (root == 0) {
		res = true;
	}

	return res;
}

template<class T>
inline void BSTree<T>::insertMovieToGenre(T val,T movieTitle,  T Plot, T Editor, T ReleaseYear)
{
	BSTNode<T>* res;
	BSTNode<T>* node;
	node = root;
	res = 0;
	if (node != 0)
	{
		if (val == node->getInfo())
		{
			res = node;
		}
		else if (val < node->getInfo())
		{
			res = recursiveSearch(node->getLeft(), val);
		}
		else
		{
			res = recursiveSearch(node->getRight(), val);
		}
	}

	if (res == 0)
	{
		cout << "Genre not found" << endl;
	}
	else
	{
		/*res->addMovie(movieTitle, Plot, Editor, ReleaseYear, val);*/
		res->addMovieData(movieTitle, Plot, Editor, ReleaseYear, val);
		//res->printGenreMovies();
	}
}

template<class T>
inline void BSTree<T>::printInOrder()
{
	visitInOrder(root);
}

template<class T>
inline void BSTree<T>::printPreOrder()
{
	visitPreOrder(root);
}

template<class T>
inline void BSTree<T>::printPostOrder()
{
	visitPostOrder(root);
}

template<class T>
inline void BSTree<T>::printGenreMovies(T val)
{
	BSTNode<T>* res;
	BSTNode<T>* node;
	node = root;
	res = 0;
	if (node != 0)
	{
		if (val == node->getInfo())
		{
			res = node;
		}
		else if (val < node->getInfo())
		{
			res = recursiveSearch(node->getLeft(), val);
		}
		else
		{
			res = recursiveSearch(node->getRight(), val);
		}

	}
	
	res->printGenreMovies();
}

template<class T>
inline void BSTree<T>::editMovieInfo(T val)
{
	BSTNode<T>* res;
	BSTNode<T>* node;

	string searchTitle, newTitle, newPlot, newEditor, newReleaseYear;
	node = root;
	res = 0;
	if (node != 0)
	{
		if (val == node->getInfo())
		{
			res = node;
		}
		else if (val < node->getInfo())
		{
			res = recursiveSearch(node->getLeft(), val);
		}
		else
		{
			res = recursiveSearch(node->getRight(), val);
		}
	}

	cout << endl;
	cout << endl;

	cout << "Enter movie to edit ";
	cin >> searchTitle;

	cout << "Enter new Title: ";
	cin >> newTitle;

	cout << "Enter new Plot: ";
	cin.clear();
	cin.ignore(20, '\n');
	getline(cin, newPlot);

	cout << "Enter new Editor: ";
	cin >> newEditor;

	cout << "Enter new Release Year: ";
	cin >> newReleaseYear;


	res->editMovieData(searchTitle, newTitle, newPlot, newEditor, newReleaseYear, val);
}

template<class T>
inline void BSTree<T>::printAllMoviesInsideTree()
{
	printAllMoviesInTreeInOrder(root);
}

template<class T>
inline void BSTree<T>::visitInOrder(BSTNode<T>* node)
{
	if (node != 0)
	{
		visitInOrder(node->getLeft());
		cout << "-" << node->getInfo() << "-";
		visitInOrder(node->getRight());
	}
}

template<class T>
inline void BSTree<T>::printAllMoviesInTreeInOrder(BSTNode<T>* node)
{
	if (node != 0)
	{

		printAllMoviesInTreeInOrder(node->getLeft());
		cout << "\n-" << node->getInfo() << "-\n";
		node->printGenreMovies();
		printAllMoviesInTreeInOrder(node->getRight());
	}
}

template<class T>
inline void BSTree<T>::visitPreOrder(BSTNode<T>* node)
{
	if (node != 0)
	{
		cout << "-" << node->getInfo() << "-";
		visitPreOrder(node->getLeft());
		visitPreOrder(node->getRight());
	}
}

template<class T>
inline void BSTree<T>::visitPostOrder(BSTNode<T>* node)
{
	if (node != 0)
	{
		visitPostOrder(node->getLeft());
		visitPostOrder(node->getRight());
		cout << "-" << node->getInfo() << "-";
	}
}

template<class T>
inline BSTNode<T>* BSTree<T>::recursiveSearch(BSTNode<T>* node, T val)
{
	BSTNode<T>* res;
	res = 0;
	if (node != 0)
	{
		if (val == node->getInfo())
		{
			res = node;
		}
		else if (val < node->getInfo())
		{
			res = recursiveSearch(node->getLeft(), val);
		}
		else
		{
			res = recursiveSearch(node->getRight(), val);
		}
	}
	return res;
}

template<class T>
inline bool BSTree<T>::recursiveSearchForRemove(BSTNode<T>* node, T val)
{
	bool res = false;
	BSTNode<T>* tmp, * found;

	if ((node->getLeft() != 0) && (val < node->getInfo()))
	{
		if (node->getLeft()->getInfo() == val)
		{
			found = node->getLeft();
			if (found->getRight() == 0)
			{
				node->setLeft(found->getLeft());
			}
			else
			{
				tmp = findLowest(found->getRight());
				node->setLeft(tmp);
			}
			res = true;
		}
		else
		{
			res = recursiveSearchForRemove(node->getLeft, val);
		}
	}
	else if ((node->getRight() != 0) && (val > node->getInfo()))
	{
		if (node->getRight()->getInfo() == val)
		{
			found = node->getRight();
			if (found->getRight() == 0)
			{
				node->setRight(found->getLeft());
			}
			else
			{
				tmp = findLowest(found->getRight());
				node->setRight(tmp);
			}
			res = true;
		}
		else
		{
			res = recursiveSearchForRemove(node->getRight(), val);
		}
	}
	return res;
}

template<class T>
inline BSTNode<T>* BSTree<T>::findLowest(BSTNode<T>* node)
{
	BSTNode<T>* tmp;
	if (node->getLeft() == 0)
	{
		tmp = node;
	}
	else
	{
		while (node->getLeft()->getLeft() != 0)
		{
			node = node->getLeft();
		}
		tmp = node->getLeft();
		node->setLeft(tmp->getRight());
	}
	return tmp;
}
