#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
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
//void nhapmang(ps *a,int n)
//{
//	for(int i=0; i<n; i++)
//	{
//		printf("nhap tu va mau so thu: %d \n",i+1);
//		nhapps(*(a+i));
//	}
//}
void random(ps *a,int n)
{
    srand(time(NULL));
    for (int i=0;i<n;i++)
    	{
    		(*(a+i)).tu=rand()%100;
    		(*(a+i)).mau=rand()%100;
		}
}
void xuatmang(ps *a,int x)
{
	for(int i=0; i<x; i++)
		printf("%d / %d\n",(*(a+i)).tu,(*(a+i)).mau);
}
ps max(ps *a, int n)
{
	ps max;
	int i=0;
	float v=(float)(*(a+i)).tu / (*(a+i)).mau;
	for(i=1; i<n; i++)
		if((float) (*(a+i)).tu/ (*(a+i)).mau > v)
		{
			max=*(a+i);
			v=(float) (*(a+i)).tu/(*(a+i)).mau;
		}
	return max;
}
ps tong2PhanSo(ps p1, ps p2)
{
	ps tong;
	tong.mau=p1.mau *p2.mau;
	tong.tu = p1.tu*p2.mau + p2.tu*p1.mau;
	return tong;
}
ps tongPhanSo(ps *p, int n)
{
	ps tong;
	tong.tu=0;
	tong.mau=1;
	for(int i=0; i<n; i++)
	{
		tong=tong2PhanSo(*(p+i),tong);
	}
	return tong;
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
	struct phanso *a;
	int n;
	a= (struct phanso*) malloc(n * sizeof(struct phanso));
	nhapn(n);
//	nhapmang(a,n);
	random(a,n);
	xuatmang(a,n);
	printf("PHAN SO LON NHAT TRONG DAY LA: ");
	xuatps(max(a,n));
	printf("\nTONG CAC PHAN SO:");
	xuatps(rutGonPhanSo(tongPhanSo(a,n)));
	printf("\n");
	free(a);
	getch();
}

