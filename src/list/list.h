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

/*template <class T>
void ListAdd(T *element, struct list<T> *list);
template <class T>
void RemoveAt(int index, struct list<T> *list);
template<class T>
T* ElementAt(int index, struct list<T> *list);
template <class T>
int CountElements(struct list<T> *list);
*/
#include "list.cpp"

#endif
