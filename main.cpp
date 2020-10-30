#include <iostream>
#include <vector>
#include <time.h>
#include "dictionary.h"
#include "grid.h"
using namespace std;

/*
vector<string> findMatches(grid letter_grid, dictionary search_dictionary)
{
	return
}
*/

int main()
{
	cout << "Word Search" << endl;

	dictionary test_dict;

	test_dict.readFile("./input_files/small_test_dict.txt");

	cout << test_dict << endl;

	cout << "SORTING " << endl;
	test_dict.selectSort();

	cout << test_dict << endl;

	cout << "TEST LOOKUP: " << test_dict.lookUp("code") << endl;


	grid small_grid("./input_files/15x15matrix.txt");

	//small_grid.print_grid();

}