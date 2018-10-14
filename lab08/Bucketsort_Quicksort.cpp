//Bucket Sort using Quick sort

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;

void quick_sort(float a[], int i, int r) {
	int left;
	int right;
	float x = a[i];
	for (left = i, right = r; left<right; right--) 
	{
		while (a[right] >= x && left<right) 
			right--;
		if (left<right) 
			a[left] = a[right];
		while (a[left] <= x && left<right)
			left++;
		if (left >= right) 	
			a[right] = a[left];
	}
	a[left] = x;
	if (left>i) 
		quick_sort(a, i, left - 1);
	if (left<r) 
		quick_sort(a, left + 1, r);
}

void bucket_sort(float arr[], int key) {
	float buckets[key][key];
	int B[key];
	for (int i = 0; i<key; i++) {
		B[i] = 0;
	}
	for (int i = 0; i<key; i++) {
		int array = (int)(key*arr[i]);
		buckets[array][B[array]] = arr[i];
		B[array]++;
	}
	for (int i = 0; i<key; i++) {
		quick_sort(buckets[i], 0, B[i] - 1);
	}
	int index = 0;
	for (int i = 0; i<key; i++) {
		for (int j = 0; j<B[i]; j++) {
			arr[index] = buckets[i][j];
			index++;
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
	bucket_sort(arr, size);
	printsort(arr, size);
	return 0;
}
