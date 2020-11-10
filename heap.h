#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>

template <class T>
T heap
{
public:
	heap(vector<string> vect);
	int parent(int i);
	int left(int i);
	int right(int i);
}

heap::heap(vector<string> vect)
{
	make_heap(vect.begin(), vect.end());
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

#endif
