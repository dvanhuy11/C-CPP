#include <stdio.h>
#define MAX 100;
//CAU A
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
//CAU B
void xuatmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",a[i]);
}
int tongam(int a[], int x)
{
	
	if(x==0)
		return a[0];
	if (a[x]<0)
		return tongam(a,x-1)+a[x];
	return tongam(a,x-1)+0;
}
int main()
{
	int a[100];
	int n;
	nhapn(n);
	nhapmang(a,n);
	xuatmang(a,n);
	printf("\n%d",tongam(a,n-1));
	return 0;
}
