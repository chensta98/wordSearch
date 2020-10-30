#include "d_matrix.h"
#include <fstream>
using namespace std;

class grid
{
public:
	grid(string filename);

	void print_grid();

	matrix<char> get_matrix();

private:
	matrix<char> letter_grid;
};

grid::grid(string filename)
{
	ifstream grid_file(filename);
	if (grid_file.is_open())
	{
		cout << "[INFO]: File opened successfully" << endl;
		int rows, cols;
		grid_file >> rows >> skipws >> cols;
		cout << "ROWS: " << rows << " COLS: " << cols << endl;
		letter_grid.resize(rows, cols);

		string line;
		for (int i = 0; i < rows; i++)
		{
			getline(grid_file, line);
			if (i > 0)
			{
				for (int j = 0; j < cols * 2; j+=2)
				{
					letter_grid[i - 1][j/2] = line[j];
				}
			}
		}

		grid_file.close();
	}
	else
	{
		cout << "[ERROR]: File can not be opened" << endl;
	}

}

void grid::print_grid()
{
	for(int i = 0; i < letter_grid.rows(); i++)
	{
		for (int j = 0; j < letter_grid.cols(); j++)
		{
			cout << letter_grid[i][j] << " ";
		}
		cout << endl;
	}
}

matrix<char> grid::get_matrix() 
{
	return letter_grid;
}
