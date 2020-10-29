#include "d_matrix.h"
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class grid
{
public:
	grid(string filename);
	void print_matrix();

private:
	matrix<char> letter_grid;
	int rows, cols;
	char init_char = 'a';
	char write_char;
};

grid::grid(string filename)
{
	ifstream matrix_values(filename);

	if (matrix_values.is_open())
	{
		cout << "[INFO]: Grid file opened successfully" << endl;
		matrix_values >> rows >> skipws >> cols;;
		letter_grid.resize(rows, cols);

		for (int i = 0; i < letter_grid.rows(); i++)
		{
			for (int j = 0; j < letter_grid.cols(); j++)
			{
				matrix_values >> skipws >> write_char;
				write_char = letter_grid[i][j];
			}
		}
	}
}

void grid::print_matrix()
{
	cout << letter_grid[0][0];
}
