#include<stdio.h>
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
void xuatmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",a[i]);
}
int min(int a[],int n)
{
    if(n==0)
        return -1;
    if(n==1)
        return min=a[0];
    else 
        if(a[n-1]<min(a,n-1))
            return a[n-1];
        else 
            return min(a,n-1);
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
int demnt(int a[],int n)
{
    if(n==0)
        return -1;
    if(n==1)
        if(snt(a[n-1]))
            return demnt=1;
        else 
            return demnt=0;
    else 
        if(snt(a[n]))
            return 1+demnt(a,n-1);
        else 
            return demnt(a,n-1);
}
int main()
{
    int a[100],n;
    nhapn(n);
    nhapmang(a,n);
    xuatmang(a,n);
    printf("\n GIA TRI NHO NHAT TRONG DAY LA:%d",min(a,n));
    printf("CO %d SO NGUYEN TO TRONG DAY",demnt(a,n));
    return 0;

}