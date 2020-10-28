#include <iostream>
#include <vector>
#include <time.h>
#include "dictionary.h"
#include "grid.h"
using namespace std;


int main()
{
	cout << "Word Search" << endl;

	const clock_t begin_time = clock();
	cout << begin_time << endl;

	dictionary dict1;

	dict1.readFile("./input_files/small_test_dict.txt");

	dict1.selectSort();

	cout << dict1;

	cout << float(clock() - begin_time) << endl;
}