#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
int main()
{
	int n=5, x=3;
	int *a = (int *)calloc(n,sizeof(int));
	for (int i=0;i<n;i++)
		*(a+i)=i *x;
	for (int i=0;i<n;i++)	
	printf("%5d",*(a+i));
	free(a);
	a=&x;
	*a=*a+x;
	printf("\nx=%d",x);
	getch();
}
