#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int snt(int x)
{
	if (x<=1)
		return 0;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return 0;
	return 1;
}
int doixung(int n)
{
   int t=n;
   int dv,dn=0;
   while(t!=0)
   {
      dv=t%10;
      dn=dn*10+dv;
      t=t/10;
   }
   if(dn==n)
   		return 1;
   return 0;
}
int main()
{
	int n,a[100],d=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
			scanf("%d",&a[i]);
			if(snt(a[i]) && (doixung(a[i])==1))
				d++;
	}
	printf("%d",d);
	return 0;
}
