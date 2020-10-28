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
	for (int i = 0; i < word_list.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < word_list.size(); j++)
		{
			if (word_list[j] > word_list[min])
			{
				min = j;
			}
			string temp = word_list[min];
			word_list[min] = word_list[j];
			word_list[j] = temp;
		}
	}
}

int dictionary::lookUp(string word)
{
	// TODO
	return 0;
}


#endif // Dictionary Class
