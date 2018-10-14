//reference
//pg 201 
//Using Merge sort for bucketsort
//Bucketsort/ Merge sort/ Counting sort

#include <iostream>
#include <vector>
#include<cstdlib>
#include<cmath>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


void Merge(float arr[], int low, int  mid, int high) {
	float *msearch = new float[high - low + 1];
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

void merges(float arr[], int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) >> 1;

		merges(arr, low, mid);
		merges(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}
void bucketSort(float arr[], int key, int size)
{
	int* sort = new int[size + 1];
	float* bucket = new float[key];

	for (int i = 0; i <= size; i++)
		sort[i] = 0;

	for (int i = 0; i < key; i++) {
		int array = int(size*arr[i]);
		sort[array]++;
		bucket[i] = arr[i];
	}
	for (int i = 1; i <= size; i++)
		sort[i] = sort[i]+sort[i - 1];

	for (int i = 0; i < key; i++)
		arr[--sort[(int)(size * bucket[i])]] = bucket[i];

	for (int i = 0; i < size; i++) {
		if (sort[i] < sort[i + 1]) {
			merges(arr, sort[i], sort[i + 1] - 1);
		}
	}
}


void printsort(float arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		cout << endl;
	}
}

int main()
{
	int size;
	cin >> size;
	float *arr = new float[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	bucketSort(arr, size, 10);
	printsort(arr, size);
	return 0;
}
