#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
	int size;
	char name[10];
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

int folderSize = 0;

treeNode* makeRootNode(int, char *, treeNode*, treeNode*); // 노드를 생성
int postorder_folderSize(treeNode*); // 후위순회를 이용한 폴더용량 계산

int main(void)
{
	treeNode* F11 = makeRootNode(120, "F11", NULL, NULL);
	treeNode* F10 = makeRootNode(55, "F10", NULL, NULL);
	treeNode* F9 = makeRootNode(100, "F9", NULL, NULL);
	treeNode* F8 = makeRootNode(200, "F8", NULL, NULL);

	treeNode* F7 = makeRootNode(68, "F7", F10, F11);
	treeNode* F6 = makeRootNode(40, "F6", NULL, NULL);
	treeNode* F5 = makeRootNode(15, "F5", NULL, NULL);
	treeNode* F4 = makeRootNode(2, "F4", F8, F9);

	treeNode* F3 = makeRootNode(10, "F3", F6, F7);
	treeNode* F2 = makeRootNode(0, "F3", F4, F5);

	treeNode* F1 = makeRootNode(0, "F1", F2, F3);

	printf("%s의 용량은 : %d\n", F4->name, postorder_folderSize(F4));
	folderSize = 0;
	printf("%s의 용량은 : %d\n", F3->name, postorder_folderSize(F3));
	folderSize = 0;

	return 0;
}

treeNode* makeRootNode(int size, char* name, treeNode* left, treeNode* right) // 노드를 생성
{
	treeNode* root = (treeNode* ) malloc(sizeof(treeNode));
	root->size = size;
	strcpy(root->name, name);
	root->left = left;
	root->right = right;

	return root;
}

int postorder_folderSize(treeNode* root) // 후위순회를 이용한 폴더용량 계산
{
	if(root)
	{
		postorder_folderSize(root->left);
		postorder_folderSize(root->right);
		printf("%s(%d)\n", root->name, root->size);
		folderSize += root->size;
	}
	return folderSize;
}
