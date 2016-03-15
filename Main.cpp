#include "BST.cpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
enum Option {
	Exit = 0, Insert, InorderTreeWalk, PreorderTreeWalk, PostorderTreeWalk,
	Minimum, Maximum, TreeSearchRecursively, TreeSearchIteratively, 
	TreeSuccessor, TreeDelete
};

void InitializeTree(BST *bst);
void DrawMenu();
bool Switch(BST *bst, int option);

int main() {
	BST *bst = new BST();
	bool exit = false;
	int option;
	
	InitializeTree(bst);
	while(!exit) {
		DrawMenu();
		cin >> option;
		exit = Switch(bst, option);
	}
	return 0;
}

void InitializeTree(BST *bst) {
	srand(time(NULL));
	for(int i = 0; i < ((rand() % 20) + 5); i++)
		bst->Insert((rand() % 100) + 1);
}
void DrawMenu() {
	cout << "\tBST\n";
	cout << "1. Insert key." << endl
		<< "2. InorderTreeWalk." << endl
		<< "3. PreorderTreeWalk." << endl
		<< "4. PostorderTreeWalk." << endl
		<< "5. Minimum." << endl
		<< "6. Maximum." << endl
		<< "7. TreeSearchRecursively. " << endl
		<< "8. TreeSearchIteratively. " << endl
		<< "9. TreeSuccessor." << endl
		<< "10. TreeDelete." << endl
		<< "0. Exit." << endl
		<< "->";
}
bool Switch(BST *bst, int option) {
	int key;
	
	switch(option) {
		case Exit:
			return true;
		case Insert:
			cout << "Enter key: ";
			cin >> key;
			bst->Insert(key);
		break;
		case InorderTreeWalk:
			bst->InorderTreeWalk();
		break;
		case PreorderTreeWalk:
			bst->PreorderTreeWalk();
		break;
		case PostorderTreeWalk:
			bst->PostorderTreeWalk();
		break;
		case Minimum:
			key = bst->Minimum();
			cout << "Minimum: " << key << endl;
		break;
		case Maximum:
			key = bst->Maximum();
			cout << "Maximum: " << key << endl;
		break;
		case TreeSearchRecursively:
			cout << "Enter key: ";
			cin >> key;
			if(bst->TreeSearchRecursively(key))
				cout << "Found!" << endl;
			else
				cout << "Not found!" << endl;
		break;
		case TreeSearchIteratively:
			cout << "Enter key: ";
			cin >> key;
			if(bst->TreeSearchIteratively(key))
				cout << "Found!" << endl;
			else
				cout << "Not found!" << endl;
		break;
		case TreeSuccessor:
			cout << "Enter key: ";
			cin >> key;
			key = bst->TreeSuccessor(key);
			cout << "Successor: " << key;
		break;
		case TreeDelete:
			cout << "Enter key: ";
			cin >> key;
			bst->TreeDelete(key);
		break;
	}
}