#include <cstddef>
#include "TreeNode.cpp"

#include <iostream>
using namespace std;

class BST {
	public:
		void Insert(int key) {
			TreeNode *z = new TreeNode();
			z->key = key;
			this->Insert(z);
		}
		void InorderTreeWalk() {
			this->InorderTreeWalk(this->root);
		}
		void PreorderTreeWalk() {
			this->PreorderTreeWalk(this->root);
		}
		void PostorderTreeWalk() {
			this->PreorderTreeWalk(this->root);
		}
		int Minimum() {
			TreeNode *min = this->Minimum(this->root);
			return min->key;
		}
		int Maximum() {
			TreeNode *max = this->Maximum(this->root);
			return max->key;
		}
		bool TreeSearchRecursively(int key) {
			if(this->TreeSearchRecursively(this->root, key) != NULL)
				return true;
			return false;
		}
		bool TreeSearchIteratively(int key) {
			if(this->TreeSearchIteratively(this->root, key) != NULL)
				return true;
			return false;
		}
		int TreeSuccessor(int key) {
			TreeNode *x = TreeSearchIteratively(this->root, key);
			x = TreeSuccessor(x);
			return x->key;
		}
		void TreeDelete(int key) {
			TreeNode *z = TreeSearchIteratively(this->root, key);
			TreeDelete(z);
		}
	
	private:
		TreeNode *root;
		
		void Insert(TreeNode *z) {
			TreeNode *y = NULL,
				*x = this->root;
				
			while(x != NULL) {
				y = x;
				if(z->key < x->key) 
					x = x->left;
				else
					x = x->right;
			}
			
			z->parent = y;
			
			if(y == NULL)
				this->root = z;
			else {
				if(z->key < y->key)
					y->left = z;
				else
					y->right = z;
			}
		}
		void InorderTreeWalk(TreeNode *x) {
			if(x != NULL) {
				InorderTreeWalk(x->left);
				cout << x->key << endl;
				InorderTreeWalk(x->right);
			}
		}
		void PreorderTreeWalk(TreeNode *x) {
			if(x != NULL) {
				cout << x->key << endl;
				PreorderTreeWalk(x->left);
				PreorderTreeWalk(x->right);
			}
		}
		void PostorderTreeWalk(TreeNode *x) {
			if(x != NULL) {
				PostorderTreeWalk(x->left);
				PostorderTreeWalk(x->right);
				cout << x->key << endl;
			}
		}
		TreeNode *Minimum(TreeNode *x) {
			while(x->left != NULL)
				x = x->left;
			return x;
		}
		TreeNode *Maximum(TreeNode *x) {
			while(x->right != NULL)
				x = x->right;
			return x;
		}
		TreeNode *TreeSearchRecursively(TreeNode *x, int key) {
			if(x == NULL)
				return NULL;
			if(x != NULL && key == x->key)
				return x;
			
			if(key < x->key)
				return TreeSearchRecursively(x->left, key);
			else 
				return TreeSearchRecursively(x->right, key);
		}
		TreeNode *TreeSearchIteratively(TreeNode *x, int key) {
			while(x != NULL && key != x->key) {
				if(key < x->key)
					x = x->left;
				else
					x = x->right;
			}
			
			return x;
		}
		TreeNode *TreeSuccessor(TreeNode *x) { 
			TreeNode * y;					
			if(x->right != NULL)
				return Minimum(x->right);
			else {
				y = x->parent;
				while(y != NULL && x == y->right) {
					x = y;
					y =  y->parent;
				}
			}
			
			return y;
		}
		void TreeDelete(TreeNode *z) {
										
			TreeNode *y, *x;
			
			if(z->left == NULL || z->right == NULL) 
				y = z;
			else
				y = TreeSuccessor(z);
			
			if(y->left != NULL)
				x = y->left;
			else
				x = y->right;
			
			if(x != NULL)
				x->parent = y->parent;
			
			if(y->parent == NULL)
				this->root = x;
			else {
				if (y == y->parent->left)
					y->parent->left = x;
				else
					y->parent->right = x;
			}
			if(y != z) {
				z->key = y->key;
				if(y->left != NULL)
					z->left = y->left;
				if(y->right != NULL)
					z->right = y->right;
				if(y->parent != NULL)
					z->parent = y->parent;
			}
		}
};