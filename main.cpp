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

	dict1.readFile("./input_files/small_test_dict.txt");

	dict1.selectSort();

	cout << dict1; 

	cout << dict1.lookUp("geez");
}