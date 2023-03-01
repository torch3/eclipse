#include <iostream>
#include "atdDynamicArray.h"

using namespace std;

int main() {
	int n;
	cout << "Input size of array:" << endl;
	cin >> n;
	typeX arr(n), palArr;
	input(arr);
	evenLenPalArr(arr, palArr);
	if (palArr.n == 0) {
		cout << "There are no even-length palindromes in the input array:" << endl;
		output(arr);
	}
	else {
		cout << "Array of palimdromes:" << endl;
		output(palArr);
	}
	return 0;
}
