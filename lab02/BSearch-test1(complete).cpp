//whehdwns
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
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
	cout << binarySearch(arr, 0, size-1, value);
	return 0;
}



