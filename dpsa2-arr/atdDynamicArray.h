#ifndef ATDDYNAMICARRAY_H_
#define ATDDYNAMICARRAY_H_
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef unsigned int uint;
struct typeX {
	uint n = 0;
	uint *X = nullptr;
	typeX(int n1) {
		n = n1;
		X = (uint*)malloc(n * sizeof(uint));
	}
	typeX(){
		n = 0;
	}
};

void input(typeX &a);
void output(typeX a);
void delElem(typeX &a, int pos);
void insElem(typeX &a, int pos, int num);
void evenLenPalArr(typeX a, typeX &b);

bool isEvenLenPal(uint number) {
	int dir = number;
	int rev = 0;
	int len = 0;
	while (number != 0) {
		rev = rev * 10 + number % 10;
		number /= 10;
		len++;
	}
	return (dir == rev) and (len % 2 == 0) and (dir != 0);
};
void input(typeX &a) {
	cout << "Input " << a.n << " numbers:" << endl;
	for (uint i = 0; i < a.n; i++) {
		cin >> a.X[i];
	}
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
void evenLenPalArr(typeX a, typeX &b) {
	b.n = 0;
	b.X = (uint*)malloc(0);
	for (uint i = 0; i < a.n; i++) {
		if (isEvenLenPal(a.X[i])) {
			if ((b.X = (uint*)realloc(b.X, (b.n + 1) * sizeof(uint))) != nullptr) {
				b.X	[b.n] = a.X[i];
				b.n++;
			}
		}
	}
};
#endif
