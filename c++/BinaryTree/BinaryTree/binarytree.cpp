#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *LeftChild, *RightChild;
	TreeNode():data(-1), LeftChild(NULL), RightChild(NULL) {}
};

void CreateTree(TreeNode *&root) {
	int value;
	cout<<"请输入节点数字:";
	cin>>value;
	if (value == -1) {
		root = NULL;
		return;
	} 

	root = new TreeNode;
	root->data = value;
	CreateTree(root->LeftChild);
	CreateTree(root->RightChild);
}

void PreOrderVisit(TreeNode *&root){
	if(root) {
		cout<<root->data<<"\t";
		PreOrderVisit(root->LeftChild);
		PreOrderVisit(root->RightChild);
	}
}

void PostOrderVisit(TreeNode *&root) {
	if(root) {
		PostOrderVisit(root->LeftChild);
		PostOrderVisit(root->RightChild);
		cout<<root->data<<"\t";
	}
}

void InOrderVisit(TreeNode *&root) {
	if (root) {
		InOrderVisit(root->LeftChild);
		cout<<root->data<<"\t";
		InOrderVisit(root->RightChild);
	}
}

void LevelVist(TreeNode *&root) {
	vector<TreeNode *> stack;
	if (!root) {
		return;
	}

	stack.push_back(root);
	int cur = 0;
	int last = 1;
	while(cur < stack.size()) {
		last = stack.size();
		while(cur < last) {
			cout<<stack[cur]->data<<"\t";
			if(stack[cur]->LeftChild) {
				stack.push_back(stack[cur]->LeftChild);
			}
			if(stack[cur]->RightChild) {
				stack.push_back(stack[cur]->RightChild);
			}
			cur++;
		}
		cout<<endl;
	}
}

void main() {
	TreeNode *root;
	CreateTree(root);
	cout<<"前序遍历：";
	PreOrderVisit(root);
	cout<<"\n中序遍历：";
	PostOrderVisit(root);
	cout<<"\n后序遍历：";
	InOrderVisit(root);
	cout<<"\n层序遍历:\n";
	LevelVist(root);
}