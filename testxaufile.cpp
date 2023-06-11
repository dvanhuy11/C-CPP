#include <stdio.h>
#include <string.h>
#include <conio.h>
struct xau
{
	char s[100];
	char b[100];
	int k;
};
void nhapn(int &n)
{
	printf("NHAP SO LUONG DONG:");
	scanf("%d",&n);
}
void list(xau &x)
{
	fflush(stdin);
	gets(x.s);
}
void xuat(xau n)
{
	printf(" %s",n.s);
}
void nhapm(xau a[],int n)
{
	for(int i=0;i<n;i++)
		{
			printf("CHUOI THU %d:",i+1);
			list(a[i]);
		}
}
void xuatm(xau a[],int n)
{
	for(int i=0;i<n;i++)
	{
		xuat(a[i]);	
		printf("\n");
	}
}
void last(xau a[],int n)
{
	char s0[100];
	for (int i = 0; i < n; i++)
	{
		int x=0;
		for (int j = strlen(a[i].s); j>=0; j--)
		 {
			if (a[i].s[j] ==' ') // a[i] la dong thu i					s[j] la phan tu thuoc xau s
			{
				printf("\n");
				break;
			}
			else
				{
						s0[x]=a[i].s[j];
						x++;
				}
		}
		for(int k=x-1;k>=0;k--)
			printf("%c",s0[k]);
	}
}
int dt(xau a[], int n)
{
    int d=0;
   	for(int i=0;i<n;i++)
   		for(int j=0;j<strlen(a[i].s)+1;j++)
       		if (a[i].s[j] == ' ' && a[i].s[j+1] != ' ')
           		d++;
    return d;
}
int main()
{
	int n;
	xau s[100];
	nhapn(n);
	nhapm(s,n);
//	xuatm(s,n);
	last(s,n);
	printf("\n%d",dt(s,n));
	return 0;
}
	



