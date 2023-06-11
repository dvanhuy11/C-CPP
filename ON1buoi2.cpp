#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//CAU A ( NHAP MANG BANG CON TRO )
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void nhapmang(int *a,int x)
{
	for(int i=0;i<x;i++)
		{
			printf("a[%d]",i);
			scanf("%d",(a+i));
		}
}
//CAU B
void xuatmang(int *a,int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",*(a+i));
}
// CAU C( TINH TONG CAC PHAN TU TRONG MANG )
long tong(int *a,int x)
{
	int sum=0;
	for(int i=0;i<x;i++)
		sum+=*(a+i);
	return sum;
}
// CAU D ( TINH TONG CAC PHAN TU CHAN )
long tongchan(int *a,int x)
{
	int sumc=0;
	for(int i=0;i<x;i++)
		if(*(a+i)%2==0)
			sumc+=*(a+i);
	return sumc;
}
// CAU E ( TINH TONG CAC PHAN TU LE)
long tongle(int *a,int x)
{
	int suml=0;
	for(int i=0;i<x;i++)
		if(*(a+i)%2!=0)
			suml+=*(a+i);
	return suml;
}
// CAU F ( TINH TONG CAC PHAN TU NGUYEN TO)
int snt(int x)
{
	if (x<=1)
		return 0;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return 0;
	return 1;
}
long tongsnt(int *a,int x)
{
	int sumnt=0;
	for(int i=0;i<x;i++)
		if(snt(*(a+i)))
			sumnt+=*(a+i);
	return sumnt;
}
// CAU G ( TIM PHAN TU CHAN DAU TIEN )
void firstc(int *a,int x)
{
	int gtc;
	for(int i=0;i<x;i++)
		if((*(a+i))%2==0)
			{
				gtc=*(a+i);
				break;
			}
	printf("\n GIA TRI CUA PHAN TU CHAN DAU TIEN: %d",gtc);
}
// CAU H ( TIM PHAN TU LE DAU TIEN )
void firstl(int *a,int x)
{
	int gtl;
	for(int i=0;i<x;i++)
		if((*(a+i))%2!=0)
			{
				gtl=*(a+i);
				break;
			}
	printf("\n GIA TRI CUA PHAN TU LE DAU TIEN: %d",gtl);
}
// CAU I ( TIM PHAN TU NGUYEN TO DAU TIEN )
void firstnt(int *a,int x)
{
	int gtnt;
	for(int i=0;i<x;i++)
		if(snt(*(a+i)))
			{
				gtnt=*(a+i);
				break;
			}
	printf("\n GIA TRI CUA PHAN TU NGUYEN TO DAU TIEN: %d",gtnt);
}
// CAU J ( TIM PHAN TU CHAN CUOI CUNG )
void lastc(int *a,int x)
{
	int lastc=0;
	for(int i=x-1;i>=0;i--)
		if ((*(a+i))%2==0)	
			{
				lastc=*(a+i);
				break;
			}
	printf("\n GIA TRI CUA PHAN TU CHAN CUOI CUNG : %d",lastc);
}
// CAU K ( TIM PHAN TU CHINH PHUONG CUOI CUNG )
bool scp(int x)
{
	int sqr = sqrt(x);
	return (sqr * sqr == x);
}
void lastcp(int *a,int x)
{
	int lastcp=0;
	for(int i=x-1;i>=0;i--)
		if (scp(*(a+i)))	
			{
				lastcp=*(a+i);
				break;
			}
	printf("\n GIA TRI CUA PHAN TU CHINH PHUONG CUOI CUNG : %d",lastcp);
}
// CAU L ( TIM PHAN TU LON NHAT )
int gtln(int *a,int x)
{
	int max=*(a+0);
	for(int i=1;i<x;i++)
		if ((*(a+i))>max)
				max=*(a+i);
	return max;
}
// CAU M ( DEM SO PHAN TU CHAN TRONG MANG )
int demchan(int *a, int x)
{
	int dc=0;
	for(int i=0;i<x;i++)
		if((*(a+i))%2==0)
			dc++;
	return dc;
}
// CAU N ( DEM SO LUONG PHAN TU LON NHAT )
int dem(int *a,int x )
{
	int demmax=0;
	for(int i=0;i<x;i++)	
		if (*(a+i)==gtln(a,x))
			demmax++;
	return demmax;
}	
// CAU O ( IN RA VI TRI PHAN TU LON NHAT DAU TIEN 
void firstmax(int *a,int x )
{
	int vtmax=0;
	for(int i=0;i<x;i++)	
		if (*(a+i)==gtln(a,x))
			{
				vtmax=*(a+i);
				break;
			}
	printf("\n VI TRI CUA PHAN TU LON NHAT DAU TIEN LA: %d",vtmax);
}	
void nhapai(int &h)
{
	printf(" \n NHAP GIA TRI CAN THEM= ");
	scanf("%d",&h);
}
void addf(int *b,int x,int k) 
{
	nhapai(k);
	x++;
	for(int i=x;i>=1;i--)
  		{
   			*(b+i)=*(b+(i-1)); 
 	    }
 	*(b+0)=k; 
 	printf("MANG SAU KHI THEM PHAN TU VAO DAU MANG: ");	
 	xuatmang(b,x); 
}
void xoaf(int *a,int x)
{
	for(int i=0;i<x;i++)
   			*(a+i)=*(a+(i+1));	 
}
void addl(int *b,int x,int k) 
{
	nhapai(k);
	x++;
	for(int i=x;i>=1;i--)
  		{
   			*(b+i)=k;
   			break;
 	    }
 	printf("MANG SAU KHI THEM PHAN TU VAO CUOI MANG: ");	
 	xuatmang(b,x); 
}
int main()
{
	int *a;
	int n,k;
	nhapn(n);
	a = (int *)malloc(n * sizeof(int));
	nhapmang(a,n);
	xuatmang(a,n);
	printf("\n TONG CAC PHAN TU CO TRONG MANG = %d",tong(a,n));
	printf("\n TONG CAC PHAN TU CHAN CO TRONG MANG =%d",tongchan(a,n));
	printf("\n TONG CAC PHAN TU LE CO TRONG MANG= %d",tongle(a,n));
	printf("\n TONG CAC PHAN TU NGUYEN TO= %d",tongsnt(a,n));
	firstc(a,n);
	firstl(a,n);
	firstnt(a,n);
	lastc(a,n);
	lastcp(a,n);
	printf("\n GIA TRI LON NHAT TRONG MANG LA: %d",gtln(a,n));
	printf("\n SO PHAN TU CHAN TRONG MANG LA: %d",demchan(a,n));
	printf("\n SO LUONG PHAN TU LON NHAT TRONG MANG LA: %d",dem(a,n));
	firstmax(a,n);
	free(a);
	addf(a,n,k);
	xoaf(a,n);
	addl(a,n,k);
	return 0;
}
