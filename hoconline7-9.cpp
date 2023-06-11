#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
void nhapmn(int &m,int &n)
{
	printf("NHAP DONG:");
	scanf("%d",&m);
	printf("NHAP COT:");
	scanf("%d",&n);
}
void random(int a[][100],int m,int n)
{
	srand(time(NULL));
	for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
					a[i][j]=rand()%20;
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
bool snt(int x)
{
	if (x<=1)
		return false;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return false;
	return true;
}
bool scp(int n){
    int sqr = sqrt(n);
    return (sqr*sqr == n);
}
void swap(int &x,int &y)
{
	int t=x;
	x=y;
	y=t;
}
void sxsnt(int a[][100],int m,int n)
{
	for(int k=0;k<m;k++)
	{
		for(int i=0;i<n-1;i++)// phai la n-1 chu khong phai m-1 vi neu dung m-1 thi chi tinh toi cot m-1 thoi
			for(int j=i+1;j<n;j++)
				if(((a[k][i])>(a[k][j])) && (snt(a[k][i]) && snt(a[k][j])))
					swap(a[k][i],a[k][j]);
	}
	printf("\n");
	xuat(a,m,n);
}
void sxscp(int a[][100],int m,int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<m-1;i++)
			for(int j=i+1;j<n;j++)
				if(((a[k][i])>(a[k][j])) && (scp(a[k][i]) && scp(a[k][j])))
					swap(a[k][i],a[k][j]);
	}
	printf("\n");
	xuat(a,m,n);
}
void sxd(int a[][100],int m,int n)
{
	for(int k=0;k<m;k++)
	{
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				if((a[k][i])>(a[k][j])) 
					swap(a[k][i],a[k][j]);
	}
	printf("\n");
	xuat(a,m,n);
}
int main()
{
	int n,m,a[100][100];
	nhapmn(m,n);
	random(a,m,n);
	xuat(a,m,n);
	printf("MANG SAU KHI SAP XEP:");
	sxd(a,m,n);
	//sxsnt(a,m,n);
	//sxscp(a,m,n);
	return 0;
}
