#include <iostream>
#include <vector>
#include "dictionary.h"
#include "grid.h"
using namespace std;


int main()
{
	cout << "Word Search" << endl;

	dictionary dict1;

	dict1.readFile("./input_files/Dictionary.txt");

	dict1.selectSort();

	cout << dict1;
}