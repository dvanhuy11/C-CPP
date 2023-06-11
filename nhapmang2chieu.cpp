#include<stdio.h>
void nhapnm(int &n,int &m)
{
	
			printf("nhap so hang va cot =");
			scanf("%d%d",&n,&m);
}
void nhapmang(int a[][100],int x,int y)
{
	for (int i=0;i<x;i++)
		for (int j=0;j<y;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
}
void xuatmang(int a[][100],int x,int y)
{
	
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
			printf(" %d ",a[i][j]);
		printf("\n");
	}	
}	
int tong(int a[][100],int x, int y)
{
	int tong=0;
	for(int i=0;i<x;i++)
		for (int j=0;j<y;j++)
			tong+=a[i][j];
	return tong;
}
int main()
{
	int a[100][100],m,n;
	nhapnm(n,m);
	nhapmang(a,n,m);
	xuatmang(a,n,m);
	printf("tong cac gia tri co trong mang 2 chieu la= %d ",tong(a,n,m));
	return 1;
}
