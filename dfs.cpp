#include<conio.h>
#include<stdio.h>
#include <cstdlib>
#define MAX 100
#dinh van huy 
#2080601470
typedef struct Graph{
	int n;
	int a[MAX][MAX];
}DOTHI;
struct STACK
{
	int a[MAX];
	int size;
};
int LuuVet[MAX];
	int ChuaXet[MAX];
void khoitaoStack (STACK &s)
{
	s.size=0;
}
void DayGiaTriVaoStack (STACK &s, int value)
{
	if(s.size + 1 >= 100)
		return; 
	s.a[s.size]=value;
	s.size++;
}
int DocMaTranKe(char tenfile[100],DOTHI &g)
{
	FILE *f;
	f=fopen(tenfile," r");
	if(f==NULL)
	{
		printf("khong mo duoc file \n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i =0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void xuatmaTranKe(DOTHI g)
{
	printf("So dinh cua do thi: ");
	printf("%d\n",g.n);
	for(int i=0;i<g.n;i++)
	{
		for(int j=0 ;j<g.n;j++)
			printf("%4d",g.a[i][j]);
		printf("\n");
	}
}
int Doccanh(char tenfile[100],DOTHI &g)
{
	FILE *f;
	int m;
	f=fopen(tenfile,"r");
	if(f==NULL)
	{
		printf("khong mo duoc file \n");
		return 0;
	}
	fscanf(f,"%d %d",&g.n,&m);
	printf("So canh cua do thi %d \n",m);
	int fi,la;
	for(int i=0;i<m;i++)
	{
		fscanf(f,"%d %d",&fi,&la);
		g.a[fi][la]=1;
		g.a[la][fi]=1;
	}
	fclose(f);
	return 1;
}
void DFS(int i,Graph g)
{
	ChuaXet[i]=1;
	for(int j=0;j<g.n;j++)
	{
		if(g.a[i][j]!=0&&ChuaXet[j]==0)
		{
			LuuVet[j]=i;
			DFS(j,g);
		}
	}
}
void duyettheoDFS(int S,int F,Graph g)
{
	int c;
	for(int i=S;i<=F;i++)
		LuuVet[i]=-1;
	for(int j=S;j<=F;j++)
		ChuaXet[j]=0;
	DFS(S,g);
	if(ChuaXet[F]==1)
	{
		printf("Duong di tu dinh %d den dinh %d\n\t",S,F);
		while(F!=-1)
		{
			printf("%5d",F);
			F=LuuVet[F];
		}
	}
	else
		printf("\nKhong co duong di tu %d den dinh %d\n\t",S,F);	
}
struct Queue
{
	int size;
	int array[MAX];
};
void KhoitaoQueue(Queue &Q)
{
	Q.size=0;
}
int DaygiatrivaoQueue(Queue &Q,int value)
{
	if(Q.size+1>=100)
		return 0;
	Q.array[Q.size]=value;
	Q.size++;
	return 1;
}
int LaygiatrirakhoiQueue(Queue &Q,int &value)
{
	if(Q.size<=0)
		return 0;
	value=Q.array[0];
	for(int i=0;i<Q.size-1;i++)
		Q.array[i]=Q.array[i+1];
	Q.size--;
	return 1;
}
int KiemtraQueuerong(Queue Q)
{
	if(Q.size<=0)
		return 1;
	return 0;
}

int main(){
	DOTHI g;
	STACK s;
	int S,F;	
	if(DocMaTranKe("D:\\hutech\\LTDT\\dothi2.txt",g))
	{
			xuatmaTranKe(g);
			printf("\nMoi nhap dinh dau S:  ");
			scanf("%d",&S);
			printf("\nMoi nhap dinh cuoi F:  ");
			scanf("%d",&F);
			printf("Duyet theo DFS: \n");
			duyettheoDFS(S,F,g);
					
	}	
}
