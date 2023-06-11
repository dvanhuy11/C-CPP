#include<stdio.h>
// CAU A
void nhapn(int &n)
{
	do 
	 {
	 	printf("nhap n =");
	 	scanf("%d",&n);
	 }while (n<=0 && n>100);
}
// CAU B
void nhapmang1chieu(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
			printf("a[%d]",i);
			scanf("%d",&a[i]);
	}
}
// CAU C
void xuatmang(int a[], int n)
{
	for (int i=0;i<n;i++)
	{
			printf("%d",a[i]);
			printf("\n");
	}
}
//CAU D
int sobenhat(int a[], int n)
{
	int min=a[0];
	for (int i=0;i<n;i++)
	 	if (a[i] < min)
	 	  min=a[i];
	return min;
}
// CAU E
int main()
{
	int a[10000],n;
	nhapn(n);
	nhapmang1chieu(a,n);
	xuatmang(a,n);
	printf("so be nhat trong day la: %d ",sobenhat(a,n));
	return 1;
}
