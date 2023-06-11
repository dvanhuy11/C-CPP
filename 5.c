#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhapAB(int &a, int &b)
{
		printf("- Moi ban nhap cac so a va b = \n");
		scanf("%d%d",&a,&b);
}
int UCLN(int a, int b)
{
	if (a == b)
		return a;
	if (a > b)
		return UCLN(a-b, b);
	else
		return UCLN(a, b-a);
}	
int main()

	int a,b;
	nhapAB(a,b);
	printf("- Uoc chung lon nhat cua %d vs %d la = %d\n",a,b,UCLN(a,b));
	return 0;
}
