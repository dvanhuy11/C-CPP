#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhapN(int &n)
{
	do
	{
		printf("- Moi ban nhap n = ");
		scanf("%d",&n);
		if(n<=0)
			printf(" MOI BAN NHAP LAI ( n>0 ) !!!\n");
	}while(n<=0);
}
void nhapMang(int n, int *a)
{
	for(int i=0;i<n;i++)
	{
		printf("\tA[%d] = ",i);
		scanf("%d",&*(a+i));
	}
}
int Tong(int *a, int n)
{
	if (n == 1)
		return *(a+0);
	return Tong(a, n-1) + a[n-1];
}
int main()
{
	int n;
	int *a = (int *)malloc(n * sizeof(int *));
	nhapN(n);
	nhapMang(n,a);
	printf("\n");
	printf("- Tong cac phan tu trong mang la = %d \n",Tong(a,n));
	printf("\n");
	return 0;
}
