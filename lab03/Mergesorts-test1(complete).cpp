#include <iostream>
#include <stdlib.h>

using namespace std;

void printsort(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ";";
	}
}

void Merge(int arr[], int low, int  mid, int high) {
	int *msearch = new int[high - low + 1];
	int i = low, j = mid + 1;
	int k = 0;
	
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j])
			msearch[k++] = arr[i++];
		else
			msearch[k++] = arr[j++];
	}
	while (i <= mid)
		msearch[k++] = arr[i++];
	while (j <= high)
		msearch[k++] = arr[j++];
	for (k = 0, i = low; i <= high; ++i, ++k)
		arr[i] = msearch[k];
}

void merges(int arr[], int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) >> 1;
		
		merges(arr, low, mid);
		merges(arr, mid + 1, high);
		Merge(arr, low, mid, high);
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

