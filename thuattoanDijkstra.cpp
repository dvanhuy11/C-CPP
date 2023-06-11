#include <stdio.h>
#include <conio.h>
#include<math.h>
#define M 20
#define inf 1000
#define inputfile "D:\\hutech\\LTDT\\dothi1.txt"

int bef[M], uncheck[M], tongts[M];


typedef struct DOTHI{
	int n;
	int a[M][M];
}dt;

int read(const char file[200], dt &g)
{
	FILE *f;
	f = fopen(file,"rt");
	if(f==NULL)
	{
		printf("fail \n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}

void xuatmt(dt g)
{
	printf("So dinh cua do thi la: %d\n",g.n);
	printf("Ma tran ke cua do thi:\n\n");
	for(int i=0;i<g.n;i++)
	{
		printf("\t");
		for(int j=0;j<g.n;j++)
		{
			printf(" %2d ",g.a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int minD (dt g){
	int li = -1;
	float p = inf;
	for (int i=0 ; i<g.n ; i++)
		if (uncheck[i] == 0 && tongts[i] < p)
		{
			p = tongts[i];
			li = i;
		}
	return li;
}

void updateD (int u, dt g)
{
	uncheck[u] = 1;
	for (int v=0; v<g.n; v++)
		if (uncheck[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < inf)
			if (tongts[v] > tongts[u] + g.a[u][v])
			{
				tongts[v] = tongts[u] + g.a[u][v];
				bef[v] = u;
			}
}

void xuat(int S, int F){
	printf ("[%d]", F);
	if (F != S){
		printf ("<-");
		xuat(S, bef[F]);
	}
}

void Dijkstra (int S, int F, dt g)
{
	int i;
	for (i=0 ; i<g.n ; i++)
	{
		bef[i] = -1;
		uncheck[i] = 0;
		tongts[i] = inf;
	}
	tongts[S] = 0;
	while (uncheck[F] == 0)
	{
		int u = minD(g);
		if (u == -1)	
			break;
		updateD(u,g);
	}
	if (uncheck[F] == 1)
	{
		printf ("\nDuong di ngan nhat tu dinh %d den dinh %d la: \n\t", S,F);
		xuat(S,F);
		printf ("\nTong do dai duong di: %d", tongts[F]);
	}
	else
		printf ("\nkKong co duong di", S,F);
}

int main()
{
	dt g;
	if (read(inputfile, g) == 1)
	{
		xuatmt(g);
		int S, F;
		printf("Nhap vao dinh cuoi: ");
		scanf("%d", &F);
		printf("Nhap vao dinh dau: ");
		scanf("%d", &S);
		Dijkstra(S, F, g);
	}
	else
		printf("khong mo duoc file");
	getch();
	return 0;
}
