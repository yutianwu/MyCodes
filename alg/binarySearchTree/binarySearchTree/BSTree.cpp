#include <iostream>
using namespace std;

struct BSTreeNode {
	BSTreeNode(int k=0, BSTreeNode *p = NULL, BSTreeNode *l = NULL, BSTreeNode *r = NULL) : key(k), parent(p), left(l), right(r) {}
	
	int key;
	BSTreeNode *parent;
	BSTreeNode *left;
	BSTreeNode *right;
};

//树的插入操作
void treeInsert(BSTreeNode* &root, int key) {
	BSTreeNode *x = root;
	BSTreeNode *y = NULL;
	
	while (x != NULL) {
		y = x;
		if (key < x->key) {
			x = x->left;
		} else {
			x = x->right;
		}
	}

	BSTreeNode *z = new BSTreeNode(key);
	z->parent = y;

	if (y == NULL) {
		root = z;	
	} else if (key < y->key) {
		y->left = z;
	} else {
		y->right = z;
	}

	//return root;
}

//中序遍历 递归实现
void inOderTreeWalk (BSTreeNode *root) {
	if (root != NULL) {
		inOderTreeWalk(root->left);
		cout << root->key <<endl;
		inOderTreeWalk(root->right);
	}
}

//搜索树 递归实现
BSTreeNode *search(BSTreeNode *root, int key) {
	if (root == NULL || root->key == key) {
		return root;
	}

	if (key < root->key) {
		return search(root->left, key);
	} else {
		return search(root->right, key);
	}
}

//返回树的最小节点
BSTreeNode *minimum(BSTreeNode *root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

//返回最大的节点
BSTreeNode *maximum(BSTreeNode *root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

//返回节点的后继
BSTreeNode *successor(BSTreeNode *x) {
	if (x->right != NULL) {
		return minimum(x->right);
	}

	BSTreeNode *y = x->parent;
	while (y != NULL && y->right == x) {
		x = y;
		y = y->parent;
	}
	return y;
}

//返回节点的前驱
BSTreeNode *predecessor(BSTreeNode *x) {
	if (x->left != NULL) {
		return maximum(x->left);
	} 
	BSTreeNode *y = x->parent;
	while (y != NULL && y->left == x) {
		x = y; 
		y = y->parent;
	}
	return y;
}

void main() {
	BSTreeNode *root = NULL;
	treeInsert(root, 5);
	treeInsert(root, 3);
	treeInsert(root, 1);
	treeInsert(root, 6);
	treeInsert(root, 7);
	
	cout<<"中序遍历"<<endl;
	inOderTreeWalk(root);
	
	BSTreeNode *res = search(root, 10);
	if (res == NULL) {
		cout<<"没有结果！"<<endl;
	} else {
		cout << "搜索结果"<<res->key<<endl;
	}
	
	system("PAUSE");
}
