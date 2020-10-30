/*
* Alex Negulescu		negulescu.a@northeastern.edu
* Ethan Chen			chen.eth@northeastern.edu
* 
* This file contains the class grid that is responsible for reading from input
* file of characters and creating a matrix. To do so, this file uses the
* d_matrix.h file provided to us. For debugging purposes and to show that the
* class works as intended, we have also included a print_grid() function as
* well as a get_matrix() function.
*/

#include "d_matrix.h"
#include <fstream>
using namespace std;

class grid
{
public:
	//class constructor
	grid(string filename);

	//void type function to print grid values
	void print_grid();

	//matrix<char> type function that will return the grid
	matrix<char> get_matrix();

private:
	//creates default matrix object "letter_grid" of type char
	matrix<char> letter_grid;
};

//constructor to create grid 
//passed filename as a parameter
grid::grid(string filename)
{
	//opens matrix file provided to constructor
	ifstream grid_file(filename);

	//check if file is found and opened
	if (grid_file.is_open())
	{
		cout << "[INFO]: File opened successfully" << endl;
		int rows, cols;

		//reads first two integers in file as we know format of file provides
		//the matrix rows and columns in first line
		grid_file >> rows >> skipws >> cols;
		cout << "ROWS: " << rows << " COLS: " << cols << endl;

		//use the resize function provided in d_matrix.h to change the default
		//matrix object to the correct size as stated in .txt file
		letter_grid.resize(rows, cols);

		//creates a string that will capture each line of file
		string line;
		for (int i = 0; i < rows; i++)
		{
			//reads line from .txt file
			getline(grid_file, line);
			if (i > 0)
			{
				//for loop here increments by 2 to avoid whitespace characters
				for (int j = 0; j < cols * 2; j += 2)
				{
					//places each character from file into grid, by position
					letter_grid[i - 1][j / 2] = line[j];
				}
			}
		}
		//closes .txt file
		grid_file.close();
	}
	//warn user if file can not be opened
	else
	{
		cout << "[ERROR]: File can not be opened" << endl;
	}

}

//function to print the entire grid
//simply loops through each row, printing each character before moving to the 
//next line
void grid::print_grid()
{
	for (int i = 0; i < letter_grid.rows(); i++)
	{
		for (int j = 0; j < letter_grid.cols(); j++)
		{
			cout << letter_grid[i][j] << " ";
		}
		cout << endl;
	}
}

//returns the matrix object
matrix<char> grid::get_matrix()
{
	return letter_grid;
}
