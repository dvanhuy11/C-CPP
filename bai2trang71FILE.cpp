#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhapfile(int a[],int n)
{
	FILE *f1;
	f1=fopen("D:\\CODE\\bai2.inp.txt","rt");
	fscanf(f1,"%d",&n);
	for(int i=0;i<n;i++)
	{
		fscanf(f1,"%d",&a[i]);
		printf(" %d ",a[i]);
	}
	fclose(f1);
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
void ghifile(int a[],int n)
{
	FILE *f2,*f1;
	f1=fopen("D:\\CODE\\bai2.inp.txt","rt");
	fscanf(f1,"%d",&n);
	f2=fopen("D:\\CODE\\bai2.out.txt","wt");
	for(int i=0;i<n;i++)	
		if(snt(a[i]))
			fprintf(f2," %d ",a[i]);
	fclose(f2);		
}
int main()
{
	int a[100], n;
	printf("MANG VUA NHAP LA:");
	nhapfile(a,n);
	ghifile(a,n);
	return 0;
}
