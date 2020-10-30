#include <iostream>
#include <vector>
#include <time.h>
#include "dictionary.h"
#include "grid.h"
using namespace std;


vector<string> findMatches(grid letter_grid, dictionary search_dictionary)
{
	vector<string> found_words;
	found_words.push_back("LIST OF FOUND WORDS: ");
	matrix<char> letter_matrix = letter_grid.get_matrix();
	vector<string> dict_string = search_dictionary.get_list();

	int rowBound = letter_matrix.rows();
	int colBound = letter_matrix.cols();

	for (int r = 0; r < rowBound; r++)
	{
		for (int c = 0; c < colBound; c++)
		{
			cout << "LETTER AT INDEX: " << r << " " << c << ": " << letter_matrix[r][c] << endl;
			string possible_word;
			possible_word.push_back(letter_matrix[r][c]);
			for (int l = 1; l < rowBound; l++)
			{
				int direction = l;
				

				//possible_word.push_back(letter_matrix[r][c + direction]);
				//cout << possible_word << endl;
			}
 		}
		
	}

	return found_words;
}


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

	small_grid.print_grid();

	dictionary large_dict;
	large_dict.readFile("./input_files/dictionary-sorted.txt");

	//cout << "LOOKUP NORTHEASTERN BIG LIST: " << large_dict.lookUp("northeastern") << endl;

	vector<string> matches = findMatches(small_grid, large_dict);

	for (int i = 0; i < matches.size(); i++)
	{
		cout << matches[i] << endl;
	}
}