//reference
//http://www.martinbroadhurst.com/concatenate-two-vectors-in-c.html
//https://www2.hawaii.edu/~nodari/teaching/s17/Notes/Topic-10.html
//https://www.slideshare.net/shimulsakhawat/bucket-sort
#include <iostream>
#include<cstdlib>
#include<cmath>
#include <stdlib.h>
using namespace std;

void insertionsort(float arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
		int key = arr[j];
		while (j > 0 && key > arr[j - 1]) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}


void BUCKET_SORT(float arr[], int key){

	float buckets[key][key];
	int B[key];
	for (int i = 0; i<key; i++) {
		B[i] = 0;
	}

	for (int i = 0; i < key; i++) {
		int array = (int)(floor)(key*arr[i]);
		buckets[array][B[array]] = arr[i];
		B[array]++;

	}
	for (int i = 0; i < key; i++) {
		insertionsort(buckets[i], B[i]-1);
	}
	int index = 0;
	for (int i = 0; i<key; i++) {
		for (int j = 0; j<B[i]; j++) {
			arr[index] = buckets[i][j];
			index++;
		}
	}
	
}
void printsort(float arr[], int n) {
	for (int i = 0; i < n; i++)
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
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	BUCKET_SORT(arr, size);
	printsort(arr, size);
	return 0;
}


