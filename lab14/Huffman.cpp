//Huffman Code		pg 431


#include <iostream>
#include <climits>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Node {
	int nums;
	int freq;
	char character;
	Node* leftNode;
	Node* rightNode;
	string code;

	Node() {
		nums = -1;
		freq = 0;
		character = '\0';
		leftNode = NULL;
		rightNode = NULL;
		code = "";
	}
};

Node* MinHeap(vector<Node*> &huff) {

	int number;

	Node *tempNode = new Node();
	tempNode->freq = INT_MAX;

	for (int i = 0; i < huff.size(); i++) {
		if (tempNode->freq > huff[i]->freq) {
			number = i;
			tempNode = huff[i];
		}

		if (tempNode->freq == huff[i]->freq) {
			if (tempNode->nums > huff[i]->nums) {
				number = i;
				tempNode = huff[i];
			}
		}
	}	
	huff.erase(huff.begin() + number);

	return tempNode;
}


void print(map<char, string> &huffmap, Node *hufftree, string code) {

	if (hufftree != NULL) {
		print(huffmap, hufftree->leftNode, code + "0");

		if (hufftree->character != '\0') {
			map<char, string>::iterator it;	
			it = huffmap.find(hufftree->character);
			it->second = code;
		}

		print(huffmap, hufftree->rightNode, code + "1");
	}
	return;
}



Node* huffman( vector<Node*> &huff, int size) {
	Node *leftNode, *rightNode;

	for (int i = 1; i < size; i++) {

		Node *topNode = new Node();

		topNode->leftNode = MinHeap(huff);
		topNode->rightNode = MinHeap(huff);

		topNode->nums = topNode->leftNode->nums;
		topNode->freq = topNode->leftNode->freq + topNode->rightNode->freq;

		huff.push_back(topNode);
	}
	return huff[0];
}



int main() {
	int size;
	cin >> size;
	map<char, string> huffmap;
	vector<Node*> huff;
	for (int i = 0; i <size; i++)
	{
		Node *charactervalue = new Node();
		charactervalue->nums = i;
		charactervalue->character = 'A' +i;
		cin >> charactervalue->freq;
		huffmap.insert(pair<char, string>('A' + i, ""));
		huff.push_back(charactervalue);
	}

	Node *hufftree = huffman(huff,size);

	print(huffmap, hufftree, "");

	for (int i = 0; i<size; i++) {
		cout << huffmap.find('A' + i)->second << endl;
	}

	huffmap.clear();

	return 0;
}