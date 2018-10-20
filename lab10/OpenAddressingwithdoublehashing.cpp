//whehdwns
//Hash Table
// Open Addressing with double Hashing
//pg 270 -Hash insert
//pg 271 -Hash search- searching key
//Hash Delete- (using same concept of the hash search)- deleting key
//Hash Open Addressing with double hashing

#include <iostream>
using namespace std;


int main() {
	int size = 13; // fixed size / given size
	int key;
	int index;
	int hashtable[size];
	bool found = false;
	int number = 1; 
	//any value that is not equal 0
	for (int i = 0; i < size; i++)
	{
		hashtable[i] = number;
	}

	cin >> key;
	//From lab
	//the input terminates when the key -1 is read 
	// ( such a key must not be inserted in the hash table)
	//if the collision occurs
	while (key != -1) 
	{
		for (int i = 0; i < size; i++)//Find Index Inside the Hash Table
		{
			int hash1 = key % 13;
			int hash2 = 1+(key % 11);
			index = (hash1 + i * hash2) % size;
			if (hashtable[index] == number)
				break;
		}
			hashtable[index] = key;
			cin >> key;
	}
	//print the content of the hash table to the screen
	for (int i = 0; i < size; i++)
	{
		if (hashtable[i] != number)
			cout << hashtable[i];
		cout << endl;
	}

	cin >> key;

	//read the integers fom the input untill the number -2 is found
	// search 
	//if the collision occurs -> linear probing
	while (key != -2) 
	{ 
		for (int i = 0; i < size; i++)// i=i+1
		{
			int hash1 = key % 13;
			int hash2 = 1 + (key % 11);
			index = (hash1 + i * hash2) % size;
			if (hashtable[index] == key)// if the index in the hashtable is equal to key that is trying to search
			{
				cout << index << endl;
				found = true;// TRUE
				break;
			}
			
		}
		if (!found)// if the index in the hashtable is not equal to key
		{
			cout << "NOT_FOUND" << endl; // number is not inside the hash table
		}
		found = false;// FALSE
		cin >> key;
	}


	cin >> key;
	//for each number inputted , delete from hash table
	//read integers from the input untill the number -3 is found
	// delete
	while (key != -3) //if the collision occurs // deleting from the hash table // once the integer -3 is found then print the table
	{
		for (int i = 0; i < size; i++)
		{
			int hash1 = key % 13;
			int hash2 = 1 + (key % 11);
			index = (hash1 + i * hash2) % size;
			if (hashtable[index] == key)// if the index in the hashtable is equal to key is trying to delete
			{
				hashtable[index] = number;
				break;
			}
		}
		cin >> key;
	}
	//print the deleted content of the hash table
	for (int i = 0; i < size; i++)
	{
		if (hashtable[i] != number)
			cout << hashtable[i];
		cout << endl;
	}
}