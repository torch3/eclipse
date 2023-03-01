#include <iostream>
#include <malloc.h>
using namespace std;

class Object {
    public:
        int *x = nullptr;
        Object(int n);
        void output();
};

Object :: Object(int n) {
    if (n > 4) {
        x = (int*)malloc(8 * sizeof(int));
        for (int i = 0; i < 8; i++) {
            x[i] = n;
        }
    }
};
void Object :: output() {
    int n = 8;
    cout << sizeof(x) << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << x[i] << "  ";
    }
    cout << x[n - 1];
    delete x;
}
int main() {
    Object qwe(8);
    qwe.output();
    return 0;
}
