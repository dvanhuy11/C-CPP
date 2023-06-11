#include <stdio.h>
#include <conio.h>
#define MAX 100 
int chuaxet[MAX]; 
int luuvet[MAX];
#dinh van huy 
#2080601470
typedef struct GRAPH
{
	int n; 
	int a[MAX][MAX]; 
}dothi;

struct QUEUE
{
	int size; 
	int array[MAX];
};

void KhoiTaoQueue (QUEUE &Q)
{
	Q.size = 0; 
}

int Push_value_into_Queue (QUEUE &Q, int value)
{
	if (Q.size + 1 >= 100)
		return 0;
	Q.array[Q.size] = value;
	Q.size++;
	return 1;
}

int POP (QUEUE &Q, int &value)
{
	if (Q.size <= 0) 
		return 0; 
		 
	value = Q.array[0];  
	for (int i=0 ; i<Q.size - 1 ; i++) 
		Q.array[i] = Q.array[i+1];
	Q.size--;
	return 1; 
}

int checkQueue(QUEUE Q)
{
	if (Q.size <= 0) 
		return 1;  
	return 0; 
}

int ReadMatrix (const char tenfile[100], dothi&g)
{
	FILE *f;
	f = fopen (tenfile, "rt");
	
	if (f == NULL)
	{
		printf ("\nCannot open file.");
	}
	fscanf (f, "%d", &g.n);
	
	for (int i=0 ; i<g.n ; i++)
	{
		for (int j=0 ; j<g.n ; j++)
		{
			fscanf (f, "%d", &g.a[i][j]);
		}
	}
	fclose (f);
	return 1;
}

void Output (dothi g)
{
	printf ("\nTa co ma tran %d dinh\n", g.n);
	
	for (int i=0 ; i<g.n ; i++)
	{
		printf ("\n");
		for (int j=0 ; j<g.n ; j++)
			printf ("%4d", g.a[i][j]);
	}
}

void BFS (int v, dothi g)
{
	QUEUE Q; 
	KhoiTaoQueue(Q); 
	Push_value_into_Queue (Q,v);
	 
	while (!checkQueue(Q)) 
	{
		POP (Q,v); 
		chuaxet[v] = 1; 
		for (int u=0 ; u<g.n ; u++)
		{ 
			if (g.a[v][u] != 0 && chuaxet[u] == 0)
			{
				Push_value_into_Queue(Q,u); 
					if(luuvet[u]==-1)
					{
						luuvet[u]=v;
					}
			}
		}
	}
}

void xuatDD_DQ (int S, int F)
{
	if (F != S) 
	{
		xuatDD_DQ (S, luuvet[F]);  
		printf ("->"); 
	}
	printf ("%c[%d]", F+'A',F);
}

void duyetBFS (int S, int F, dothi g)
{
	for (int i=0; i<g.n; i++)
	{
		chuaxet[i] = 0; 
		luuvet[i] = -1; 
	}
	BFS (S,g);	
	
	if (chuaxet[F]==1) 
	{
		printf ("\nDuong di tu dinh %d den dinh %d la: ", S, F);
		xuatDD_DQ(S,F); 
	}
	else
		printf ("\nKhong co duong di tu dinh %d den dinh %d ", S, F);
}

int main()
{
	dothi g;	
	int F, S;
    printf("\nTim duong di theo thuat toan Breath-First-Search (BFS)");
    if(ReadMatrix("D:\\hutech\\LTDT\\dothi6.txt",g)==1)
    {
    	Output(g); 
    	printf("\nNhap diem bat dau: ");
    	scanf("%d", &S);
    	printf("\nNhap diem ket thuc: ");
    	scanf("%d", &F);
    	duyetBFS(S, F, g);
	}
		
	return 0;
}

