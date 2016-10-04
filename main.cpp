#include <iostream>
#include <conio.h>
#include "CircularLinkedList.h"
using namespace std;
// 8.	��������� ������ � ���������, ����������� �� ���� �������� ���������� � �������������� ���������� ��������.

template<class T>
void displayList(CircularLinkedList<T>* list) {
	system("cls");
	CircularLinkedList<T>::Iterator iter = list->iterator();
	int listSize = list->getListSize();
	while (listSize > 0) {
		cout << iter.getValue() << endl;
		iter.next();
		listSize--;
	}
	system("pause");
}

template<class T>
T getElement() {
	cout << "������� �������: ";
	T temp;
	cin >> temp;
	return temp;
}

template<class T>
int getIndex() {
	cout << "������� ������: ";
	int i; cin >> i;
	return i;
}

template<class T>
void iterMenu(CircularLinkedList<T>* list, typename CircularLinkedList<T>::Iterator *iter)
{
	system("cls");
	int choose;
	cout << "���� ���������" << endl;
	cout << "1: � ������" << endl;
	cout << "2: ������� � ����������" << endl;
	cout << "3: ��������� �� �������� �� ������� ?" << endl;
	cout << "4: ��������: ���������" << endl;
	cout << "5: �����" << endl;

	cin >> choose;
	switch (choose) {
	case 1:
		iter->beg();
		iterMenu(list, iter);
		break;
	case 2:
		iter->next();
		iterMenu(list, iter);
		break;
	case 3:
		system("cls");
		iter->isValid() ? cout << "���������" << endl : cout << "�� ���������" << endl;
		system("pause");
		iterMenu(list, iter);
		break;
	case 4:
		system("cls");
		cout << iter->getValue() << endl;
		system("pause");
		iterMenu(list, iter);
		break;
	case 5:
		menu(list, iter);
		system("cls");
		break;
	case 6:
		break;
	}
}

template <typename T>
T getValidatedInput()
{
	T result;
	cin >> result;

	if (cin.fail() || cin.get() != '\n')
	{
		cin.clear();

		while (cin.get() != '\n')
			;

		throw ios_base::failure("Invalid input.");
	}
	return result;
}

template<typename T>
T validate() {
	while (true)
	{
		try
		{
			return getValidatedInput<T>();
		}
		catch (exception e)
		{
			cerr << e.what() << endl;
			continue;
		}

		break;
	}
}

template<class T>
void testMenu(CircularLinkedList<T>* list, typename CircularLinkedList<T>::Iterator *iter)
{
	system("cls");
	int choose;
	cout << "���� ��� ������������" << endl;
	cout << "1: ��������� ����" << endl;
	cout << "2: ���������� �������� ��� �������" << endl;
	cout << "3: ���������� �������� ��� ��������" << endl;
	cout << "4: ���������� �������� ��� ������" << endl;
	cout << "5: �����" << endl;
	cin >> choose;
	switch (choose) {
	case 1:
		system("cls");
		int n;
		cout << "���������� �������: " << endl;
		cin >> n;
		for (int i = 1; i < n; i++) {
			if (i % 3 == 0) {
				int position = rand() % (list->getListSize() + 1 - 0);
				list->removeByPosition(position);
				position = rand() % (list->getListSize() + 1 - 0);
				list->insert(rand(), position);
			}
			int value = rand();
			list->insert(value);
		}
		cout << "���������!" << endl;
		system("pause");
		testMenu(list, iter);
		break;
	case 2:
		cout << "�������: " << list->getInsertOperation() << endl;
		system("pause");
		testMenu(list, iter);
		break;
	case 3:
		cout << "��������: " << list->getRemoveOperation() << endl;
		system("pause");
		testMenu(list, iter);
		break;
	case 4:
		cout << "�����: " << list->getSearchOperation() << endl;
		system("pause");
		testMenu(list, iter);
		break;
	case 5:
		menu(list, iter);
		break;
	}
}

