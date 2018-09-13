#include <iostream>
#include <stdlib.h>

using namespace std;


int linearSearch(int *arr, int size, int value){
	for(int i=0; i<size; i++){
		if(arr[i] == value){
			return i;
		}
	}
	return -1;
}


int main() {
	int uservalue;
	int arraysize;
	cin >> arraysize;
	cin >> uservalue;

		int *array = (int*)malloc(sizeof(int)*arraysize);

		for (int i = 0; i < arraysize; i++)
		{
			cin >> array[i];
		}
		cout << linearSearch(array,arraysize,uservalue) << endl;

		free(array);
		cin>>arraysize;
}
