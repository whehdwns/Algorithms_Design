#include <iostream>
#include <stdlib.h>
#include <cstdlib>
//pg 171, 179 from textbook
//pg 171 normal quicksort
//pg 179 randomized quicksort
using namespace std;

int swap(int *x, int *y) {
	int exchange = *x;
	*x = *y;
	*y = exchange;
}

int PARTITION(int arr[], int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (arr[j] <= x) {
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

int Randomized_Partition(int arr[], int p, int r) {
	int i = p + rand() % (r - p + 1);
	swap(arr[r], arr[i]);
	return PARTITION(arr, p, r);
}


int Randomized_Quicksort(int arr[], int p, int r) {
	if (p < r) {
		int q = Randomized_Partition(arr, p, r);
		Randomized_Quicksort(arr, p, q - 1);
		Randomized_Quicksort(arr, q + 1, r);
	}
}


void printsort(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ";";
	}
}


int main() {
	int num;
	cin >> num;
	int *arr = new int[num];
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	Randomized_Quicksort(arr, 0, num - 1);
	printsort(arr, num);
	return 0;
}
