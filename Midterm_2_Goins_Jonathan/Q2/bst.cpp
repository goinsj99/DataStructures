#include <iostream>
#include "bst.hpp"

BST::BST() {
	root = NULL;
}

BST::~BST() {
	deleteTree(root);
	root = NULL;
}
void BST::deleteTree(Node* node) {
	if (node != NULL) {
		deleteTree(node->leftChild);
		deleteTree(node->rightChild);
		delete node;
	}
}
int searchKeyHelper(Node* currNode, int key){
int counter = 0;

while(currNode!= nullptr){				//Iteravily traversed through the BST
	if(currNode->key == key){				// if not found currnode will eventually = nullptr
		counter++;		//found search key, return number of comaprisons 
		return counter;
	}
	if (key < currNode->key ){
		currNode = currNode->leftChild;	//search key is less than currnode key, goes left child. Add to counter
		counter++;
	}
	else{
		currNode = currNode->rightChild;  //search key is greater than currnode key, goes right child. Add to counter
		counter++;
	}
}
return counter;
}


/*
** Implement the following function to return the count of comparisons, 
**   you may implement helper functions.
*/
int BST::searchCounter(int target) {
	// your code here!
	int count2 = searchKeyHelper(root, target);	// set count 2 to total number of comparisons from searchkeyhelper
	
    return count2;

}
