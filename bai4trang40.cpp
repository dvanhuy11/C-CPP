#include <stdio.h>
#include <string.h>
#include <conio.h>
//void kt(char  s2,char  s1)
//{
//	char *s;
//	s=strstr(s2,s1);
//	if(s)==s1[0])
//		printf("xau thu 1 nam trong xau thu 2:");
//	else
//		printf("xau thu 1 ko nam trong xau thu 2:");
//	getch();
//}
int main()
{
	char s2[100],s1[100];
	// s= (char *)malloc(100*sizeof(char));
	printf("nhap chuoi 1:");
	gets(s1);
	printf("\nnhap chuoi 2:");
	gets(s2);
	printf("\n HAI CHUOI VUA NHAP LA");
	printf("\n s1:%s",s1);
	printf("\n s2:%s",s2);
	printf("\n DO DAI S1:%d",strlen(s1));
	printf("\n DO DAI S2:%d",strlen(s2));
	printf("\n SO SANH");
	int x = strcmp(s1, s2);
        if(x < 0) printf(" \n => s1 < s2");
        if(x > 0) printf(" \n => s1 > s2");
        if(x == 0)printf(" \n => s1 = s2");
    printf("\n %s",strcat(s2,s1));
    if ((strstr(s2,s1))==NULL)
    	printf("\n s1 khong chua trong s2");
    else 
    	printf("\n s1 chua trong s2");
    if ((strstr(s1,s2))==NULL)
    	printf("\n s2 khong chua trong s1");
    else 
    	printf("\n s2 chua trong s1");
    return 0;
}
