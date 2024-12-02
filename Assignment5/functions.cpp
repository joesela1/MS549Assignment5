#include <iostream>
#include "functions.h"

using namespace std;

binarySearchTree::binarySearchTree() :rootNode(nullptr) {}
//-----------------------------------------------
Node* binarySearchTree::add(Node* node, int num) {
	if (node == nullptr) {
		return new Node(num);
	}
	if (num < node->d) {
		node->left = add(node->left, num);
	}
	else if (num > node->d) {
		node->right = add(node->right, num);
	}
	return node;
}
void binarySearchTree::add(int num) {
	rootNode = add(rootNode, num);
}
//-----------------------------------------------
Node* binarySearchTree::min(Node* node) {
	Node* curr = node;
	while (curr->left != nullptr) {
		curr = curr->left;
	}
	return curr;
}
Node* binarySearchTree::remove(Node* node, int num) {
	if (node == nullptr) {
		return node;
	}
	if (num < node->d) {
		node->left = remove(node->left, num);
	}
	else if (num > node->d) {
		node->right = remove(node->right, num);
	}
	else {
		if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}

		Node* temp = min(node->right);
		node->d = temp->d;
		node->right = remove(node->right, temp->d);
	}
	return node;
}
void binarySearchTree::remove(int num) {
	rootNode = remove(rootNode, num);
}
//-----------------------------------------------
Node* binarySearchTree::max(Node* node) {
	Node* curr = node;
	while (curr->right != nullptr) {
		curr = curr->right;
	}
	return curr;
}
//-----------------------------------------------
void binarySearchTree::inOrderTraverse(Node* node) {
	if (node != nullptr) {
		inOrderTraverse(node->left);
		cout << node->d << " ";
		inOrderTraverse(node->right);
	}
}
void binarySearchTree::inOrderTraverse() {
	inOrderTraverse(rootNode);
	cout << endl;
}
//-----------------------------------------------
Node* binarySearchTree::find(Node* node, int num) {
	if (node == nullptr || node->d == num) {
		return node;
	}
	if (node->d < num) {
		return find(node->right, num);
	}
	return find(node->left, num);
}
Node* binarySearchTree::find(int num) {
	return find(rootNode, num);
}
