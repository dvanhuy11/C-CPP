#include<stdio.h>
int Fibonacci(int n)
{
    if(n==0||n==1) 
		return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}
int main()
{
    int n;
   	do
	{
		printf("Nhap n = ");
		scanf("%d",&n);
		if(n<=0)
			printf("Nhap sai! Nhap lai!");
	}
	while(n<=0);
    for(int i=1;i<=n;i++)
        printf("%d",Fibonacci(i));
}
