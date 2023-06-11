#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct kg
{
	char name[20];
	int soao;
};
void doc(kg s[],int m)
{
	FILE *f;
	kg a[100];
	f=fopen("D:\\CODE\\TenKhanGia.txt","r+");
	fscanf(f,"%d",&m);
	for(int j=0;j<m;j++)
		fgets(s[j].a->name,20,f);
	srand(time(NULL));
	int min=0;
	int max=9;
	for(int i=0;i<m;i++)
			{
				s[i].soao=min+rand()%(max-min+1);
				fprintf(f,"%d",s[i].soao);
			}
}
int main()
{
	kg a[100];
	int n,m;
	doc(a,m);
	return 0;
}
