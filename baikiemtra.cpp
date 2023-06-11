#include <stdio.h>
#include <math.h>
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void nhapmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		{
			printf("a[%d]",i);
			scanf("%d",&a[i]);
		}
}
int snt(int x)
{
	if (x<=1)
		return 0;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return 0;
	return 1;
}
long tong(int a[],int x)
{
	int sum=0;
	for(int i=0;i<x;i++)	
		sum+=a[i];
	return sum;
}
int dayconmax(int a[],int x)
{
	int max=0,dem1=0;
	for(int i=0;i<x;i++)
		if(a[i]<a[i+1])
			{
				dem1++;
				if (dem1>max)
					max=dem1;
			}
		else 
			dem1=1;
	return max;
}
int demsnt(int a[], int x)
{
	int dem=0;
	for(int i=0;i<x;i++)
		if(snt(a[i]))
			dem++;
	return dem;
}
int main()
{
	int a[100],n;
	nhapn(n);
	nhapmang(a,n);
	printf("TONG CAC PHAN TU CUA DAY =%d",tong(a,n));
	printf("\nDAY A CO %d SO NGUYEN TO",demsnt(a,n));
	printf("\nCHIEU DAI DAY CON TANG DAI NHAT= %d",dayconmax(a,n));
	return 0;
}

