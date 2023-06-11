#include <stdio.h>
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void nhapmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		{
			printf("a[%d]",i);
			scanf("%d",&a[i]);
		}
}
void xuatmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",a[i]);
}
void sx(int a[],int x)
{
	int t;
	for(int i=0;i<x-1;i++)
		for(int j=i+1;j<x;j++)
			if(a[i]>a[j])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;		
			}
	printf("\n MANG SAU KHI SAP XEP: ");
	xuatmang(a,x);
}
int main()
{
	int a[1000];
	int n;
	nhapn(n);
	nhapmang(a,n);
	xuatmang(a,n);
	sx(a,n);
	return 0;
}
