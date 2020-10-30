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
};


// Implementation

void dictionary::readFile(string filename)
{
	string word;
	ifstream dictionary_text(filename);

	if (dictionary_text.is_open())
	{
		cout << "[INFO]: File opened successfully" << endl;
		while (getline(dictionary_text, word))
		{
			word_list.push_back(word);
		}
	}
	else
	{
		cout << "[ERROR]: file does not exist" << endl;
	}

	dictionary_text.close();
}

ostream& operator<<(ostream& os, const dictionary& dt)
{
	vector<string> print_words = dt.word_list;
	int size = print_words.size();

	for(int i = 0; i < size; i++)
	{
		os << print_words[i] << endl;
	}
	return os;
}

void dictionary::selectSort()
{
	int size = word_list.size();
	int i, j, min;
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

int binarySearch(vector<string> search_list, string word, int left, int right)
{
	if (right >= left)
	{
		int mid = (left + right) / 2;
		if (search_list[mid] == word)
		{
			return mid;
		}
		else if (search_list[mid] > word)
		{
			return binarySearch(search_list, word, left, mid - 1);
		}
		else if (search_list[mid] < word) 
		{
			return binarySearch(search_list, word, mid + 1, right);
		}
	}
	return -1;
}


int dictionary::lookUp(string word)
{
	int index = binarySearch(word_list, word, 0, word_list.size() - 1);
	return index;
}

vector<string> dictionary::get_list()
{
	return word_list;
}



#endif // Dictionary Class
