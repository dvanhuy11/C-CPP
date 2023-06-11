#include<stdio.h>
#include<math.h>
int snt(int x)
{
	if (x<=1)
		return 0;
	for(int i=2;i<=sqrt(x);i++)
		if (x%i==0)
			return 0;
	return 1;
}
int main()
{
	int n;
	printf("nhap vao so nguyen=");
	scanf("%d",&n);
	if (snt(n))
		printf("yes");
	else 
		printf("no");
	return 0;
}