template<class T>
void menu(CircularLinkedList<T>* list, typename CircularLinkedList<T>::Iterator *iter) {
	system("cls");
	int choose, position =  -1;
	T value;
	char *outOfRange = "Exception occured: index out of range";
	cout << "Menu" << endl;
	cout << "1: ����� ������� ������" << endl;
	cout << "2: ������� ������" << endl;
	cout << "3: �������� ������ �� �������" << endl;
	cout << "4: ����� ������� ��������� ��������" << endl;
	cout << "5: ������ �������� � �������� ������� � ������" << endl;
	cout << "6: ��������� �������� � �������� ������� � ������" << endl;
	cout << "7: ��������� ������� � ������ � �������� ���������" << endl;
	cout << "8: ��������� ������ ��������" << endl;
	cout << "9: ��������� ������ �������� � ������� � �������� �������" << endl;
	cout << "10: �������� ��������� �������� �� ������" << endl;
	cout << "11: �������� �������� �� ������� � �������� �������" << endl;
	cout << "12: �������� ���� ������" << endl;
	cout << "13: �������� � ����������" << endl;
	cout << "14: ������������" << endl;
	cout << "15: �����" << endl;
	
	cin >> choose;
	switch (choose) {
		case 1:
			system("cls");
			cout << "������ ������: " << list->getListSize() << endl;
			system("pause");
			menu(list, iter);
			break;
		case 2:
			system("cls");
			list->clear();
			cout << "������ ����" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 3:
			system("cls");
			list->isEmpty() ? cout << "������ ����" << endl : cout << "������ �� ����" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 4:
			system("cls");
			cout << "������� �������� ��� ������" << endl;
			cin >> value;
			list->isExist(value) ? cout << "�������� �������" << endl : cout << "�������� �� �������" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 5:
			system("cls");
			cout << "������� ������� ��� ������" << endl;
			cin >> position;
			try {
				cout << list->read(position) << endl;
			}
			catch (out_of_range) {
				cout << outOfRange << endl;
			}
			system("pause");
			menu(list, iter);
			break;
		case 6:
			system("cls");
			cout << "������� ������� ��� ���������" << endl;
			cin >> position;
			system("cls");
			cout << "������� ����� ��������" << endl;
			cin >> value;
			try {
				list->updateValueByPosition(value, position) ? cout << "�������� ��������!" << endl : cout << "�������� �� ��������" << endl;
			} 
			catch (out_of_range) {
				cout << outOfRange << endl;
			}
			system("pause");
			menu(list, iter);
			break;
		case 7:
			system("cls");
			cout << "������� �������� ��� ������ �������" << endl;
			cin >> value;
			try {
				cout << "�������: " << list->getPositionByValue(value) << endl;
			}
			catch (out_of_range) {
				cout << outOfRange << endl;
			}
			system("pause");
			menu(list, iter);
			break;
		case 8:
			system("cls");
			value = validate<T>();
			list->insert(value);
			system("pause");
			menu(list, iter);
			break;
		case 9:
			system("cls");
			cout << "������� �������� ��� �������" << endl;
			cin >> value;
			cout << "������� ��� �������: " << endl;
			cin >> position;
			try {
				list->insert(value, position);
			}
			catch (out_of_range) {
				cout << outOfRange << endl;
			}
			system("pause");
			menu(list, iter);
			break;
		case 10:
			system("cls");
			cout << "������� �������� ��� ��������" << endl;
			cin >> value;
			list->removeByValue(value) ? cout << "�������� �������!" << endl : cout << "�������� �� �������" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 11:
			system("cls");
			cout << "������� ������� ��� ��������" << endl;
			cin >> position;
			try {
				list->removeByPosition(position);
			}
			catch (out_of_range) {
				cout << outOfRange << endl;
			}
			system("pause");
			menu(list, iter);
			break;
		case 12:
			displayList(list);
			menu(list, iter);
			break;
		case 13:
			iterMenu(list, iter);
			break;
		case 14:
			testMenu(list, iter);
			break;
		case 15:
			break;
		default:
			cout << "Choose correct function" << endl;
			system("pause");
			break;
		}
}

int main() {
	//changed encoding
	setlocale(LC_ALL, "russian");
	CircularLinkedList<long>* empty = new CircularLinkedList<long>();
	CircularLinkedList<long>::Iterator *iter = &empty->iterator();
	menu(empty, iter);
}