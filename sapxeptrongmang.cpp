#include<stdio.h>	
void nhap(int a[],int x)
{
	for(int i=0;i<x;i++)
	{
		printf("nhap a[%d]",i);
		scanf("%d",&a[i]);	
	}
}
void xuat (int a[],int x)
{
	for(int i=0;i<x;i++)
		printf("\na[%d]=%d",i,a[i]);
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
	printf("\n sau khi sap xep la \n");
	for(int i=0;i<x;i++)
		printf(" %d ",a[i]);
}
int main()
{
	int n;
	int a[100];
	printf("nhap n");scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	sx(a,n);
	return 0;
}
