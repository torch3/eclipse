#include <iostream>
#include "atdStaticArray.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	typeX arr;
	int action, rn, n, pos, elem, pal;
	while (true) {
		cout << "=================Меню=================" << endl;
		cout << "1. Заполнить массив" << endl;
		cout << "2. Вывести массив" << endl;
		cout << "3. Удалить элемент" << endl;
		cout << "4. Вставить элемент" << endl;
		cout << "5. Найти палиндром" << endl;
		cout << "6. Удалить все элементы до палиндрома" << endl;
		cout << "7. Вставить элемент после палиндрома" << endl;
		cout << "8. Завершить работу программы" << endl;
		cout << "======================================" << endl;
		cout << "Выберите номер операции:" << endl;
		cin >> action;
		switch (action) {
		case 1:
			cout << "Введите размер массива:" << N << endl;
			cin >> n;
			if ((n < 1) or (n > N)) {
				cout << "Некорректное значение" << endl;
			}
			else {
				cout << "Выберите способ ввода:" << endl;
				cout << "1. Ввод с клавиатуры" << endl;
				cout << "2. Случайный ввод" << endl;
				cin >> rn;
				switch(rn) {
				case 1:
					input(arr, n);
					break;
				case 2:
					inputRandom(arr, n);
					break;
				default:
					cout << "Некорректное значение" << endl;
				}
			}
			break;
		case 2:
			if (arr.n > 0) {
				output(arr);
			}
			else {
				cout << "Массив не заполнен" << endl;
			}
			break;
		case 3:
			if (arr.n > 0) {
				cout << "Введите номер элемента:" << endl;
				cin >> pos;
				if (pos <= arr.n) {
					delElem(arr, pos);
				}
				else {
					cout << "Некорректное значение" << endl;
				}
			}
			else {
				cout << "Массив не заполнен" << endl;
			}
			break;
		case 4:
			if (arr.n > 0) {
				cout << "Введите номер элемента:" << endl;
				cin >> pos;
				if (pos <= arr.n + 1) {
					cout << "Введите вставляемое значение:" << endl;
					cin >> elem;
					insElem(arr, pos, elem);
				}
				else {
					cout << "Некорректное значение" << endl;
				}
			}
			else {
				cout << "Массив не заполнен" << endl;
			}
			break;
		case 5:
			if (arr.n > 0) {
				pal = firstPal(arr);
				if (pal > 0) {
					cout << pal << "-й элемент - палиндром" << endl;
				}
				else {
					cout << "В массиве нет палиндрома" << endl;
				}
			}
			else {
				cout << "Массив не заполнен" << endl;
			}
			break;
		case 6:
			if (arr.n > 0) {
				delBeforePal(arr);
			}
			else {
				cout << "Массив не заполнен" << endl;
			}
			break;
		case 7:
			if (arr.n > 0) {
				cout << "Введите вставляемое значение:" << endl;
				cin >> elem;
				insAfterPal(arr, elem);
			}
			else {
				cout << "Массив не заполнен" << endl;
			}
			break;
		case 8:
			return 0;
		}
	}
}
