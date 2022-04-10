// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data) {
	// step 1 => create new Node (pointer);
	// step 2 => set data
	// step 3 => takecare of child nodes, initially be null
	// step 4 => return the reference

	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = nullptr; // eatch itaration we're initializing left and right child for every new node
	return newNode;
}

int main()
{
	Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);

	//			   root node
	//				   v 
	//				  (1)
	//			 |-----------|
	//			(2)			(3)
	//		  |-----|	 |-------|
	//		 (4)    N	 N		 N


	system("pause>0");
}