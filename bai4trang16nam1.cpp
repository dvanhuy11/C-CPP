#include<stdio.h>
#include<conio.h>
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
void xuatdongk(int a[][100],int x,int k)
{
	do
	{
		printf("\nnhap dong k=");
		scanf("%d",&k);	
	}while (k<0 || k>x-1);
	printf("CAC PHAN TU TREN DONG THU %d la: ",k);
	for (int j=0; j<=x; j++) // cho nay neu cho j<x thi bi mat so cuoi
		printf(" %d ",a[k][j]);
}
int tongcot(int a[][100], int m, int k)
{
	int sum=0;
	for (int i=0; i<=m;i++) // cho nay neu cho i<m thi no khong tinh so cuoi
		sum+= a[i][k];
	return sum;
}
void sumrow(int a[][100],int m,int k )
{
	do
	{
		printf("\nnhap cot k=");
		scanf("%d",&k);	
	}while (k<0 || k>=m);
	printf("\nTONG CAC PHAN TU TREN COT %d la: %d",k,tongcot(a,m,k));
	
}
int GTLN(int a[][100], int m, int n)
{
   int max = a[0][0];
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(a[i][j]>max)
            max = a[i][j];
   return max;
}
int main()
{
	int a[100][100],m,n,dem,k;
	float tbc,tbcd;
	nhapnm(n,m);
	nhapmang(a,n,m);
	xuatmang(a,n,m);
	tbc=(float)tong(a,n,m) / (n*m);
	tbcd=(float)tong(a,n,n) / (demduong(a,n,m));
	printf("TONG CAC GIA TRI CO TRONG MA TRAN= %d ",tong(a,n,m));
	printf("\nTRUNG BINH CONG CUA CAC PHAN TU TRONG MA TRAN= %.2f",tbc);
	printf("\nTRUNG BINH CONG CUA CAC PHAN TU DUONG: %.2f",tbcd);
	xuatdongk(a,n,k);
	sumrow(a,m,k);
	printf("\nGIA TRI LON NHAT TRONG MA TRAN: %d",GTLN(a,n,m));
	getch();
}
