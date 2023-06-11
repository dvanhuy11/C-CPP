#include <stdio.h>
#include<conio.h>
#include<algorithm>
struct phanso
{
	int tu;
	int mau;
	float t;
};
typedef struct phanso ps;
void nhap(int &n)
{
	do 
	{
		printf("nhap n =");
		scanf("%d",&n);
	}while (n<0 || n>100);
}
void nhapps(ps &x,int i)
{
		printf("nhap tu va mau so thu %d:",i+1);
		scanf("%d",&x.tu); 
		scanf("%d",&x.mau);
		if (x.mau==0)
		{
				printf("vui long nhap lai mau");
				scanf("%d",&x.mau);
		}
}
void xuatps(ps x)
{
	printf("%d / %d",x.tu,x.mau);
}
void nhapmang(ps a[], int n)
{
	for(int i=0;i<n;i++)
		nhapps(a[i],i);
}
void xuatmang(ps a[],int n)
{
	for(int i=0;i<n;i++)
		printf("\n %d / %d",a[i].tu,a[i].mau);
}
ps rutgon(ps x)
{
	int ucln = std::__gcd(x.tu,x.mau);
	x.tu=x.tu/ucln;
	x.mau=x.mau/ucln;
	return x;
}
ps tongps(ps p1,ps p2)
{
	ps tong;
	tong.mau=p1.mau*p2.mau;
	tong.tu=(p1.tu*p2.mau)+(p1.mau*p2.tu);
	return tong;
}
ps tongmang(ps a[],int n)
{
	ps sum;
	sum.tu=0;
	sum.mau=1;
	for(int i=0;i<n;i++)
	{
		sum=tongps(a[i],sum);
		rutgon(sum);
	}
	return sum;
}
int dem(ps a[],int n)
{
	int d=0;
	for(int i=0;i<n;i++)
		if(((a[i].tu)/(float)(a[i].mau))<1)
			d++;
	return d;
}
void sx(ps a[],int n)
{
	ps t;
	int j,i;
	for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				float v=(float)(a[i].tu)/(a[i].mau);
				float k=(float)(a[j].tu)/(a[j].mau);
				if(v>k)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
		   	}
		}
	xuatmang(a,n);
}
int main()
{
	int n;
	ps a[100];
//	int a[100];
	nhap(n);
	nhapmang(a,n);
	printf("MANG SAU KHI NHAP LA:");
	xuatmang(a,n);
	printf("\n TONG MANG=");
	xuatps(rutgon(tongmang(a,n)));
	printf("\n CO %d PHAN SO < 1",dem(a,n));
	printf("\n MANG SAU KHI SAP XEP:");
	sx(a,n);
	getch();
	return 0; 
}
