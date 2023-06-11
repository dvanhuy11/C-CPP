#include <stdio.h>
#include <conio.h>
#define MAX 20
#define VOCUC 1000
#define inputfile "D:\\hutech\\LTDT\\dothi10.txt"

int Sau_Nut[MAX][MAX];
int L[MAX][MAX]; 

typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}dothi;

int ReadMatrix (const char tenfile[100], dothi&g)
{
	FILE *f;
	f = fopen (tenfile, "rt");
	
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
	}
	fscanf (f, "%d", &g.n);
	
	for (int i=0 ; i<g.n ; i++)
		for (int j=0 ; j<g.n ; j++)
			fscanf (f, "%d", &g.a[i][j]);
	fclose (f);
	
	return 1;
}

void Output (dothi g)
{
	printf ("\nTa co ma tran %d dinh.\n", g.n);
	for (int i=0 ; i<g.n ; i++)
	{
		printf ("\t");
		for (int j=0 ; j<g.n ; j++)
			printf ("%4d", g.a[i][j]);
		printf ("\n");
	}
}

void xuatDD (int S, int F)
{
	printf ("[%d]", S);
	int u = S;
	while (Sau_Nut[u][F] != F)
	{
		u = Sau_Nut[u][F];
		printf ("->[%d]", u);
	}
	printf ("->[%d]", F);
}

void Floyd (dothi g)
{
	int i,j;
	for (i=0 ; i<g.n ; i++)
	{
		for (j=0 ; j<g.n ; j++)
		{
			
			if (g.a[i][j] > 0)
			{
				Sau_Nut[i][j] = j;
				L[i][j] = g.a[i][j]; 
			}
			
			else
			{
				Sau_Nut[i][j] = -1;
				L[i][j] = VOCUC; 
			}
		}
	}
	
	for (int k=0 ; k<g.n ; k++)
	{
		for (i=0 ; i<g.n ; i++)
		{
			for (j=0 ; j<g.n ; j++)
			{
				if (L[i][j] > L[i][k] + L[k][j])
				{	 
					L[i][j] = L[i][k] + L[k][j];
					Sau_Nut[i][j] = Sau_Nut[i][k];
				}
			}
		}
	}
	
	int S,F;
	printf ("Nhap dinh bat dau: ");		
	scanf ("%d", &S);
	printf ("Nhap dinh ket thuc: ");	
	scanf ("%d", &F);
	
	if (Sau_Nut[S][F] == -1) 
		printf ("\nKhong co duong di tu %d den %d.", S, F);
		
	else
	{
		printf ("\nDuong di ngan nhat tu %d den %d: ", S, F);
		xuatDD(S,F);
		printf ("\nVoi tong trong so la: %d", L[S][F]);
	}
}

int main()
{
	dothi g;
	if (ReadMatrix (inputfile, g) == 1)
	{
		Output(g);
		Floyd(g);
	}
	return 0;
}

