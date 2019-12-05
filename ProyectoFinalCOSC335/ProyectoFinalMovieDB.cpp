#include "BSTree.h"
#include"Genre.h"

int main()
{

	cout << endl;
	cout << endl;

	BSTree<string> GenreTree;
	
	//   1. Add Genre
	GenreTree.insert("Horror");
	GenreTree.insert("Action");
	//GenreTree.insert("Comedy");

	cout << endl;
	cout << endl;

	//	2. Add movie 
	GenreTree.insertMovieToGenre("Action","Transformers", "Robots attack", "Michael Bay", "2009");
	GenreTree.insertMovieToGenre("Comedy", "Anabelle", "Child possesed attack", "Tarantino", "2018");
	GenreTree.insertMovieToGenre("Horror", "Carlos", "Child possesed attack", "Tarantino", "2018");
	GenreTree.insertMovieToGenre("Action", "Jose", "Child possesed attack", "Tarantino", "2018");
	GenreTree.insertMovieToGenre("Horror", "Alberto", "Child possesed attack", "Tarantino", "2018");
	GenreTree.insertMovieToGenre("Comedy", "Aelo", "Child possesed attack", "Tarantino", "2018");

	cout << endl;
	cout << endl;

	//	3. Modify Movie
	//GenreTree.editMovieInfo("Action");

	cout << endl;
	cout << endl;

	//	4. List all Genre
	//GenreTree.printInOrder();

	cout << endl;
	cout << endl;

	//	5. List all movies by genre
	GenreTree.printAllMoviesInsideTree();

	cout << endl;
	cout << endl;

	//	6. List All Movies for a selected Genre
	//GenreTree.printGenreMovies("Action");
	//cout << endl;
	//GenreTree.printGenreMovies("Horror");

	cout << endl;
	cout << endl;

	//	7. Search for a specific movie





	system("PAUSE");
}