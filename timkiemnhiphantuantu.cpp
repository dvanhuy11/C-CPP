#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void nhapn(int &n)
{
	do
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void random(int a[],int n)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
		a[i]=rand()%100;
}
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf(" %d ",a[i]);
}
int tuantu(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return i;
	return -1;
}
void sx(int a[],int n)
{
	int t=0;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
	xuat(a,n);
}
int nhiphan(int a[],int n,int x)
{
	int l=0;
	int r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]<x)
			l=mid+1;
		else
			r=mid-1;
	}
		return -1;
}
int main()
{
	int a[100],n,x;
	nhapn(n);
	random(a,n);
	xuat(a,n);
	printf("\nnhap X=");
	scanf("%d",&x);
	if(tuantu(a,n,x)==-1)
		printf("\nKHONG TIM THAY");
	else
		printf("\nTUAN TU=>>> VI TRI %d = a[%d] la %d\n",x,tuantu(a,n,x),tuantu(a,n,x));
	sx(a,n);
	if(nhiphan(a,n,x)==-1)
		printf("\nKHONG TIM THAY");
	else
		printf("\nNHI PHAN=>>>VI TRI %d = a[%d] la %d",x,nhiphan(a,n,x),nhiphan(a,n,x));
	return 1;
}
