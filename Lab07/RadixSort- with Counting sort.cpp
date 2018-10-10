/*reference
http://www.cplusplus.com/reference/stl/
https://cal-linux.com/tutorials/STL.html
http://www.cplusplus.com/reference/vector/vector/push_back/
http://www.cplusplus.com/reference/vector/vector/begin/
http://www.cplusplus.com/reference/vector/vector/end/

Textbook
	pg 195 for counting sort
	pg 198 for radix sort

*/
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
// require multidimensional array for this assignment
//		C[j][key] 
void COUNTING_SORT(vector<int> *arr, int key, int size)
{
	vector<int> * B = new vector<int>[size];

	int C[10] = { 0 };// C[0..k] be a new array  there are 10 digits (0-9) in this assignmens

	for (int j = 0; j < size; j++)
	{
		C[arr[j][key]] = C[arr[j][key]] + 1;
	}

	for (int i = 1; i < 10; i++)
	{
		C[i] = C[i]+ C[i - 1];
	}

	for (int j = size-1; j >= 0; j--)
	{
		B[C[arr[j][key]]-1] = arr[j];
		C[arr[j][key]] = C[arr[j][key]] - 1;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = B[i];
	}

}


void RADIX_SORT(vector<int> arr[], int digits)
{
	for (int i = 9; i >=0; i--) //(0~9) 10 digits
	{
		COUNTING_SORT(arr, i, digits);
	}
}


void PRINT_SORT(vector<int> arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		for (vector<int>::iterator it = arr[i].begin(); it != arr[i].end(); it++)// from reference 
																				//"returns an iterator pointing to the first element in the vector"
																				//"Returns an iterator referring to the past-the-end element in the vector container."
		{
			cout << *it << ";";
		}
		cout << endl; // if I remove this line 67, then it gives incorrect/ segmentation fault. (not sure why)
	}
}

int main()
{
	int size;
	int value;
	cin >> size;
	vector<int> *arr = new vector<int>[size];
	//multidimensional array => 2 for loops 
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<10; j++)
		{
			cin >> value;
			arr[i].push_back(value);//from referce - "add value/element to the vector each time a new integer is read"
			//values into array
		}
	}
	RADIX_SORT(arr, size);
	PRINT_SORT(arr, size);

	return 0;
}