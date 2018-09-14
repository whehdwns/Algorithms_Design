//whehdwns
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int linearSearch(int *arr, int size, int value) {
	for (int i = 0; i<size; i++) {
		if (value ==arr[i]) {
			return i;
		}
	}
	return -1;
}

int main() {

	int size;
	cin >> size;
	int *arr = new int[size];
	int value = 0;
	cin >> value;
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	cout << linearSearch(arr, size, value) << endl;
	return 0;
}


