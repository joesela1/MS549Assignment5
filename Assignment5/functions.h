#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Node {
public:
	int d;
	Node* left;
	Node* right;
	Node(int num) {
		d = num;
		left = nullptr;
		right = nullptr;
	}
};
class binarySearchTree {
public:
	Node* rootNode;
	binarySearchTree();
	Node* add(Node* node, int num);
	Node* min(Node* node);
	Node* remove(Node* node, int num);
	Node* max(Node* node);
	Node* find(Node* node, int num);
	
	void add(int num);
	void remove(int num);
	void inOrderTraverse(Node* node);
	void inOrderTraverse();
	Node* find(int num);
};

#endif