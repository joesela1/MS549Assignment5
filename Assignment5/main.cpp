#include <iostream>
#include "functions.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {

	binarySearchTree t1;
	binarySearchTree t2;
	binarySearchTree t3;
	binarySearchTree t4;

	//100
	cout << "--------------------------------" << endl;
	cout << "Inserting 100 random numbers into Tree 1..." << endl;
	auto startTimeT1 = high_resolution_clock::now();
	for (int i = 0; i < 100; i++) {
		int randN = rand() % 5000;
		t1.add(randN);
	}
	auto endTimeT1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(endTimeT1 - startTimeT1);

	//1000
	cout << "--------------------------------" << endl;
	cout << "Inserting 1000 random numbers into Tree 2..." << endl;
	auto startTimeT2 = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		int randN = rand() % 5000;
		t2.add(randN);
	}
	auto endTimeT2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(endTimeT2 - startTimeT2);

	//10000
	cout << "--------------------------------" << endl;
	cout << "Inserting 10000 random numbers into Tree 3..." << endl;
	auto startTimeT3 = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++) {
		int randN = rand() % 5000;
		t3.add(randN);
	}
	auto endTimeT3 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>(endTimeT3 - startTimeT3);

	//100000
	cout << "--------------------------------" << endl;
	cout << "Inserting 100000 random numbers into Tree 4..." << endl;
	auto startTimeT4 = high_resolution_clock::now();
	for (int i = 0; i < 100000; i++) {
		int randN = rand() % 5000;
		t4.add(randN);
	}
	auto endTimeT4 = high_resolution_clock::now();
	auto duration4 = duration_cast<microseconds>(endTimeT4 - startTimeT4);

	//Table output
	cout << "--------------------------------" << endl;
	cout << left << setw(20) << " " << setw(10) << "100" << setw(10) << "1000" << setw(10) << "10000" << setw(10) << "100000" << setw(10) << endl;
	cout << left << setw(20) << "Performance" << setw(10) << duration1.count() << setw(10) << duration2.count() << setw(10) << duration3.count() << setw(10) << duration4.count() << setw(10) << endl;

	cout << "--------------------------------" << endl;
	cout << "Printing tree 1" << endl;
	t1.inOrderTraverse();

	cout << "--------------------------------" << endl;
	cout << "Printing tree 2" << endl;
	t2.inOrderTraverse();

	cout << "--------------------------------" << endl;
	cout << "Printing tree 3" << endl;
	t3.inOrderTraverse();

	cout << "--------------------------------" << endl;
	cout << "Printing tree 4" << endl;
	t4.inOrderTraverse();

	cout << "--------------------------------" << endl;
	Node* findNum = t1.find(3245);
	if (findNum != nullptr){
		cout << "Node found in the Tree" << endl;
	}
	else {
		cout << "Node not found in the Tree" << endl;
	}

	cout << "--------------------------------" << endl;
	cout << "Removing 4334 from Tree 2" << endl;
	t2.remove(4334);
	cout << "Printing tree 2";
	t2.inOrderTraverse();

	cout << "--------------------------------" << endl;
	cout << "finding maximum value in Tree 3" << endl;
	Node* maxNum = t3.max(t3.rootNode);
	cout << "Max value in Tree 3 is " << maxNum->d << endl;

	cout << "--------------------------------" << endl;

	return 0;
}