#include <stdio.h>
int snt(int x)
{
	int i,dem;
	if (x==1) return 0;
	for (i=2;i<=x;i++)
			if (x%i==0)
				dem++;
	if (dem==2)
		return 1;
		else 
			return 0;
}
int main()
{
	int n;
	printf("nhap so nguyen n=");scanf("%d",&n);
	int s=0,i;
	for (i=1;i<=n;i++)
		if (snt(i))
			{
				printf("day la so nguyen to");
				s+=i;
			}
	return 1;
}
