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
int demduong(int a[][100],int x, int y)
{
	int d=0;
	for(int i=0;i<x;i++)
		for (int j=0;j<y;j++)
			if(a[i][j]>0)
				d++;
	return d;
}
int main()
{
	int a[100][100],m,n,dem;
	float tbc,tbcd;
	nhapnm(n,m);
	nhapmang(a,n,m);
	xuatmang(a,n,m);
	tbc=(float)tong(a,n,m) / (n*m);
	tbcd=(float)tong(a,n,n) / (demduong(a,n,m));
	printf("TONG CAC GIA TRI CO TRONG MA TRAN= %d ",tong(a,n,m));
	printf("\nTRUNG BINH CONG CUA CAC PHAN TU TRONG MA TRAN= %.2f",tbc);
	printf("\nTRUNG BINH CONG CUA CAC PHAN TU DUONG: %.2f",tbcd);
	return 1;
}
