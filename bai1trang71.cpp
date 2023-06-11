#include<stdio.h>
#include<stdlib.h>
int main()
{
	char c[50];	
	FILE *f;
	f=fopen("D:\\code\\cau1trang71.txt","w"); // a
	if(f==NULL) 	 
	{
		printf("Hello!");
		exit(1);
	}
	printf("Nhap noi dung van ban:\n");
	gets(c);
	fprintf(f,"%s",c);  // b
	fclose(f);
	if ((f= fopen("D:\\code\\cau1trang71.txt", "r+")) == NULL)  //b
    {
        printf("Hello!");
        exit(1);         
    }   
    fscanf(f,"%s", c);
    printf("noi dung van ban da nhap vao file la:\n%s\n", c);
	if(f==NULL) 	 // c 
	{
		printf("Hello!");
		exit(1);
	}
	printf("Nhap phan tap tin noi them:");
	gets(c);
	fprintf(f,"%s",c); 
	fclose(f);
	return 0;
}
