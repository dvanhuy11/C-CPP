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
//CAU C
void fist(int a[],int x)
{
	int vitri,gt;
	int d=0;
	for(int i=0;i<x;i++)
		if (a[i]>0)
			{
				vitri=i;
				gt=a[i];
				d++;
				break;
			}
	if (d=0)
		printf(" %d \n",a[1]);
	printf("\n vi tri cua phan tu duong dau tien: %d \n",vitri);
	printf("\n gia tri cua phan tu duong dau tien: %d\n",gt);
}
//CAU D
void last(int a[],int x)
{
	int vt1,gt1;
	int d1=0;
	for(int i=x-1;i>=0;i--)
		if (a[i]>0)	
			{
				vt1=i;
				gt1=a[i];
				d1++;
				break;
			}
	printf("\nvi tri cua phan tu duong cuoi cung : %d\n",vt1);
	printf("\ngia tri cua phan tu duong cuoi cung : %d\n",gt1);
}
/*
//CAU E
int max(int a[],int x)
{
	int max=0;
	for(int i=0;i<x;i++)
		if (a[i]>max)
			max=a[i];
	return max;
}*/
// 
int main()
{
	int n;
	int a[1000];
	nhapn(n);
	nhapmang(a,n);
	printf("------MANG SAU KHI NHAP: ");
	xuatmang(a,n);
	printf("\n-------vi tri va gia tri duong dau tien------------\n");
	fist(a,n);
	printf("\n-------vi tri va gia tri duong cuoi cung------------\n");
	last(a,n);
	return 0;
}
