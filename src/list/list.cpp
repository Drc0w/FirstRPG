#include "list.h"

#ifndef LIST_CPP_
#define LIST_CPP_
using namespace std;

template<class T>
int ListCountElements(struct list<T> *list)
{
	struct list<T> *l = list;
	if (l == NULL)
		return 0;
	int count = 1;
	for (; l->next != NULL; l = l->next)
		count += 1;
	return count;
}

template <class T>
struct list<T>* ListAdd(T *element, struct list<T> *list)
{
	struct list<T> *l = list;
	if (l == NULL)
	{
		l = new struct list<T>();
		l->element = element;
		l->index = 0;
		l->next = NULL;
		return l;
	}
	else
	{
		for (; l->next != NULL; l = l->next);
		l->next = new struct list<T>();
		l = l->next;
		l->element = element;
		l->index = l->index + 1;
		l->next = NULL;
	}
	return list;
}

template <class T>
void ListRemoveAt(int index, struct list<T> *list)
{
	struct list<T> *l = list;
	if (index < ListCountElements(l))
	{
		for (int i = 0; i < index; i++, l = l->next);
		struct list<T> *tmp = l->next;
		l->next = tmp->next;
		free(tmp);
		l = l->next;
		for (; l->next != NULL; l->index++, l = l->next);
	}
	else
		cout << index << " out of bounds in RemoveAt(int index, struct list *list)" << endl;
}

template <class T>
T* ListElementAt(int index, struct list<T> *list)
{
	if (index < ListCountElements(list))
	{
		struct list<T> *l = list;
		for (int i = 0; i < index; i++, l = l->next);
		return l->element;
	}
	else
		cout << index << " out of bounds in ElementAt(int index, struct list *list)" << endl;
	return NULL;
}

#endif
