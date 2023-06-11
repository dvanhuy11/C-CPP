#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct phanso
{
	int tu;
	int mau;
};
typedef struct phanso ps;
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void nhapps(ps &x)
{
	scanf("%d",&x.tu); 
	scanf("%d",&x.mau);
}
void xuatps(ps p)
{
	printf(" %d/%d",p.tu,p.mau);	
}
void nhapmang(ps a[],int n)
{
	for(int i=0; i<n; i++)
	{
		printf("nhap tu va mau so thu: %d \n",i+1);
		nhapps(a[i]);
	}
}
void xuatmang(ps a[],int x)
{
	for(int i=0; i<x; i++)
		printf("%d / %d\n",a[i].tu,a[i].mau);
}
ps max(ps *a, int n)
{
	ps max;
	float v=(float)a[0].tu / a[0].mau;
	for(int i=1; i<n; i++)
		if((float) a[i].tu/ a[i].mau > v)
		{
			max=*(a+i);
			v=(float) a[i].tu/a[i].mau;
		}
	return max;
}
int nhohon1(ps a[], int x )
{
	int dem1=0;
	for(int i=0; i<x; i++)
		if((a[i].tu/a[i].mau)<1)
			dem1++;
	return dem1;
}
int UCLN(int a, int b)
{
	a=abs(a);
	b=abs(b);
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}	
	return a;
}
ps rutGonPhanSo(ps p)
{
	int uc=UCLN(p.tu,p.mau);
	p.tu=p.tu/uc;
	p.mau=p.mau/uc;
	return p;
}
int main()
{
//	struct phanso *a;
	ps a[100];
	int n;
	// a= (struct phanso*) malloc(n * sizeof(struct phanso));
	nhapn(n);
	nhapmang(a,n);
//	xuatmang(a,n);
	printf("CO %d PHAN SO CO GIA TRI NHO HON 1",nhohon1(a,n));
	printf("\n PHAN SO LON NHAT TRONG DAY LA: ");
	xuatps(max(a,n));
//	free(a);
	return 0;
}

