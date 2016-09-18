#pragma once
#include <iostream>
using namespace std;
template<class T>
class CircularLinkedList
{
	int listSize;
	int operation;
	class Node {
	public:
		T value;
		Node *next;
		Node(T value) { this->value = value; }
		T getValue() { return this->value; }
	};
	void deleteNode(Node *current, Node *prev);
	template <typename T>
	T getValidatedInput(T result)
	{
		if (cin.fail() || cin.get() != '\n')
		{
			cin.clear();
						
			while (cin.get() != '\n')
				;

			throw ios_base::failure("Invalid input.");
		}
		return result;
	}

public:
	CircularLinkedList();
	Node *dummy;
	void insert(T); // включение нового значения
	bool insert(T, int); // включение нового значения в позицию с заданным номером
	bool removeByPosition(int position);
	bool removeByValue(T); // удаление заданного значения из списка
	bool updateValueByPosition(T, int); // изменение значения с заданным номером в списке
	T read(int); // чтение значения с заданным номером в списке

	int getPositionByValue(T); // получение позиции в списке с заданным значением
	int getListSize(); // опрос размера списка
	bool isEmpty(); // проверка списка на пустоту
	void clear(); // очистка списка
	bool isExist(T); // опрос наличия заданного значения

	class Iterator {
		CircularLinkedList *list;
		Node *curr;
		bool valid;
	public:
		Iterator(CircularLinkedList* list) {
			this->list = list;
			beg();
		}
		void beg();
		void next();
		bool isValid();
		T getValue();
		bool operator==(const Iterator& iter) {
			if (iter->curr == this->curr && iter->list == this->list) {
				return true;
			}
			else {
				return false;
			}
		}
		Iterator & operator= (const Iterator& iter) {
			this->list = iter->list;
			this->curr = iter->curr;
			return *this;
		}
	};
	Iterator iterator();
	friend class Iterator;
};

// Iterator
template<class T>
typename CircularLinkedList<T>::Iterator CircularLinkedList<T>::iterator() {
	return Iterator(this);
}

template<class T>
void CircularLinkedList<T>::Iterator::beg() {
	valid = (list->dummy->next != list->dummy);
	curr = list->dummy->next;
}

template<class T>
void CircularLinkedList<T>::Iterator::next() {
	if (valid) {
		curr = curr->next;
		if (curr == list->dummy) {
			valid = false;
		}
	}
}

template<class T>
bool CircularLinkedList<T>::Iterator::isValid() {
	return valid;
}

template<class T>
T CircularLinkedList<T>::Iterator::getValue() {
	return this->curr->value;
}

// Linked list
template<typename T>
void CircularLinkedList<T>::deleteNode(Node *current, Node *prev)
{
	prev->next = current->next;
	delete current;
	listSize--;
}

template<typename T>
CircularLinkedList<T>::CircularLinkedList()
{
	dummy = new Node(T());
	dummy->next = dummy;
	listSize = 0;
	operation = 0;
}

template<typename T>
void CircularLinkedList<T>::insert(T value)
{
	Node* node = new Node(value);
	node->next = dummy->next;
	dummy->next = node;
	listSize++;
}

template<typename T>
bool CircularLinkedList<T>::insert(T value, int position)
{
	int i = 0;
	if (position > listSize) return false;

	Node *current = dummy;
	while (current->next != dummy) {
		if (i == position) break;
		i++;
		current = current->next;
	}
	if (i != position) {
		return false;
	}
	else {
		Node *node = new Node(value);
		node->next = current->next;
		current->next = node;
		listSize++;
		return true;
	}
}

template<typename T>
bool CircularLinkedList<T>::removeByValue(T value)
{
	if (isEmpty()) {
		return false;
	}
	operation = 0;
	Node *current = dummy->next, *prev = dummy;
	while (current != dummy) {
		if (current->value == value) break;
		prev = current;
		current = current->next;
		operation++;
	}

	if (current == dummy) {
		return false;
	}

	deleteNode(current, prev);
	return true;
}

template<typename T>
bool CircularLinkedList<T>::removeByPosition(int position)
{
	int i = 0;
	if (position > listSize) return false;
	Node *current = dummy->next, *prev = dummy;
	while (current != dummy) {
		if (i == position) break;
		i++;
		prev = current;
		current = current->next;
	}
	if (i != position || isEmpty() || current == dummy) {
		return false;
	}
	else {
		deleteNode(current, prev);
		return true;
	}
}

template<typename T>
int CircularLinkedList<T>::getListSize()
{
	return listSize;
}

template<typename T>
bool CircularLinkedList<T>::isEmpty()
{
	return listSize <= 0 ? true : false;
}

template<typename T>
void CircularLinkedList<T>::clear()
{
	Node *current = dummy->next, *next;
	dummy->next = dummy;
	while (current != dummy) {
		next = current->next;
		delete current;
		current = next;
	}
	listSize = 0;
}

template<typename T>
bool CircularLinkedList<T>::updateValueByPosition(T value, int position)
{
	if (isEmpty()) {
		return false;
	}
	int i = 0;
	Node* current = dummy->next;
	while (current != dummy) {
		if (i == position) break;
		i++;
		current = current->next;
	}
	current->value = value;
	return true;
}

template<typename T>
bool CircularLinkedList<T>::isExist(T value)
{
	if (isEmpty()) {
		return false;
	}

	Node* current = dummy->next;
	while (current != dummy) {
		if (current->value == value) {
			return true;
			break;
		}
		current = current->next;
	}
	return false;
}

template<typename T>
T CircularLinkedList<T>::read(int position)
{
	if (position > listSize || position < 0) {
		return false;
	}

	Node* current = dummy->next;
	int i = 0;
	while (current != dummy) {
		if (i == position) { return current->value; break; }
		current = current->next;
		i++;
	}
}

template<typename T>
int CircularLinkedList<T>::getPositionByValue(T value)
{
	Node *current = dummy->next; int i = 0;
	while (current != dummy) {
		if (current->value == value) { break; }
		i++;
		current = current->next;
		if (i > listSize) { break; }
	}
	return i;

	// Exception
}
