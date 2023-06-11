#include<stdio.h>
#include<math.h>
int scp(int &x)
{
	int sqr=sqrt(x);
	return (sqr*sqr==x);
}
int main()
{
	int n;
	printf("\nhap n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		if(scp(i))
			printf(" %d ",i);
	return 0;
}
