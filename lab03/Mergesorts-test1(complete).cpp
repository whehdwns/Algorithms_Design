#include <iostream>
#include <stdlib.h>

using namespace std;

void printsort(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ";";
	}
}

void Merge(int arr[], int lo, int  mi, int hi) {
	int *temp = new int[hi - lo + 1];
	int i = lo, j = mi + 1;
	int k = 0;
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mi)
		temp[k++] = arr[i++];
	while (j <= hi)
		temp[k++] = arr[j++];
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];

	delete[]temp;
}
void merges(int arr[], int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = (lo + hi) >> 1;
		merges(arr, lo, mid);
		merges(arr, mid + 1, hi);
		Merge(arr, lo, mid, hi);
	}
}
void MergeSort(int arr[], int arr_size) {
	merges(arr, 0, arr_size - 1);
}

int main() {

	int size;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	MergeSort(arr, size);
	//merges(arr, 0, size - 1);
	printsort(arr, size);
	return 0;
}

