#include <stdio.h>
#include <conio.h>
#include <math.h>
struct td
{
	int x;
	int y;
};
void nhaptd(td &n)
{
	printf("NHAP TOA DO\n");
	printf("\tNhap x: ");
	scanf("%d",&n.x);
	printf("\tNhap y: ");
	scanf("%d",&n.y);
}
void xuattd(td n)
{
	printf("=>Toa do( %d , %d )\n",n.x,n.y);
}
void nhapsl(int &n)
{
   
    {
        printf("NHAP SO LUONG PHAN TU: ");
        scanf("%d",  &n);
    }
}
void nhapmang(td a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("Nhap toa do %d:",i+1);
		nhaptd(a[i]);
		
	}	
}
void xuatmang(td a[], int n)
{
	for(int i=0; i<n; i++)
		xuattd(a[i]);	
}
 void min(td a[],int n)
{
	td min;
	int i=0,k;
	int v=a[0].x;
	for( i=1; i<n; i++)
		if(a[i].x < v)
		{
			min=a[i];
			v=a[i].x;
			k=a[i].y;
		}
	printf(" CAU A:");
	printf("( %d , %d)",v,k);
}
void sl(td a[],int n)
{
	int d1=0,d2=0,d3=0,d4=0,d5=0;
	for(int i=0; i<n; i++)
	{	
		if((a[i].x>0) && (a[i].y>0))
			d1++;
		if((a[i].x<0) && (a[i].y>0))
			d2++;
		if ((a[i].y<0) && (a[i].x<0))
			d3++;
		if((a[i].x>0) && (a[i].y<0))
			d4++;
		if((a[i].x==0) || (a[i].y==0))
			d5++;
	}
	printf("\n CAU B:");
	printf("\n GOC PHAN TU I:%d",d1);
	printf("\n GOC PHAN TU II:%d",d2);
	printf("\n GOC PHAN TU III:%d",d3);
	printf("\n GOC PHAN TU IV:%d",d4);	
	printf("\n NAM TREN 2 TRUC TOA DO:%d",d5);		
}
//float  kcmax(td a[], int i,int j)
//{
//    float kc= sqrt(pow((a[i].x-a[j].x),2) + pow((a[i].y-a[j].y),2));
//	return kc;
//}
void inkc(td a[],int n)
{
	float kc,dis=0;
	int i=0,j=0;
	int z=a[i].x,h=a[i].y;
	int d=a[j].x,k=a[j].y;
	for( i=0; i<n-1; i++)
		for( j=i+1;j<n;j++)
		{
			kc= (1.0)*sqrt(pow((a[i].x-a[j].x),2) + pow((a[i].y-a[j].y),2));
			if(kc>dis)
			{
				dis=kc;
				z=a[i].x;
				h=a[i].y;
				d=a[j].x;
				k=a[j].y;
			}
		}
	printf("\n TOA DO CUA CAP DIEM XA NHAT LA:(%d,%d)  (%d,%d)",z,h,d,k);
	printf("\n KHOANG CACH GIUA 2 CAP DIEM:%.3f",dis);
}
int main()
{
   	int n;
	td a[100];
	nhapsl(n);
	nhapmang(a,n);
	xuatmang(a,n);
	min(a,n);
	sl(a,n);
	inkc(a,n);
    return 0;
}
