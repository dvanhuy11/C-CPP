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
int tong(int n)
{
    if(n == 0){
        return 0;
    }
    return n + tong(n-1);
}
int main()
{
	int n;
	nhapN(n);
	printf("- S = %d \n",tong(n));
	return 0;
}
