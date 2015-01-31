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
	cout << (l == NULL) << endl;
	if (l == NULL)
	{
		l = (struct list<T>*)malloc(sizeof(struct list<T>));
		l->element = element;
		l->index = 0;
		l->next = NULL;
		return l;
	}
	else
	{
		for (; l->next != NULL; l = l->next);
		l->next = (struct list<T>*)malloc(sizeof(struct list<T>));
		struct list<T> *tmp = l;
		l = l->next;
		l->element = element;
		l->index = tmp->index + 1;
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
		for (; l != NULL && l->next != NULL; l = l->next)
		{
			if (l->next->index == index)
			{
				struct list<T> *tmp = l->next;
				delete(tmp->element);
				l->next = tmp->next;
				free(tmp);
				break;
			}
		}
		for (; l != NULL; l = l->next)
		{
			l->index--;
		}
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

template<class T>
bool ListElementExists(T *element, struct list<T> *list)
{
	struct list<T> *l = list;
	for (; l != NULL; l = l->next)
		if (*(l->element) == *element)
			return true;
	return false;
}

#endif
