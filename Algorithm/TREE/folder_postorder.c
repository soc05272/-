#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	int size;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

int folderSize = 0;

treeNode* makeRootNode(int, treeNode*, treeNode*); // 노드를 생성
int postorder_FolderSize(treeNode*); // 후위순회를 이용한 폴더용량 계산

int main(void)
{
	treeNode* F11 = makeRootNode(120, NULL, NULL);
	treeNode* F10 = makeRootNode(55, NULL, NULL);
	treeNode* F9 = makeRootNode(100, NULL, NULL);
	treeNode* F8 = makeRootNode(200, NULL, NULL);

	treeNode* F7 = makeRootNode(68, F10, F11);
	treeNode* F6 = makeRootNode(40, NULL, NULL);
	treeNode* F5 = makeRootNode(15, NULL, NULL);
	treeNode* F4 = makeRootNode(2, F8, F9);

	treeNode* F3 = makeRootNode(10, F6, F7);
	treeNode* F2 = makeRootNode(0, F4, F5);

	treeNode* F1 = makeRootNode(0, F2, F3);

	printf("F4의 용량은 : %d\n", postorder_FolderSize(F4));
	folderSize = 0;
	printf("F3의 용량은 : %d\n", postorder_FolderSize(F3));
	folderSize = 0;
	
	printf("F1의 용량은 : %d\n", postorder_FolderSize(F1));
	folderSize = 0;

	return 0;
}

treeNode* makeRootNode(int size, treeNode* left, treeNode* right) // 노드를 생성
{
	treeNode* root = (treeNode* ) malloc(sizeof(treeNode));
	root->size = size;
	root->left = left;
	root->right = right;

	return root;
}

int postorder_FolderSize(treeNode* root) // 후위순회를 이용한 폴더용량 계산
{
	if(root)
	{
		postorder_FolderSize(root->left);
		postorder_FolderSize(root->right);
		folderSize += root->size;
	}
	return folderSize;
}
