#include<stdio.h>
#define MAX 100
struct GRAPH
{
	int a[MAX][MAX];
	int n;
};
void init(GRAPH *g,int n)
{
	int i,j;
	g->n=n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->a[i][j]=0;
}
void add_edge(GRAPH *g,int x,int y)
{
	g->a[x][y]=1;
	g->a[y][x]=1;
}
int adjacent(GRAPH *g,int x,int y)
{
	return (g->a[x][y]!=0);
}
int degree(GRAPH *g,int x)
{
	int deg=0,i;
	for(i=1;i<=g->n;i++)
		if(adjacent(g,i,x))
			deg++;
	return deg;
}
struct LIST
{
	int data[MAX];
	int size;
};
void make_null(LIST *l)
{
	l->size=0;
}
void PUSHback(LIST *l,int x)
{
	l->data[l->size]=x;
	l->size ++;
}
int element_at(LIST *l,int i)
{
	return l->data[i-1];
}
LIST neigbors(GRAPH *g,int x)
{
	LIST l;
	make_null(&l);
	int i;
	for(i=1;i<=g->n;i++)
		if(g->a[i][x]==1)
			PUSHback(&l,i);
	return l;
}
struct STACK
{
	int data[MAX];
	int size;
};
void make_nullstack(STACK *l)
{
	l->size=0;
}
void PUSHstack(STACK *l,int x)
{
	l->data[l->size]=x;
	l->size ++;
}
int top(STACK *stack)
{
	return stack->data[stack->size -1];
}
void pop(STACK *stack){ 
	stack->size--;
}
int empty_stack(STACK *stack)
{
	return stack->size == 0;
}
LIST DFS(GRAPH *g,int x)
{
	STACK s;
	make_nullstack(&s);
	PUSHstack(&s,x);
	int duyet[MAX];
	LIST list_dfs;
	make_null(&list_dfs);
	for(int i=1;i<=g->n;i++)
		duyet[i]=0;
	while(!empty_stack(&s))
	{
		int u=top(&s);
		pop(&s); 
		if(duyet[u]==1)
			continue;
		PUSHback(&list_dfs,u);
		duyet[u]=1;
		LIST list=neigbors(g,u);
		for(int i=1;i<=list.size;i++)
			{
				int v=element_at(&list,i); 
				if(duyet[v]==0)
					PUSHstack(&s,v);
			}
	}
	return list_dfs;
}
int main()
{
	GRAPH g;
	FILE *f1;
	int n,m;
	f1=fopen("D:\\CODE\\DFS.inp.txt","rt");
	fscanf(f1,"%d %d",&n,&m);
	init(&g,n);
	int u,v,e;
	for(e=1;e<=m;e++)
		{
			fscanf(f1,"%d %d",&u,&v);
			add_edge(&g,u,v);
		}
	int duyetFULLdothi[MAX];
	for(int i=1;i<g.n;i++)
		duyetFULLdothi[i]=0;
	for(int i=1;i<g.n;i++)
	{
		if(duyetFULLdothi[i]==0)
			{
				LIST dfs=DFS(&g,i);
				for(int j=1;j<=dfs.size;j++)
				{
					int k=element_at(&dfs,j);
					printf(" %d ",k);
					duyetFULLdothi[k]=1;
				}
			}
	}
	fclose(f1);
	return 0;
}
