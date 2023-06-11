#include <stdio.h>
#include <math.h>
// CAU A ( NHAP MANG KHONG TRUNG PHAN TU )
int check(int a[],int n, int x)
{
	for(int j=0; j<n;j++)
		if(a[j]==x)
			return 1;
	return 0;
}
void nhapn(int &n)
{
	printf("nhap so luong phan tu:");
	scanf("%d",&n);
}
void nhapmang(int a[], int n)
{
	int t;
	for(int i=0; i<n;i++)
		{
			printf(" a[%d] ",i);
			scanf("%d",&a[i]);
			t=a[i];
			if (check(a,i,t)==1)
			{
				printf("gia tri bi trung vui long nhap lai");
				i--;
			}
			else 
				a[i]= t;
		}
}
// CAU B ( XUAT MANG )
void xuatmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",a[i]);
}
// CAU C (  SO CHINH PHUONG TAI VI TRI LE )
bool scp(int n)
{
    int sqr = sqrt(n);
    return (sqr*sqr == n);
}
void inscp( int a[],int n)
{
	int d=0;
	printf("\nSO CHINH PHUONG TAI CAC VI TRI LE:");
	for(int i=0;i<n;i++)
		if(scp(a[i]) && i%2!=0)
		{
			printf(" %d ",a[i]);
			d++;
		}
	if (d==0)
		printf("KHONG CO");
}
// CAU D ( IN RA VI TRI PHAN TU LON NHAT)
int gtln(int a[],int x)
{
	int max=a[0];
	for(int i=1;i<x;i++)
		if (a[i]>max)
				max=a[i];
	return max;
}
void xuatmax(int a[],int l)
{
	int j=0;
	int b[100];
	for(int k=0;k<l;k++)	
		if(a[k]==gtln(a,l))
			printf(" %d ",k);
}	
// CAU E( TIM PHAN TU AM MAX / PHAN TU DUONG MIN )
int firstd(int a[],int x)
{
	for(int i=0;i<x;i++)
		if (a[i]>0)
			return a[i];
	return 0;
}
int firsta(int a[],int x)
{
	for(int i=0;i<x;i++)
		if (a[i]<0)
			return a[i];
	return 0;
}
void duongmin(int a[], int n)
{
	int min=firstd(a,n);
	for(int i=0; i<n; i++)
		if(a[i]>0 && a[i]<min)
			min=a[i];
	printf("\n PHAN TU DUONG NHO NHAT: %d\n",min);
}
void ammax(int a[],int n)
{
	int max1=firsta(a,n);
	for(int i=0; i<n;i++)
		if(a[i]<0 && a[i]>max1)
			max1=a[i];
	printf("\n PHAN TU AM LON NHAT: %d",max1);	
}
// CAU F( TINH TONG CAC PHAN TU O VI TRI CHAN )
void tong(int a[],int n)
{
	int sum=0;
	for(int i=0; i<n;i++)	
		if(i%2==0)
			sum+=a[i];
	printf("TONG CAC PHAN TU O VI TRI CHAN: %d",sum);
}
// CAU G ( SAP XEP MANG THEO THU TU TANG DAN )
void sx(int a[],int x)
{
	int t;
	for(int i=0;i<x-1;i++)
		for(int j=i+1;j<x;j++)
			if(a[i]>a[j])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;		
			}
	printf("\n MANG SAU KHI SAP XEP: ");
	xuatmang(a,x);
}
int main()
{
	int a[1000];
	int n;
	nhapn(n);
	nhapmang(a,n);
	printf("MANG SAU KHI NHAP LA:");
	xuatmang(a,n);
	inscp(a,n);
	printf("\n VI TRI CAC PHAN TU LON NHAT: i=");
	xuatmax(a,n);
	ammax(a,n);
	duongmin(a,n);
	tong(a,n);
	sx(a,n);
	return 0;
}
