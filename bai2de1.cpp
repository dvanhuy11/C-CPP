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
long tong(int a[][100],int m,int n)
{
	int sum=0;
	for(int i=0;i<m;i++)
	 	for(int j = 0; j < n; j++)
			sum+=a[i][j];
	return sum;	
}
int snt(int x)
{
	if (x<=1)
		return 0;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return 0;
	return 1;
}
int demnt(int a[][100],int m,int n)
{
	int d=0;
	for(int i=0;i<m;i++)
	 	for(int j = 0; j < n; j++)
			if(snt(a[i][j]))
				d++;
	return d;		
}
int max(int a,int b)
{
	int max=a;
		 if(b>max)
		 	max=b;
		else 
			max=a;
	return max;
}
int  maxmin(int a[][100],int b[100],int m)
{
	int j,v;
	int Min,Max=0;
	for(int i=0;i<m;i++)
	{
		j=1;
		Min=a[i][0];
		while(j<m)
		{
			if(a[i][j]<Min)
			{
				Min=a[i][j];
			//	demmin++;
			}
			j++;
		}
//		Min=Max;
		b[i]=Min;
//		v=max(b[i],Max);
//		Max=Min;
	}
	int max1=b[0];
	for(int i=1;i<m;i++)
		if(b[i]>max1)
			max1=b[i];
	return max1;
}
long tongcs(int x)
{
	int t=0,n=x;
	while(n%10!=0)
	{
		n=x%10;
		t+=n;
		x=x/10;
	}
	return t;
}
void change(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	 	for(int j=0;j<n;j++)	
	 		if((a[i][j])>9)
	 			a[i][j]=tongcs(a[i][j]);
	xuat(a,m,n);
}
int main()
{
	int a[100][100],m,n;
	int b[100];
	nhapmn(m,n);
	nhapmang(a,m,n);
	xuat(a,m,n);
	printf("\n TONG CAC PHAN TU=%d",tong(a,m,n));
	printf("\n SO LUONG SO NGUYEN TO:%d",demnt(a,m,n));
	printf("\n GIA TRI LON NHAT CUA CAC DONG:%d",maxmin(a,b,m));
	printf("\n");
	change(a,m,n);
	return 0;
}
