#include "BSTree.h"
#include"Genre.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	BSTree<string> GenreTree;
	bool quitProg = false;
	int pick;
	string genreName = "";
	string movieName = "";
	string Plot = "";
	string Editor = "";
	string ReleaseYear = "";
	string dummy;


	while (!quitProg)
	{
		system("CLS");

		cout << "\n\n";
		cout << "What would you like to do in our Genre Database?" << endl;
		cout << "(1) Add a genre to our database" << endl;
		cout << "(2) Add a movie to our database" << endl;
		cout << "(3) Modify a movie that is on our database" << endl;
		cout << "(4) List all genres in our database." << endl;
		cout << "(5) List all movies by genres." << endl;
		cout << "(6) List all movies for a specific genre." << endl;
		cout << "(7) Search for a movie in our data base." << endl;
		cout << "(8) Exit database and program." << endl;
		cout << "Enter a number from 1 to 8: >> ";
		cin >> pick;

		switch (pick)
		{
		case 1:
			cout << "Enter the genre you want to add to our database: ";
			cin.clear();
			cin.ignore(20, '\n');
			getline(cin, genreName);
			GenreTree.insert(genreName);
			system("PAUSE");


			break;
		case 2:
			system("CLS");
			cout << "Enter the info for the movie you want to add to our database\n";
			cin.clear();
			cin.ignore(20, '\n');
			cout << "Enter the genre of the movie: ";
			getline(cin, genreName);
			cout << "Enter the title of the movie: ";
			getline(cin, movieName);
			cout << "Enter the plot of the movie: ";
			getline(cin, Plot);
			cout << "Enter the editor of the movie: ";
			getline(cin, Editor);			
			cout << "Enter enter the year the movie released: ";
			getline(cin, ReleaseYear);
			
			GenreTree.insertMovieToGenre(genreName, movieName, Plot, Editor, ReleaseYear);
			system("PAUSE");


			break;
		case 3:
			cout << "Enter the genre of the movie: ";
			cin.clear();
			cin.ignore(20, '\n');
			getline(cin, genreName);
			GenreTree.editMovieInfo(genreName);
			system("PAUSE");

			break;
		case 4:
			GenreTree.printInOrder();
			system("PAUSE");


			break;
		case 5:
			GenreTree.printAllMoviesInsideTree();
			system("PAUSE");


			break;
		case 6:
			cin.clear();
			cin.ignore(20, '\n');
			cout << "Enter the genre to see the list of movies: ";
			getline(cin, genreName);
			GenreTree.printGenreMovies(genreName);
			system("PAUSE");


			break;
		case 7:
			cin.clear();
			cin.ignore(20, '\n');
			cout << "Enter the title of the movie: ";
			getline(cin, movieName);
			GenreTree.searchForMovieInTree(movieName);
			system("PAUSE");


			break;
		case 8:
			quitProg = true;			
			break;
		default:

			break;
		}
	}

	cout << endl;
	cout << endl;


	
	//   1. Add Genre
	//GenreTree.insert("Horror");
	//GenreTree.insert("Action");
	//GenreTree.insert("Comedy");
	 
	cout << endl;
	cout << endl;

	//	2. Add movie 
	//GenreTree.insertMovieToGenre("Action","Transformers", "Robots attack", "Michael Bay", "2009");
	//GenreTree.insertMovieToGenre("Comedy", "Anabelle", "Child possesed attack", "Tarantino", "2018");
	//GenreTree.insertMovieToGenre("Horror", "Carlos", "Child possesed attack", "Tarantino", "2018");
	//GenreTree.insertMovieToGenre("Action", "Jose", "Child possesed attack", "Tarantino", "2018");
	//GenreTree.insertMovieToGenre("Horror", "Alberto", "Child possesed attack", "Tarantino", "2018");
	//GenreTree.insertMovieToGenre("Comedy", "Aelo", "Child possesed attack", "Tarantino", "2018");

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
	//GenreTree.printAllMoviesInsideTree();

	cout << endl;
	cout << endl;

	//	6. List All Movies for a selected Genre
	//GenreTree.printGenreMovies("Action");
	//cout << endl;
	//GenreTree.printGenreMovies("Horror");

	cout << endl;
	cout << endl;

	//	7. Search for a specific movie

	//GenreTree.searchForMovieInTree("Aelo");
	//cout << "New Search \n\n";
	//GenreTree.searchForMovieInTree("Transformers");
	//cout << "New Search \n\n";
	//GenreTree.searchForMovieInTree("Carlos");
	//cout << "New Search \n\n";
	//GenreTree.searchForMovieInTree("Jose");

	return 0;
}