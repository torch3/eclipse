#ifndef ATDSTATICARRAY_H_
#define ATDSTATICARRAY_H_
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

typedef unsigned int uint;
const uint N = 1000;
struct typeX {
	uint n = 0;
	uint X[N] = {};
};

void input(typeX &a, int n);
void inputRandom(typeX &a, int n);
void output(typeX a);
void delElem(typeX &a, int pos);
void insElem(typeX &a, int pos, int num);
int firstPal(typeX a);
void delBeforePal(typeX &a);
void insAfterPal(typeX &a, int num);

bool isPal(int number) {
	int dir = number;
	int rev = 0;
	while (number != 0) {
		rev = rev * 10 + number % 10;
		number /= 10;
	}
	return dir == rev;
};
void input(typeX &a, int n) {
	cout << "Input " << n << " numbers:";
	for (int i = 0; i < n; i++) {
		cin >> a.X[i];
	}
	a.n = n;
};
void inputRandom(typeX &a, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
			a.X[i] = rand() % 300 + 1;
		}
		a.n = n;
};
void output(typeX a) {
	cout << "Array of " << a.n << " numbers:" << endl;;
	for (uint i = 0; i < a.n; i++) {
		cout << a.X[i] << " ";
	}
	cout << "\n";
};
void delElem(typeX &a, int pos) {
	for (uint i = pos; i < a.n; i++) {
		a.X[i] = a.X[i + 1];
	}
	a.n--;
};
void insElem(typeX &a, int pos, int num) {
	a.n++;
	for (int i = a.n - 1; i > pos; i--) {
		a.X[i] = a.X[i - 1];
	}
	a.X[pos] = num;
};
int firstPal(typeX a) {
	for (uint i = 0; i < a.n; i++) {
		if (isPal(a.X[i])) {
			return i;
		}
	}
	return -1;
};
void delBeforePal(typeX &a) {
	int pos = firstPal(a);
	if (pos > -1) {
		for (uint i = 0; i < a.n - pos; i++) {
			a.X[i] = a.X[i + pos];
		}
		a.n -= pos;
	}
};
void insAfterPal(typeX &a, int num) {
	int pos = firstPal(a);
	if (pos > -1) {
		pos += 1;
		a.n++;
		for (int i = a.n - 1; i > pos; i--) {
			a.X[i] = a.X[i - 1];
		}
		a.X[pos] = num;
	}
};
#endif
