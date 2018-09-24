#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

using namespace std;
//pg 154 => MAX-HEAPIFY(A,i) => MAX_HEAPIFY
//pg 157 => BUILD-MAX-HEAP(A)=>BUILD_MAX_HEAP
// pg 160 => HEAPSORT(A)

int swap(int *x, int *y) {
	int exchange= *x;
	*x = *y;
	*y = exchange;
}

int MAX_HEAPIFY(int arr[], int index, int num) {
	//if i use <= instead of < then the number shows wrong
	int largest = num;
	int left = (2*num) + 1;
	int right = (2*num) + 2;
		if (left < index && arr[left] > arr[num]) 
		{
			largest = left;
		}
		else {
			largest = num;
		}
		if (right < index && arr[right]>arr[largest]) 
		{
			largest = right;
		}

		if (largest != num) 
		{
			swap(arr[num], arr[largest]);
			MAX_HEAPIFY(arr,index, largest);
		}
	}

int BUILD_MAX_HEAP(int arr[], int index) {
	//index/2-1; i>=0
	int length = floor(int(index / 2.0));
	for(int j=length-1; j>=0; j--)
	{
		MAX_HEAPIFY(arr, index, j);
	}
}
	
int HEAPSORT(int arr[], int index) {
	BUILD_MAX_HEAP(arr, index);
	//index-2, i>=1
	for (int i = index-1 ; i >= 0; i--) {// if I put index-2; then the first input number sorted at the last. 
		swap(arr[0], arr[i]);//
		arr[index] = arr[index] - 1;
		MAX_HEAPIFY(arr, i, 0);
	}

}

void printsort(int arr[], int index) {
	for (int i = 0; i < index; i++)
	{
		cout << arr[i] << ";";
	}
}


int main() {
	int index;
	cin >> index;
	int *arr = new int[index];
	for (int i = 0; i < index; i++)
		cin >> arr[i];
	HEAPSORT(arr, index);
	printsort(arr, index);
	return 0;
}

