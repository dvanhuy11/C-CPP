#include<stdio.h>
int ucln(int &n, int &m)
{
	if (m==n) 
		scanf("%d",m);
	while (n!=m) 
		{
			if (n>m)
				n=n-m;
			else 
				m=m-n;
		}
	return m;
}
int main()
{
	int n,m;
	printf("nhap m va n ");
	scanf("%d%d",&m,&m);
	printf("uoc chung lon nhat la %d",ucln(n,m));
	return 1;
}
