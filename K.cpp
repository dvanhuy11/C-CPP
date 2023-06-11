#include<stdio.h>
#include<conio.h>
#include<string.h>
void sx(char s[])
{
	int i,j;
	char temp;
	int n=strlen(s);
	for (i = 0; i < n-1; i++) 
      for (j = i+1; j < n; j++) 
         if (s[i] > s[j]) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
		}
}
voi xoa3(char s[])
{
	int d=0;
	for(int i=0;i<strlen(s);i++)
		b[i]=0;
	for(int i=0;i<strlen(s);i++)
		for(int j=i+1;j<strlen(s);j++)
			if(s[i]==s[j])
				{
					d++;
					
				}
}
			
			
void xoa2(char s[])
{
	int l = strlen(s);
	int d=0;
	char s2[256];
	char check;
    for (int i = 0; i < l; i++)  
    	for (int j = i + 1; j < l; j++)
   		{
         	if (s[i] == s[j] )
         		{
  					check=s[j];		       			
         			s2[d]=s[j];
					d++;	
				 }
			else 
				break;
//         		 strncpy(s + j, s + j + 1, l - j);
//        	l = strlen(s);
		}
   	for(int h=0;h<d;h++)
  	 	 printf("%c",s2[h]);
}
int main()
{
	char test1[100];
	char test2[100];
	fflush(stdin);
	gets(test1);
	fflush(stdin);
	gets(test2);
	sx(test1);
	sx(test2);
	printf("\n%s",test1);
	printf("\n%s\n",test2);
	xoa2(test2);
	return 0;
}
