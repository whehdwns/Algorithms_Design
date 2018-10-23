//whehdwns

//INORDER_TREE_WALK		pg 288
//TREE_SEARCH			pg 290
//ITERATIVE_TREE_SEARCH	pg 291
//TREE_MINIMUM			pg 291
//preorder
//postorder
//TREE_INSERT			pg 294
//TRANSPLANT			pg 296
//TREE_DELETE			pg 298
//used psudocode from the textbook
//used same value from the textbook
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

struct Node 
{
	int value; // key
	Node *left; //left node
	Node *right; // right node
	Node *boss; // parents node
};
class BINARYSEACH 
{

public:
	BINARYSEACH();
	~BINARYSEACH();
	void TREE_INSERT(int treeinsert);
	void TREE_DELETE(int treedelete);
	void TREE_PRINT(string print);
private:
	void TRANSPLANT(Node *u, Node *v);
	void TREE_INORDER(Node *x);
	void TREE_PREORDER(Node *x);
	void TREE_POSTORDER(Node *x);
	Node *TREE_SEARCH(int treesearch);
	Node *root;
	Node *TREE_MINIMUM(Node *x);

};
//CONSTRUCTOR
//create the binary search tree
BINARYSEACH::BINARYSEACH()
{
	root = NULL;
}
//DECONSTRUCTOR
//empty constructor
BINARYSEACH::~BINARYSEACH()
{

}
//"compare" is for string class
//inserting node
void BINARYSEACH::TREE_INSERT(int treeinsert)
{
	Node * x = root;
	Node * y = NULL;
	Node * z = new Node();
	z->value = treeinsert;//value
	// in this while loop, the two pointers move down to tree, 
	//and choose whether the pointers goes left or right depends on comparing parents value and child value
	while (x != NULL)  
	{
		y = x;
		if (treeinsert < (x->value))// treeinsert is smaller than (x->value) z-> value < x-> value
		{
			x = x->left;
		}
		else 
		{
			x = x->right;
		}
	}
	//set the pointers that cause z to be inserted
	z->boss = y;
	if (y == NULL) 
	{
		root = z;	//Tree T was empty
	}
	else if (z->value < (y->value)) // treeinsert is smaller than (x->value)
	{
		y->left = z;
	}
	else 
	{
		y->right = z;
	}
}
void BINARYSEACH::TRANSPLANT(Node *u, Node *v)
{
	if (u->boss == NULL) // which u is the root of T
	{
		root = v;
	}
	else if (u == u->boss->left) //updating u.p.left if u is the left child
	{
		u->boss->left = v;
	}
	else	
	{
		u->boss->right = v; //updating u.p right if u is the right child
	}
	if (v != NULL) // update v.p if v is not nil'
	{
		v->boss = u->boss;
	}
}
//delete
void BINARYSEACH::TREE_DELETE(int treedelete)
{
	Node* z = TREE_SEARCH(treedelete);
	if (z == NULL) {//can't find the node
		return;
	}
	if (z->left == NULL)// node z has no right child
	{
		TRANSPLANT(z, z->right);
	}
	else if (z->right == NULL)//z only has left child
	{
		TRANSPLANT(z, z->left);
	}
	else
	{
		Node* y = TREE_MINIMUM(z->right);//find node y which is the successor of z
		if (y->boss != z) // if y is not z's left child
		{
			TRANSPLANT(y, y->right);//replace y as a child of its parent by y's right child and turn z's left child into y's right child
			y->right = z->right;;
			y->right->boss = y;
		}
		TRANSPLANT(z, y); //replace z as a child of its parents by y and replace y's left child by z's left child
		y->left = z->left;
		y->left->boss = y;
	}
}

Node *BINARYSEACH::TREE_MINIMUM(Node *x)
{
	while (x->left != NULL)
	{
		x = x->left;
	}
	return x;
}


Node *BINARYSEACH::TREE_SEARCH(int treesearch) //(int k)
{
	Node* x = root;
	if (x == NULL || treesearch == x->value) // treesearch == (x->value))
	{
		return x;
	}
	while (x != NULL && treesearch != x->value) {
		if (treesearch < x->value)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}

void BINARYSEACH::TREE_INORDER(Node *x)
{
	if (x != NULL) 
	{
		TREE_INORDER(x->left);//	1. check for left side of the value
		cout << x->value << endl;//	2. check for first value after checking left side
		TREE_INORDER(x->right);	//	3. check for right side of the value
	}
}

void BINARYSEACH::TREE_PREORDER(Node *x) 
{
	if (x != NULL) 
	{
		cout << x->value << endl;	// 1. check for top value
		TREE_PREORDER(x->left);		// 2. check for left-side of the value
		TREE_PREORDER(x->right);	// 3. check for right-side of the value
	}
}

void BINARYSEACH::TREE_POSTORDER(Node *x)
{
	if (x != NULL) 
	{
		TREE_POSTORDER(x->left); //		1. similar to inorder, check for left side of the value
		TREE_POSTORDER(x->right);//		2. check for right side of the value
		cout << x->value << endl;//		3. check top value at the last
	}
}

void BINARYSEACH::TREE_PRINT(string print)
{
	if (print == "INORDER") 
	{
		TREE_INORDER(root);
	}
	if (print == "PREORDER")
	{
		TREE_PREORDER(root);
	}
	if (print == "POSTORDER") 
	{
		TREE_POSTORDER(root);
	}
}

int main()
{
	BINARYSEACH BINARY;
	char line[100]; // fixed  size buffer// temporary size
	while (cin.getline(line, 100))
		//cin -> input with no space
		//cin.getline -> input with space
		// use return/continue for short if statement
		//use if/else for long if statement
	{
		string chain(line);
		if (chain.substr(0, 1) == "e") // 1 string for "e"
			//"e" <- finish
		{
			break;
		}
		if (chain.substr(0, 2) == "in")// 2 string for "in"
		{
			BINARY.TREE_PRINT("INORDER");
			cout << "++++++++++++++++++++" << endl;
			continue;
		}
		if (chain.substr(0, 3) == "pre") // 3 string for "pre"
		{
			BINARY.TREE_PRINT("PREORDER");
			cout << "++++++++++++++++++++" << endl;
			continue;
		}
		if (chain.substr(0, 4) == "post") // 4 string for "post"
		{
			BINARY.TREE_PRINT("POSTORDER");
			cout << "++++++++++++++++++++" << endl;
			continue;
		}
		//breaking input into word using string stream //for input and output to a string. 
		int key;
		stringstream binarysearch(chain.substr(2, chain.size()-1));
		if (!(binarysearch >> key)) //shift
		{
			key = 1;
		}
		if (chain.substr(0, 1) == "i")
		{   // insert
			BINARY.TREE_INSERT(key);
			//continue;
		}
		if (chain.substr(0, 1) == "d")
		{ // delete
			BINARY.TREE_DELETE(key);
			//continue;
		}
	}
	return 0;
}
