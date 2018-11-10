//Cut_rod					pg 363
//Memorize_cut_rod				pg 365
//Memorize_cut_rod_aux				pg 366
//Bottom_up_cut_rod				pg 366

//Exteneded bottom up cut rod			pg 369
//Print cut rod solution			pg 369
//Used pseudocode from textbook
//11/8/2018

#include <iostream>
#include <climits>

using namespace std;


int EXTENDED_BOTTOM_UP_CUT_ROD(int arr[], int s[], int size)
{
	int r[size];
	r[0] = 0;
	for (int j = 1; j <= size; j++)
	{
		int q = INT_MIN;
		for (int i = 1; i <= j; i++)
		{
			if (q < arr[i] + r[j - i])
			{
				s[j] = i;
				q = arr[i] + r[j - i];
			}
		}
		r[j] = q;
	}
	//cout << r[size] << endl;
	return r[size];
}


void PRINT_CUT_ROD_SOLUTION(int arr[], int size)
{
	int s[size];
	int r = EXTENDED_BOTTOM_UP_CUT_ROD(arr, s, size);
	cout << r << endl;

	while (size > 0) 
	{
		cout << s[size] << " ";
		size = size - s[size];
	}
	cout << "-1" << endl;
}

int main()
{
	int size;
	cin >> size;
	int *arr = (int*)malloc(sizeof(int)*size);
	for (int i =1; i <=size ; i++) 
	{
		cin >> arr[i];
	}
	PRINT_CUT_ROD_SOLUTION(arr, size);
	return 0;
}
