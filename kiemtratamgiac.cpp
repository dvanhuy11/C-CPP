#include <stdio.h>
 int main ()
 {
 	int a,b,c;
 	printf("nhap vao 3 canh cua tam giac =");
 	scanf("%d%d%d",&a,&b,&c);
 	if (a==b==c)
 		printf("day la tam giac deu");
	  else {
	 	if ((a==b) || (a==c) || (b==c))
		 {
	 		printf("day la tam giac can");
		 }else printf("day la tam giac thuong");
	 }
	return 0;
 }
