#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long tong(int a[],int n,int m)
{
	int sum=0,d=0;
	for(int i=0;i<n;i++)
	{
		sum=a[i]+a[i+1];
			if(sum==m)
				d++;
	}
	return d;
}
int main()
{
	int n,,m,a[100][100],d=0;
	FILE *f1,*f2;
	f1=fopen("D:\\CODE\\NUM.inp.txt","rt");
	f2=fopen("D:\\CODE\\NUM.out.txt","wt");
	fscanf(f1,"%d %d",&n,&m);
	for(int i=0;i<n;i++)
		fscanf(f1,"%d",&a[i]);
	fprintf(f2,"%d",tong(a,n,m));
	fclose(f1);
	fclose(f2);
	return 0;
}
