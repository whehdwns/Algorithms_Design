//matrix multiply		   	pg 371

//Matrix_Chain - order	  		pg 375
//print optimal parens	  		pg 377

//Used pseudocode from textbook
//11/8/2018

#include <iostream>
#include <climits>
#include <stdlib.h>
#include <vector>

using namespace std;

void PRINT_OPTIMAL_PARENS(vector<vector<int> > s, int i, int j)
{
	if (i == j) {
		cout << "A" << i-1;
	}
	else
	{
		cout << "(";
		PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
		cout << ".";
		PRINT_OPTIMAL_PARENS(s, s[i][j] + 1, j);
		cout << ")";
	}
}

void MATRIX_CHAIN_ORDER(int arr[], int size) 
{
	int m[size+1][size];
	vector<vector<int> >s;
	s.resize(size, vector<int>(size+1));

	for (int i = 1; i <=size; i++)
	{
		m[i][i] = 0;
	}
	for (int l = 2; l <= size; l++) 
	{
		for (int i = 1; i <=size - l + 1; i++)
		{
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) 
			{
				int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k]*arr[j];
				if (q < m[i][j]) 
				{
					m[i][j] = q;
					s[i][j] = k ;
				}
			}
		}
	}
	cout << m[1][size] << endl;
	PRINT_OPTIMAL_PARENS(s, 1, size);
	cout << endl;
}

int main() 
{
	int size;
	cin >> size;
	int *arr = (int*)malloc(sizeof(int)*size+1);
	for (int i = 0; i <= size; i++)
	{
		cin >> arr[i];
	}
	MATRIX_CHAIN_ORDER(arr, size);
	return 0;
}
