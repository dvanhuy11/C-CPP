#include<stdio.h>
int TinhTong(int n)
{
	if(n==0)
		return 0;
	printf("\nTinhTongDE(n=%d)",n);
	return n+TinhTong(n-1);
}

int main()
{
	int n;
	int s=0;
	do
	{
		printf("Nhap n = ");
		scanf("%d",&n);
		if(n<=0)
			printf("Nhap sai! Nhap lai!");
	}
	while(n<=0);
	int tong=TinhTong(n);
	printf("\nTong S(n)=1+2+...+n la : %d",tong);
}
