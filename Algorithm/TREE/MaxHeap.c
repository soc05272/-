#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct heap
{
	int heap[MAX_SIZE];
	int heap_size;
}heapType;

heapType* createHeap(); // 공백힙 생성
void insertHeap(heapType *, int); // 삽입연산
void printHeap(heapType *); // 힙 출력
int deleteHeap(heapType*); // 삭제연산

int main(void)
{
	int i, n;

	heapType *h = createHeap();
	insertHeap(h, 99);
	insertHeap(h, 10);
	insertHeap(h, 56);
	insertHeap(h, 78);
	insertHeap(h, 45);
	insertHeap(h, 87);

	printHeap(h);
	
	n = h->heap_size;
	for(i = 1; i <= n; i++)
	{
		printf("%d \n", deleteHeap(h));
	}

	return 0;
}

heapType* createHeap() // 공백힙 생성
{
	heapType *h;
	h = (heapType *)malloc(sizeof(heapType));

	h->heap_size = 0;

	return h;
}

void insertHeap(heapType *h, int item)
{
	int i;

	h->heap_size++;
	if(h->heap_size == MAX_SIZE)
	{
		printf("Heap is Full!!\n");
		return;
	}
	i = h->heap_size;

	// i : item(새 노드)의 위치
	// i/2 : 부모노드의 위치
	// 탐색결과 i에는 item(새 노드)의 삽입위치 저장
	while((i != 1) && (item > h->heap[i/2]))
	{
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}
	
void printHeap(heapType *h) // 힙 출력
{
	int i;
	printf("[MaxHeap : ");
	for(i = 1; i <= h->heap_size; i++)
	{
		printf("%d ", h->heap[i]);
	}printf("]\n");
}

int deleteHeap(heapType* h) // 삭제연산
{
	int parent, child, item, temp;
	
	item = h->heap[1]; // 삭제할 루트의 키값 저장
	temp = h->heap[h->heap_size]; // 마지막 노드의 키값 저장
	h->heap_size--;

	parent = 1;
	child = 2;

	while(child <= h->heap_size)
	{
		if((child < h->heap_size) && (h->heap[child] < h->heap[child+1]))
		{
			child++;
		}
		if(temp >=h->heap[child]) break;
		else
		{
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}

	h->heap[parent] = temp;
	return item;
}
