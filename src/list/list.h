#ifndef LIST_H_
#define LIST_H_

#include <cstdlib>
#include <string>
#include <iostream>

template <class T>
struct list
{
	T *element;
	int index;
	struct list *next; 
};

#include "list.cpp"

#endif
