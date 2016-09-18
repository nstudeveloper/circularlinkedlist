#include <iostream>
#include <conio.h>
#include "CircularLinkedList.h"
using namespace std;
// 8.	Структура данных – кольцевая, односвязная на базе адресных указателей с использованием фиктивного элемента.
/*
int main(){
	CircularLinkedList<int> list;
	cout << list.isEmpty() << endl;
	list.insert(5);
	list.insert(1510);
	list.insert(15);
	list.insert(1220);
	list.insert(52);
	list.insert(120, 2);
	cout << list.isEmpty() << endl;
	list.clear();
	cout << list.isEmpty() << endl;
	list.updateValueByPosition(145, 2);
}
*/

template<class T>
void displayList(CircularLinkedList<T>* list) {
	system("cls");
	CircularLinkedList<T>::Iterator iter = list->iterator();
	while (iter.isValid()) {
		cout << iter.getValue() << endl;
		iter.next();
	}
	system("pause");
}

template<class T>
T getElement() {
	cout << "Введите элемент: ";
	T temp;
	cin >> temp;
	return temp;
}

template<class T>
int getIndex() {
	cout << "Введите индекс: ";
	int i; cin >> i;
	return i;
}

template<class T>
void iterMenu(CircularLinkedList<T>* list, typename CircularLinkedList<T>::Iterator *iter)
{
	system("cls");
	int choose;
	cout << "Меню итератора" << endl;
	cout << "1: В начало" << endl;
	cout << "2: Перейти к следующему" << endl;
	cout << "3: Указывает ли итератор на элемент ?" << endl;
	cout << "4: Итератор: прочитать" << endl;
	cout << "2: Перейти к следующему" << endl;
	cin >> choose;
	switch (choose) {
	case 1:
		iter->beg();
		menu(list, iter);
		break;
	case 2:
		iter->next();
		menu(list, iter);
		break;
	case 3:
		cout << iter->isValid();
		system("cls");
		menu(list, iter);
		break;
	case 4:
//		cout << **iter << endl;
		system("cls");
		break;
	case 5:
		break;
	case 6:
		break;
	}
}

template<class T>
void menu(CircularLinkedList<T>* list, typename CircularLinkedList<T>::Iterator *iter) {
	system("cls");
	int choose, position, value = -1;
	cout << "Menu" << endl;
	cout << "1: Опрос размера списка" << endl;
	cout << "2: Очистка списка" << endl;
	cout << "3: Проверка списка на пустоту" << endl;
	cout << "4: Опрос наличия заданного значения" << endl;
	cout << "5: Чтение значения с заданным номером в списке" << endl;
	cout << "6: Изменение значения с заданным номером в списке" << endl;
	cout << "7: Получение позиции в списке с заданным значением" << endl;
	cout << "8: Включение нового значения" << endl;
	cout << "9: Включение нового значения в позицию с заданным номером" << endl;
	cout << "10: Удаление заданного значения из списка" << endl;
	cout << "11: Удаление значения из позиции с заданным номером" << endl;
	cout << "12: Показать весь список" << endl;
	cout << "13: Операции с итератором" << endl;

	cin >> choose;
	switch (choose) {
		case 1:
			system("cls");
			cout << "Размер списка: " << list->getListSize() << endl;
			system("pause");
			menu(list, iter);
			break;
		case 2:
			system("cls");
			list->clear();
			cout << "Список пуст" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 3:
			system("cls");
			list->isEmpty() ? cout << "Список пуст" << endl : cout << "Список не пуст" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 4:
			system("cls");
			cout << "Введите значение для поиска" << endl;
			cin >> value;
			list->isExist(value) ? cout << "Значение найдено" << endl : cout << "Значение не найдено" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 5:
			system("cls");
			cout << "Введите позицию для поиска" << endl;
			cin >> position;
			cout << list->read(position) << endl;
			system("pause");
			menu(list, iter);
			break;
		case 6:
			system("cls");
			cout << "Введите позицию для изменения" << endl;
			cin >> position;
			system("cls");
			cout << "Введите новое значение" << endl;
			cin >> value;
			list->updateValueByPosition(value, position) ? cout << "Значение изменено!" << endl : cout << "Значение не изменено" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 7:
			system("cls");
			cout << "Введите значение для поиска позиции" << endl;
			cin >> value;
			cout << "Позиция: " << list->getPositionByValue(value) << endl;
			system("pause");
			menu(list, iter);
			break;
		case 8:
			system("cls");
			cout << "Введите значение для вставки" << endl;
			cin >> value;
			list->insert(value);
			cout << "Значение вставлено" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 9:
			system("cls");
			cout << "Введите значение для вставки" << endl;
			cin >> value;
			cout << "Позиция для вставки: " << endl;
			cin >> position;
			list->insert(value, position) ? cout << "Значение вставлено!" << endl : cout << "Значение не вставлено" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 10:
			system("cls");
			cout << "Введите значение для удаления" << endl;
			cin >> value;
			list->removeByValue(value) ? cout << "Значение удалено!" << endl : cout << "Значение не удалено" << endl;
			system("pause");
			menu(list, iter);
			break;
		case 11:
			system("cls");
			cout << "Введите позицию для удаления" << endl;
			cin >> position;
			list->removeByPosition(position) ? cout << "Значение удалено!" << endl : cout << "Значение не удалено" << endl;
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
		default:
			cout << "Choose correct function" << endl;
			break;
		}
}


int main() {
	setlocale(LC_ALL, "russian");
	CircularLinkedList<long>* empty = new CircularLinkedList<long>();
	CircularLinkedList<long>::Iterator *iter = &empty->iterator();
	menu(empty, iter);
}