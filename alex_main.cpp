#include <iostream>
#include <vector>
#include <time.h>
#include "dictionary.h"
#include "grid.h"
using namespace std;


int main()
{
	cout << "Word Search" << endl;

	dictionary dict1;
	grid grid1("./input_files/15x15 matrix.txt");

	dict1.readFile("./input_files/dictionary.txt");

	dict1.selectSort();

	//cout << dict1;

	//cout << dict1.lookUp("geez");
	
	grid1.print_matrix();
}
