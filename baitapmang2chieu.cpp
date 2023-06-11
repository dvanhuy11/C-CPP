#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void nhapmn(int &m,int &n)
{
	printf("NHAP DONG:");
	scanf("%d",&m);
	printf("NHAP COT:");
	scanf("%d",&n);
}
void random(int a[][100],int m,int n)
{
    int i,j;
    srand(time(NULL));
    for (i=0;i<m;i++)
      for(j=0;j<n;j++)
          a[i][j]=rand()%100;
}
void xuat(int a[][100], int m, int n)
{
   for(int i = 0; i < m; i++)
   {
      for(int j = 0; j < n; j++)
         printf("%d\t", a[i][j]);
      printf("\n");
   }
}
int Min(int a[][100], int m, int n)
{
	int min=a[0][0];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j]<min)
				min=a[i][j];
	return min;
}
long tong(int a[][100], int m, int n)
{
	int sum=0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j]%3==0)
				sum+=a[i][j];
	return sum;
}
float tbc(int a[][100], int m, int n)
{
	float tb;
	tb=(1.0)*tong(a,m,n) / (m*n);
	return tb;
}
void nhapx(int &x)
{
	printf("\n CHO SO NGUYEN X=");
	scanf("%d",&x);
}
void check(int a[][100], int m, int n,int x)
{
	int kt=0;
	nhapx(x);
	for(int i = 0; i < m; i++)
		{
	
			for(int j = 0; j < n; j++)
				if(a[i][j]==x)
					{
						printf(" VI TRI DONG CO CHUA GIA TRI X LA: %d",i);
						kt++;
					}
			break;
		}
	if (kt==0)
		printf(" -1 ");
}
int main()
{
	int m,n,x;
	int a[100][100];
	nhapmn(m,n);
	random(a,m,n);
	xuat(a,m,n);
	printf("\n GIA TRI BE NHAT TRONG MA TRAN LA: %d",Min(a,m,n));
	printf("\n TRUNG BINH CONG CAC PHAN TU CHIA HET CHO 3: %.2f",tbc(a,m,n));
	check(a,m,n,x);
	return 0;
}
