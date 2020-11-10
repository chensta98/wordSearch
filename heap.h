#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>

using namespace std;

template <class T>
T heap
{
public:
	int parent(int i);
	int left(int i);
	int right(int i);
	void initializeMaxHeap(vector<string> vect);
}

int heap::parent(int i)
{
	return (i - 1) / 2;
}

int heap::left(int i)
{
	return (2 * i + 1);
}

int heap::right(int i)
{
	return (2 * 1 + 2);
}

void heap::initializeMaxHeap(vector<string> vect)
{
	string x;
	int j;
	x = vect[left()];
	j = 2 * left();
	while (j <= right())
	{
		if (j < right && vect[j + 1] > vect[j])
			j = j + 1;
		if (x > vect[j])
			break;
		else if (x <= vect[j])
		{
			vect[j / 2] = vect[j];
			j = 2 * j;
		}
	}
	vect[j / 2] = x;
	return;
}
#endif
