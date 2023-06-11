#include<stdio.h>
#include<conio.h>
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
int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
    int n;
	nhapN(n);
    printf("- So Fibonacci thu %d la: %d \n", n, Fibonacci(n));
    return 0;
}
