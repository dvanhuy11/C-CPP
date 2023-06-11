#include<string>
#include<stdio.h>
int main()
{
	char s1[100],s2[100],s3[100];
	FILE *f1,*f2;
	f1=fopen("D:\\CODE\\character.inp.txt","rt");
	f2=fopen("D:\\CODE\\character.out.txt","wt");
	fscanf(f1,"%s %s %s",s1,s2,s3);
	fprintf(f2,"%s %s %s",s1,s2,s3);
	fclose(f1);
	fclose(f2);
	return 1;
}
