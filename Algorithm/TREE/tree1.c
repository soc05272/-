#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct node
{
	element data;
	struct node* left;
	struct node* right;
}treeNode;

treeNode* makeRootNode(element, treeNode*, treeNode*); // 노드를 생성

void preorder(treeNode*); // 전위순회, PLR
void inorder(treeNode*); // 중위순회, LPR
void postorder(treeNode*); // 후위순회, LRP

int main(void)
{
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("preorder : ");
	preorder(n1);
	printf("\n");

	printf("inorder : ");
	inorder(n1);
	printf("\n");

	printf("postorder : ");
	postorder(n1);
	printf("\n");
	return 0;
}


treeNode* makeRootNode(element data, treeNode* left, treeNode* right)
{
	treeNode* root;

	root = (treeNode* )malloc(sizeof(treeNode));
	root->data = data;
	root->left = left;
	root->right = right;

	return root;
}


void preorder(treeNode* root) // 'P'LR
{
	if(root) // if(root != NULL)
	{
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void inorder(treeNode* root) // L'P'R
{
	if(root) // if(root != NULL)
	{
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}


void postorder(treeNode* root) // LR'P'
{
	if(root) // if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}
