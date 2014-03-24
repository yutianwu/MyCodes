#include <iostream>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	char val;
};

void ReBuild(char *preOrder, char *inOrder, int treeLen, Node **root) {
	if (preOrder == NULL || inOrder == NULL) {
		return;
	}

	Node *nTemp = new Node();
	nTemp->val = *preOrder;
	nTemp->left = NULL;
	nTemp->right = NULL;
	if (*root == NULL) {
		*root = nTemp;
	}
	if (treeLen == 1) {
		return;
	}
	
	char *orgInOrder = inOrder;
	char *leftEnd = inOrder;
	int tempLen = 0;

	while (*preOrder != *leftEnd) {
		if (preOrder == NULL || leftEnd == NULL) {
			return;
		}
		tempLen++;
		if (tempLen > treeLen) {
			break;
		}
		leftEnd++;
	}

	int leftLen = (int) (leftEnd - orgInOrder);
	int rightLen = treeLen - leftLen - 1;
	if (leftLen > 0) {
		ReBuild(preOrder + 1, inOrder, leftLen, &((*root)->left));
	}
	if (rightLen > 0) {
		ReBuild(preOrder + leftLen + 1, inOrder + leftLen + 1, rightLen, &((*root)->right));
	}
}
void main() {
	char preOrder[6] = {'a', 'b', 'd', 'c', 'e', 'f'};
	char inOrder[6] = {'d', 'b', 'a', 'e', 'c', 'f'};
	Node *root = NULL;
	ReBuild(preOrder, inOrder, 6, &root);
}