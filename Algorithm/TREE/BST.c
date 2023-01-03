#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef char element;

typedef struct node
{
	element key;
	struct node* left;
	struct node* right;
}treeNode;

void menu();
treeNode* insertNode(treeNode*, element);
void displayInorder(treeNode*);
void deleteNode(treeNode* , element);
treeNode* searchBST(treeNode*, element);

int main(void)
{
	treeNode* root = NULL;
	int menuNum;
	char key;
	treeNode* fd;

	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');

	while(1)
	{
		menu();
		printf("input menu : ");
		scanf("%d", &menuNum);

		switch(menuNum)
		{
			case 1:
				printf("[트리출력]\n");
				displayInorder(root);
				printf("\n");
				break;
			case 2:
				printf("삽입할 문자를 입력하시오 : ");
				__fpurge(stdin);
				key = getchar(); getchar();
				insertNode(root, key);
				break;
			case 3:
				printf("삭제할 문장을 입력하시오 : ");
				__fpurge(stdin);
				key = getchar(); getchar();
				printf("key : %c\n", key);
				deleteNode(root, key);
				break;
			case 4:
				printf("탐색할 문자를 입력하시오 : ");
				__fpurge(stdin);
				key = getchar(); getchar();
				fd = searchBST(root, key);
				if(fd != NULL)
				{
					printf("%c노드를 찾았습니다!!\n", fd->key);			
					printf("%c의 주소 : %p\n", fd->key, fd);
					printf("왼쪽자식의 key값 : %s\n", fd->left);
					printf("오른쪽자식의 key값 : %s\n", fd->right);

				}
				else printf("%c노드는 존재하지 않습니다!!\n", key);
				break;
			case 5:
				printf("Bye~~\n");
				return 0;
			default:
				printf("메뉴번호를 확인 후 입력해 주세요!!\n");
		}
	}
	return 0;
}

void menu()
{
	printf("===================\n");
	printf("1. 트리 출력\n");
	printf("2. 노드 삽입\n");
	printf("3. 노드 삭제\n");
	printf("4. 노드 탐색\n");
	printf("5. 종료\n");
	printf("===================\n");
}

treeNode* insertNode(treeNode* p, element x)
{
	treeNode* newNode;
	if(p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if(x < p->key)
	{
		p->left = insertNode(p->left, x);
	}
	else if(x > p->key)
	{
		p->right = insertNode(p->right, x);
	}
	else printf("\n이미 같은 키가 있습니다!!\n");

	return p;
}

void displayInorder(treeNode* root)
{
	if(root) // if (root!= NULL)
	{
		displayInorder(root->left);
		printf("%c-", root->key);
		displayInorder(root->right);
	}
}

void deleteNode(treeNode* root, element key)
{
	treeNode* parent, *child, *p, *succ, *succ_parent;

	parent = NULL;
	p = root;

	// 삭제할 노드 탐색하기
	while((p != NULL) && (p->key != key)) // 단말노드 남아있고 원하는 코드 못 찾았을 때까지
	{
		parent = p;
		if(key < p->key) p = p->left;
		else p = p->right;	
	}

	// 삭제할 노드가 존재하지 않을 때
	if(p == NULL)
	{
		printf("삭제하려는 노드가 존재하지 않습니다!!\n");
		return;
	}

	// 삭제할 노드가 단말노드인 경우
	// p : 삭제할 노드
	// parent ; 삭제할 노드의 부모노드
	if((p->left == NULL) && (p->right == NULL))
	{
		if(parent != NULL) // root노드만 존재하는 경우가 아니라면
		{
			if(parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else
		{
			root = NULL;
		}
	}
	
	else if((p->left == NULL) || (p->right == NULL)) // 자식 노드가 하나인 경우, child : 삭제할 노드의 자식노드
	{
		if(p->left != NULL)
		{
			child = p->left;
		}
		else
		{
			child = p->right;
		}
		if(parent != NULL)
		{
			if(parent->left == p)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
		}
		else
		{
			root = child;
		}
	}
	else // 자식노드가 두 개인 경우, succ : 후계자, succ_parent ; 후계자의 부모
	{
		succ_parent = p;
		succ = p->right;
		while(succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		if(succ_parent->left == succ)
		{
			succ_parent->left = succ->left;
		}
		else
		{
			succ_parent->right = succ->left;
		}
		p->key = succ->key;
		p = succ;
	}
	free(p);

}

treeNode* searchBST(treeNode* root, element x)
{
	treeNode *p = root;
	while(p != NULL)
	{
		if(x < p->key) p = p->left;
		else if(x == p->key) return p;
		else p = p->right;


		/*if(p->left == NULL)
		{	
			printf("왼쪽자식의 key값 : NULL\n");
			printf("오른쪽자식의 key값 : %c\n", p->right);
		}
		else if(p->right == NULL)
		{
			printf("왼쪽자식의 key값 : %c\n", p->left);
			printf("오른쪽자식의 key값 : NULL\n");
		}
		else if((p->left == NULL) && (p->right = NULL))
		{
			printf("왼쪽자식의 key값 : NULL\n");
			printf("오른쪽자식의 key값 : NULL\n");
		}*/
	}	
	
	printf("찾는 키가 없습니다!!\n");
	//printf("왼쪽자식의 key값 : NULL\n");
	//printf("오른쪽자식의 key값 : NULL\n");
	return p;
}
