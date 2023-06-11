#include<stdio.h>
void nhapn(int &n)
{
	do 
	 {
	 	printf("nhap n =");
	 	scanf("%d",&n);
	 }while (n<=0 && n>100);
}
void nhapmang1chieu(int a[],int n)
{
	
	for (int i=0;i<n;i++)
	{
			printf("a[%d]",i);
			scanf("%d",&a[i]);
	}
}
/*void xuatmang(int a[],int n)
{
	for(int i=n-1;i>=0;i--)
		printf(" %d ",a[i]);
}*/
/*void xuatmang(int a[],int n)
{
	int i=4;
	do
	{
		printf(" %d ",a[i]);
		i--;
	}while (i>=0);
}*/
/*void xuatmang(int a[],int n)
{
	int i=5;
	while (i--)
	{
		printf(" %d ",a[i]);
	}
}*/
void xuatmang(int a[], int n)
{
	for (int i=0;i<n;i++)
			printf(" %d ",a[i]);
}
int tongle(int a[],int n)
{
	int sum=0;
	for (int i=0;i<n;i++)
		if (a[i]%2!=0)
			sum+=a[i];
	return sum;
}
int lonnhat(int a[],int n)
{
	int max=a[0];
	for (int i=0;i<n;i++)
		if (a[i]>max)
		 max=a[i];
	return max;
}
int main()
{
	int a[10000],n;
	nhapn(n);
	nhapmang1chieu(a,n);
	xuatmang(a,n);
	printf("\nso lon nhat: %d \n",lonnhat(a,n));
	printf("tong cac so le= %d ",tongle(a,n));
	return 1;
}
