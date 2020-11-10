/*
* Alex Negulescu		negulescu.a@northeastern.edu
* Ethan Chen			chen.eth@northeastern.edu
*
* This file contains the dictionary class. The dictionary class has a readFile()
* function that accesses a .txt file and reads each word into a vector of str.
* The class also contains an overloaded "<<" operator that allows the entire
* dictionary to be printed. Also in this file is selectSort() function that
* uses the selection sort method to reorder the word_list. There is also a
* lookUp() function that utilizes a binarySearch() function created in this
* file. Finally, there is a get_list() function that simply returns the vector
* of strings when called.
*/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Declaration
class dictionary
{
private:
	vector<string> word_list;

public:
	// read words from file into vector
	void readFile(string filename);

	// print the wordlist
	friend ostream& operator<<(ostream& os, const dictionary& dt);

	// sort the wordList using selection sort
	void selectSort();

	// lookup a word using binary search
	int lookUp(string word);

	// return list
	vector<string> get_list();

	vector<string> quicksortDict();
};


// Implementation
//constructor for dictionary class
void dictionary::readFile(string filename)
{
	//create a word variable to transfer words from .txt file into the vector
	string word;

	//open file using filename parameter passed to constructor
	ifstream dictionary_text(filename);

	//ensure file opens correctly
	if (dictionary_text.is_open())
	{
		cout << "[INFO]: File opened successfully" << endl;
		//loops as long as line has value that can be read into the word string
		while (getline(dictionary_text, word))
		{
			//push word value into vector
			word_list.push_back(word);
		}
	}
	//if file not opened, warn user
	else
	{
		cout << "[ERROR]: file does not exist" << endl;
	}
	//close .txt file
	dictionary_text.close();
}

//overloaded operator to print dictionary
ostream& operator<<(ostream& os, const dictionary& dt)
{
	//creates a vector and sets it equal to the list
	vector<string> print_words = dt.word_list;
	//gets size of dictionary for printing purposes
	int size = print_words.size();

	//loop through size of string vector and print each element
	for (int i = 0; i < size; i++)
	{
		os << print_words[i] << endl;
	}
	return os;
}

//selection sort for word list created by constructor
void dictionary::selectSort()
{
	int size = word_list.size();
	int i, j, min;

	//uses known selection sort algorithm that assumes first value is min value
	//and then checks through following values until a value smaller than min
	//is found. Once the smallest value in the list is found, it is placed ahead
	//of the previous min value
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (word_list[j] < word_list[min])
			{
				min = j;
			}

		}
		string temp = word_list[min];
		word_list[min] = word_list[i];
		word_list[i] = temp;
	}

}

//binary search function
int binarySearch(vector<string> search_list, string word, int left, int right)
{
	//ensure that the right value is to the right or equal to the left value
	if (right >= left)
	{
		//middle value of left and right values
		int mid = (left + right) / 2;

		//if this is the word, return it as found
		if (search_list[mid] == word)
		{
			return mid;
		}
		//since list is sorted, if word is smaller, move to the left 
		else if (search_list[mid] > word)
		{
			return binarySearch(search_list, word, left, mid - 1);
		}
		//if word is larger, move to the right
		else if (search_list[mid] < word)
		{
			return binarySearch(search_list, word, mid + 1, right);
		}
	}
	return -1;
}

//calls binary search function
int dictionary::lookUp(string word)
{
	int index = binarySearch(word_list, word, 0, word_list.size() - 1);
	return index;
}

//returns word_list
vector<string> dictionary::get_list()
{
	return word_list;
}

vector<string> dictionary::quicksortDict()
{
	int left = 0;
	int i = left;
	int right = word_list.size();
	int j = right;
	string temp;
	string pivot = word_list[(left + right) / 2];

	while (i <= j)
	{
		while (word_list[i] < pivot)
			i++;
		while (word_list[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = word_list[i];
			word_list[i] = word_list[j];
			word_list[j] = temp;
			i++;
			j--;
		}
	}
	
	if (left < j)
		quicksortDict();

	if (i < right)
		quicksortDict();
}


#endif // Dictionary Class
