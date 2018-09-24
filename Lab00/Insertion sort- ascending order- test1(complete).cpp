//whehdwns
//pg 26 from textbook
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void insertionsort(int arr[], int n){
 	for (int i = 0; i < n-1; i++){
	 int j=i+1;
     	  int key = arr[j];
     	  while (j > 0 && key > arr[j-1]) {
      	  	   arr[j] = arr[j-1];
       	  	  j--;
      		 }
      		 arr[j] = key;
 	  }
}

void printsort(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ";";
	}
}

int main()
{
	int size;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	insertionsort(arr, size);
	printsort(arr, size);
	return 0;
}




