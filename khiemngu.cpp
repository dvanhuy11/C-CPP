#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	char x[100];
//	scanf(" %s ",&x);
	gets(x);
	int d=0;
	int h=strlen(x);
	printf("%d",h);
	for(int i=0;i<strlen(x);i++)
		{
		for(int k=i+1;k<=strlen(x);k++)
			if((x[i]==x[k]))
				{
					printf(" %c ",x[i]);
					break;
					 d=1;
				}
			break;
		}
			
	return 0;
}
