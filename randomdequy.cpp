#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void random(int a[],int n)
{
//	int min=1000;
//	int max=9999;
    srand(time(NULL));
    for (int i=0;i<n;i++)
//    	a[i]=min+rand()%(max-min+1);
		a[i]=rand()%99;
}
//void xuatmangnguoc(int a[], int n)
//{
//    if(n>= 0)
//	{
//        xuatmangnguoc(a, n-1);
//        printf(" %d ", a[n-1]);
//    }
//}
//void xuatmang(int a[],int n,int i=0)
//{
//	if(i==n)
//		return ;
////	else 
////		{
//			printf(" %d ",a[i]);
//			xuatmang(a,n,i+1);
//	//	}
//}
//void nhapmang(int a[],int x)
//{
//	for(int i=0;i<x;i++)
//		{
//			printf("a[%d]",i);
//			scanf("%d",&a[i]);
//		}
//}
void xuatmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",a[i]);
}
bool snt(int x)
{
	if (x<=1)
		return false;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return false;
	return true;
}
int dnt(int a[],int n)
{
	if(n<0)
		return 0;
	else 
		if(snt(a[n]))
			return 
				 1+dnt(a,n-1);
		else 
			dnt(a,n-1);
}
int dem(int a[],int i)
{
	i--;
    if(i<0) return 0;
    else
    {
        if(a[i]%2==0) 
			return 
				1+dem(a, i);
        else 
			return dem(a, i);
    }
}

//int tongcs(int x)
//{
//	int t=0;
//	while(x%10!=0)
//	{
//		t=t+(x%10);
//		x=x/10;
//	}
//	return t;
//}
//int tong(int a[],int n)
//{
//	int sum=0;
//	for(int i=0;i<n;i++)
//		sum+=tongcs(a[i]);
//	return sum;
//}
int tongdq(int a[],int n)
{
	if(n==1)
		return (a[0]);
	else 
		return tongdq(a,n-1)+(a[n-1]);
	return tongdq(a,n-1);
}
bool kttoanchan(int a[], int n){
	if(n==0)
		return true;
	if(a[n-1] % 2 != 0)
		return false;
	return kttoanchan(a, n-1);
}
int tongc(int a[],int n)
{
	if(n<0)
		return 0;
	if(a[n]%2==0)
			return tongc(a,n-1)+a[n];
		else
			return tongc(a,n-1);
}
int max(int a[],int n)
{
    if(n==0)
        return -1;
    if(n==1)
        return a[0];
    else 
        if(a[n-1]>max(a,n-1))
            return a[n-1];
        else 
            return max(a,n-1);
}
int vtmax(int a[],int n)
{
    if(n==1)
        return n;
    else 
        if(a[n-1]==max(a,n))
            return n-1;
        else 
            return vtmax(a,n-1);
}
void sort(int a[], int n)
{
	if (n == 1)return;
	else{
		sort(a, n - 1); 
		if (a[n - 1] < a[n - 2])
		{ 
			int temp = a[n - 1]; 
			a[n - 1] = a[n - 2];
			a[n - 2] = temp;
			sort(a, n - 1); 
		}
	}

}
int checkbangx(int a[],int n,int x)
{
	if(n<0)
		return 0;
	if(a[n]==x)
		return checkbangx(a,n-1,x)+1;
	else 
		return checkbangx(a,n-1,x);
}
int main()
{
	int a[20],n,min,i;
//	nhapn(n);
//	nhapmang(a,n);
	random(a,n);
	printf("xuat mang\n");
	xuatmang(a,n);
//	printf("\n xuat mang nguoc ");
//	xuatmangnguoc(a,n);
	printf("\nCo %d so chan trong mang",dem(a,n));
	printf("\nCo %d so nguyen to trong mang",dnt(a,n));
	printf("\nTONG MANG:%d",tongdq(a,n));
	printf("\nTONG CHAN:%d",tongc(a,n-1));
	printf("\nSo lon nhat trong mang la:%d",max(a,n));
	printf("\nVi tri phan tu lon nhat:%d",vtmax(a,n));
	printf("\nCO %d so = k",checkbangx(a,n,8));
	printf("\n Mang sau khi sap xep");
	sort(a,n);
	return 0;
}
