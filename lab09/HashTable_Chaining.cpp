//whehdwns

//pg 258
//
//

#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
#include <sstream>
using namespace std;

int Hash_Insert(list<int>* table, int key, int size) {
	int index = key % size;
	table[index].push_front(key);

}

int Hash_Delete(list<int>* table, int key, int size) {
	bool found = false;
	int index = key % size;

	for (list<int>::iterator it = table[index].begin(); it != table[index].end(); it++)
	{
		if (*it == key)
		{
			table[index].erase(it);
			cout << key << " : "<< "DELETED" << endl;
			cout << "++++++++++++++++++++" << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << key <<" :"<<" DELETE FAILED" << endl;
		cout << "++++++++++++++++++++" << endl;
	}
	 found = false;

}

int Hash_Search(list<int>* table, int key, int size){
	bool found = false;
	int hash = 0;
	int index = key % size;

	for (list<int>::iterator k = table[index].begin(); k != table[index].end(); k++)
	{
		if (*k == key)
		{
			cout << key << " :" << " FOUND AT " << index << ","<< hash<<endl;
			cout << "++++++++++++++++++++" << endl;
			found = true;
			break;
		}
		hash++;
	}
	if (!found)
	{
		cout << key << " :" << " NOT FOUND" << endl;
		cout << "++++++++++++++++++++" << endl;
	}
	 found = false;
}

void printsort(list<int> arr[], int n) {
	for (int i = 0; i<n; i++) 
	{
		cout << i << " : ";
		for (list<int>::iterator k = arr[i].begin(); k != arr[i].end(); k++)
		{
			cout << *k;
			if (++k != arr[i].end())
				cout << "->";
				k--;
			//cout << " " << *it << "->";
		}
		cout << endl;
	}
	cout << "++++++++++++++++++++" << endl;
}

int main()
{
	int key;
	int size;
	cin >> size;
	list<int>* Table = new list<int>[size];
	char line[100];
	while (std::cin.getline(line, 100)) {
		string chain(line);
		if (chain.size() == 0) {
			continue;
		}
		if (chain.substr(0, 1) == "e") {
			return 0;
		}
		if (chain.substr(0, 1) == "o") {
			printsort(Table, size);
			continue;
		}
		stringstream hashing(chain.substr(2, chain.size() - 1));
		if (!(hashing >> key)) {
			key = -1;
		}
		if (chain.substr(0, 1) == "i") {
			Hash_Insert(Table, key, size);
		}
		if (chain.substr(0, 1) == "d") {
			Hash_Delete(Table, key, size);
		}
		if (chain.substr(0, 1) == "s") {
			Hash_Search(Table, key, size);
		}
	}

}



