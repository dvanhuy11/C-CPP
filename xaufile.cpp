#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct xau
{
	char s[100];
};
//void list(xau &x)
//{
//	FILE *f;
//	fflush(stdin);
//}
void nhapfile(xau a[],int n)
{
	FILE *f;
	f=fopen("D:\\CODE\\STR.txt","r+");
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
		fgets(a->s,40,f);
	fclose(f);
}
void ghifile(xau a[],int n)
{
	FILE *f;
	f=fopen("D:\\CODE\\STR.txt","r+");
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
			for (int j=0; j < strlen(a[i].s);j++)	
				fprintf(f," %c ",a[i].s[j]);
	fclose(f);		
}
void last(xau a[],int n)
{
	FILE *f;
	f=fopen("D:\\CODE\\STR.txt","r+");
	fscanf(f,"%d",&n);
	char s0[100];
	for (int i = 0; i < n; i++)
	{
		int x=0;
		for (int j = strlen(a[i].s); j>=0; j--)
		 {
			if (a[i].s[j] ==' ') // a[i] la dong thu i					s[j] la phan tu thuoc xau s
			{
				fprintf(f,"\n");
				break;
			}
			else
				{
						s0[x]=a[i].s[j];
						x++;
				}
		}
		for(int k=x-1;k>=0;k--)
			fprintf(f,"%c",s0[k]);
	}
}
int main()
{
	int n;
	xau s[40];
	nhapfile(s,n);
	ghifile(s,n);
	return 0;
}
