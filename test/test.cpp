#include <iostream>

using namespace std;

class Object {
private:
	int *x = nullptr;

public:
	Object();
	Object(const Object & ob);
	Object(int n);
	~Object();
	void input(int n);
	void method_1(int n);
	void method_2(int n);
	int sum(int n);
};

Object :: Object() {
	cout << "Default constructor" << "\n";
}

Object :: Object(const Object & ob) {
	cout << "Copy constructor" << "\n";
}

Object :: Object(int n) {
	cout << "Constructor set" << "\n";
}

Object :: ~Object() {
	cout << "Destructor" << "\n";
}

void Object :: input(int n) {
	x = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}

void Object :: method_1(int n) {
	for (int i = 0; i < n; i += 2) {
		x[i] += x[i + 1];
	}
}

void Object :: method_2(int n) {
	for (int i = 0; i < n; i += 2) {
			x[i] *= x[i + 1];
	}
}

int Object :: sum(int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
			s += x[i];
		}
	return s;
}

void func(Object & ob, int n) {
	ob.method_2(n);
	cout << ob.sum(n) << "\n";
}

int main() {
	int arrSize;
	cin >> arrSize;
	if ((arrSize <= 2) or (arrSize / 2 == 1)) {
		cout << arrSize << "?";
		return 0;
	}
	cout << arrSize << "\n";
	Object a(arrSize);
	a.input(arrSize);
	func(a, arrSize);
	a.method_1(arrSize);
	cout << a.sum(arrSize) << "\n";
	return(0);
}
