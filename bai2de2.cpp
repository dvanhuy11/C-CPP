#include<stdio.h>
#include<math.h>
void nhapmn(int &m,int &n)
{
	printf("NHAP DONG:");
	scanf("%d",&m);
	printf("NHAP COT:");
	scanf("%d",&n);
}
void nhapmang(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				{
					printf("a[%d][%d]",i,j);
					scanf("%d",&a[i][j]);
				}
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
long tongc(int a[][100],int m,int n)
{
	int sum=0;
	for (int i = 0; i < m; i++) 
		{
     		 for (int j = 0; j < n; j++) 
       			  if (i == j)
          			  sum = sum + a[i][j];
   		}
   return sum;
}
long tongp(int a[][100],int m,int n)
{
	int i,j,tong=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-i)
			{
				tong+=a[i][j];
			}
		}
	}
	return tong;
}
int max(int a[][100],int m,int n)
{
	int max=a[0][0];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]>max)
				max=a[i][j];
	return max;
}	
int demmax(int a[][100],int m,int n)
{
	int d=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(max(a,n)==a[i][j])
				d++;
	return d;
}
int tc(int a[][100], int m, int k)
{
	int sum=0;
	for (int i=0; i<=m;i++) 
		sum+= a[i][k];
	return sum;
}
long td(int a[][100], int n,int x)
{
	int sum1=0;
	for(int j=0;j<n;j++)
		sum1=sum1+a[x][j];
	return sum1;
}
long tongtren(int a[100][100],int n)
{
	int tong=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if((i>j)&& a[i][j]!=0)
				tong=tong+a[i][j];
	return tong;
}
int tongduoi(int a[100][100],int n)
{
	int tong1=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i<j && a[i][j]!=0)
				tong1=tong1+a[i][j];
	return tong1;
}
int main()
{
	int n,m,a[100][100];
	nhapmn(m,n);
	nhapmang(a,m,n);
	printf("\n max:%d ",max(a,m,n));
	printf("\n tongc:%d",tongc(a,m,n));
	printf("\n tongp:%d",tongp(a,m,n));
	for(int k=0;k<m;k++)
		printf("\n tongd:%d ",td(a,m,k));
	for(int x=0;x<n;x++)
		printf("\n tongc:%d ",tc(a,n,x));
	printf("\n tongt:%d ",tongtren(a,n));
	printf("\n tongd:%d ",tongduoi(a,n));
	return 0;
}
