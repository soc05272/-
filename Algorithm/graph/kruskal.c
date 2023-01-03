#include <stdio.h>
#define MAX_VER 15
#define MAX_EDGE 30

typedef struct edge
{
	int s, d, w;
}EDGE;

typedef struct vertex
{
	int p, rank;
}VT;

VT vt[MAX_VER];
EDGE e[MAX_EDGE];

void mst_kruskal(int, int);
void make_set(int);
void connect(int, int);
int find_set(int);
void sort_edge(int);

int main(void)
{
	int nv = 7; // 정점 수
	int ne = 11; // 간선 수

	// input edge
	// A-B
	e[0].s = 0;
	e[0].d = 1;
	e[0].w = 3;
	
	// A-C
	e[1].s = 0;
	e[1].d = 2;
	e[1].w = 17;

	// A-D
	e[2].s = 0;
	e[2].d = 3;
	e[2].w = 6;
	
	// B-D
	e[3].s = 1;
	e[3].d = 3;
	e[3].w = 5;
	
	// B-G
	e[4].s = 1;
	e[4].d = 6;
	e[4].w = 12;
	
	// C-E
	e[5].s = 2;
	e[5].d = 4;
	e[5].w = 10;
	
	// C-F
	e[6].s = 2;
	e[6].d = 5;
	e[6].w = 8;
	
	// D-E
	e[7].s = 3;
	e[7].d = 4;
	e[7].w = 9;
	
	// E-F
	e[8].s = 4;
	e[8].d = 5;
	e[8].w = 4;
	
	// E-G
	e[9].s = 4;
	e[9].d = 6;
	e[9].w = 2;

	// F-G
	e[10].s = 5;
	e[10].d = 6;
	e[10].w = 14;

	// kruskal start
	mst_kruskal(nv, ne);

	return 0;		
}

// make_set : 각 정점별로 1개의 set을 배정
void make_set(int v)
{
	vt[v].p = v;
	vt[v].rank = 0;
}

// find_set : 정접이 특정 대표 set의 원소로 포함된 경우 대표 set을 탐색
int find_set(int v)
{
	if(vt[v].p != v) vt[v].p = find_set(vt[v].p);
	return vt[v].p;	
}

// conmnect :  두 개 이상의 원소를 가진 set을 통합
void connect(int v, int u)
{
	v = find_set(v);
	u = find_set(u);

	// 두 정점 v와 u를 비교해서 rank가 큰 쪽으로ㅓ통합
	if(vt[v].rank > vt[u].rank) vt[u].p = v;
	else
	{
		vt[v].p = u;

		if(vt[v].rank == vt[u].rank)
		{
			vt[u].rank++;
		}
	}

	
}

void mst_kruskal(int nv, int ne)
{
	int total = 0;

	// 각 정점별 set을 생성
	for(int i = 0; i < nv; i++)
	{
		make_set(i);
	}

	// edge를 오름차순으로 정렬
	sort_edge(ne);

	printf("========= kruskal result =========\n");
	for(int i = 0; i < ne; i++)
	{
		// 두 정점의 대표 set이 같지 않은지 검사(사이클 형상 방지)
		if(find_set(e[i].s) != find_set(e[i].d))
		{
			// 2개의 대표 set을 통합
			connect(e[i].s, e[i].d);
			total += e[i].w;
			printf("%c-%c(%d), total weight : %d\n", e[i].s+65, e[i].d+65, e[i].w, total);

		}
	}
	printf("====================================\n");
}

// edge를 오름차순으로 연결
void sort_edge(int ne)
{
	EDGE temp;

	for(int i = 0; i < ne-1; i++)
	{
		for(int j = i+1; j < ne; j++)
		{
			if(e[i].w > e[j].w)
			{
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}
		}
	}

	// sort result
	printf("================== EDGE ===============\n");
	for(int i = 0; i < ne; i++)
	{
		printf("%c-%c(%d)\n",e[i].s+65, e[i].d+65, e[i].w);
	}
	printf("=======================================\n");
}
