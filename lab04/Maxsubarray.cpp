#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <climits>
#include <iostream>
#include <cmath>
using namespace std;


int maxcrossingsubarray(int arr[], int low, int mid, int high){
	int left_sum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= low; i--) {
		sum = sum + arr[i];
		if (sum > left_sum) {
			left_sum = sum;
		}
	}
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = mid + 1; i <= high; i++) {
		sum = sum + arr[i];
		if (sum > right_sum) {
			right_sum = sum;
		}
	}
	return (left_sum + right_sum);

}

int maxsubarray(int arr[], int low, int high) {
	if (high == low) {
		return arr[low];
	}
	else {
		int mid = floor(int((low + high) / 2.0));

		int maxleft_sum = maxsubarray(arr, low, mid);
		int maxright_sum = maxsubarray(arr, mid + 1, high);
		int maxcross_sum = maxcrossingsubarray(arr, low, mid, high);
		
			if ((maxleft_sum >= maxright_sum) && (maxleft_sum >= maxcross_sum)) 
				return maxleft_sum;
			else if ((maxright_sum >= maxleft_sum) && (maxright_sum >= maxcross_sum)) 
				return maxright_sum;
			else 
				return maxcross_sum;
	}
}

int main() {
	int size;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	int result = maxsubarray(arr, 0, size - 1);
	cout << result;
	return 0;
}



