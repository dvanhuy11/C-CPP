#include<stdio.h>
void NhapMang(int a[], int &n)
{
	do
	{
		printf("Nhap n = ");
		scanf("%d",&n);
		if(n<=0)		
			printf("Nhap sai! Nhap lai!");
	}
	while(n<=0);
	for(int i=0;i<n;i++)
	{
		printf("Nhap a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}

int Tong(int a[], int n)
{
	if (n == 1)
		return a[0];
	return Tong(a, n-1) + a[n-1];
}

int main()
{
	int n;
	int a[100];
	NhapMang(a,n);
	int tong=Tong(a,n);
	printf("\nTong cac phan tu trong mang la : %d",tong);
}
