#include<stdio.h>
#include<conio.h> 
#define MAX 100
typedef struct DOTHI
{
	int n;
	int a[MAX][MAX]; 
};
void Xuat(DOTHI g)
{
	printf("So dinh cua do thi la %d\n", g.n); 
	printf("\nMa tran ke cua do thi la:\n");
		for (int i = 0; i < g.n; i++)
		{
			printf ("\t");
			for (int j = 0; j < g.n; j++)
				printf("%d ",g.a[i][j]);
			printf("\n");
		}
}
int Empty(DOTHI g)
{
	int i;
	for (i=0; i<g.n; i++)
	{
		if (g.a[i][i] != 0) 
		return 0;
	}
	return 1;
}
int main()
{
	DOTHI g;
	FILE *f; 
	f = fopen("D:\\hutech\\LTDT\\dothi1.txt", "rt");
	if (f == NULL) 
		printf("Khong mo duoc file\n");
 	fscanf(f, "%d", &g.n); 
	for (int i=0; i<g.n; i++)
	{
		for (int j=0; j<g.n; j++)
			fscanf(f, "%d", &g.a[i][j]); 
	}	
	Xuat(g);
	if(Empty(g)==1)
		printf("\nMA TRAN HOP LE");
	else 
		printf("\nMA TRAN KHONG HOP LE");
	return 0;
}
