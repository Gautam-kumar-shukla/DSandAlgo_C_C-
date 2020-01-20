// simple_bin_tree_console_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <assert.h>
#include <string>



/* Abstraction of node in binary tree */
struct btree_node {
	char *pChar;
	btree_node* left_node;
	btree_node* right_node;
};

struct btree_node* root_node = NULL;

/* Need function to add nodes in the tree*/
int Add_node(btree_node **pNode, char *pStr) {

	/* If the node is root node or starting node 
		then add it as root node, else it will be 
		left or right child node based on less than
		or greater then inequality

	*/
	if (*pNode == NULL) {
		*pNode = new btree_node;
		(*pNode)->left_node = NULL;
		(*pNode)->pChar = new char[strlen(pStr) + 1];
		strcpy_s((*pNode)->pChar, (strlen(pStr) + 1), pStr);
		(*pNode)->right_node = NULL;
		return 1;
	}
	else {
		if (strcmp((*pNode)->pChar, pStr) > 0) {
			return Add_node(&(*pNode)->left_node, pStr);
		}
		else {
			return Add_node(&(*pNode)->right_node, pStr);
		}
	}
}

/* print node in inorder traversal */
int Print_Node(struct btree_node *node) {
	using namespace std;
	if (node == NULL) {
		return 1;
	}
	Print_Node(node->left_node);
	cout << node->pChar << "\n";
	Print_Node(node->right_node);
	return 1;
}


#define MAX_SIZE 256
int main(int argc, char *argv[])
{
	/* Usage message*/
	using namespace std;
	if (argc  < 2) {
		cerr << "Usage" << argv[0] << "[1 | 2]" << "\n";
		cerr << "Where \n";
		cerr << "[1] is for double indirection base";
	}

	char *szPtr = new char[256];
	/*Read a text file from standard input device and build a binary tree */
	while (!cin.eof())
	{
		cin.get(szPtr, MAX_SIZE, '\n');
		// This is for eating new line character
		cin.get();
		if (strlen(szPtr)) {
			switch (*argv[1])
			{
			case '1':
				Add_node(&root_node, szPtr);
				break;
			case '2':
				break;
			default:
				break;
			}
		}
	}
	Print_Node(root_node);
 }

