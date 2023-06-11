#include<stdio.h>
#include<math.h>
struct nhiptim
{
	int beat;
	float p;
};
void doc(nhiptim &x)
{
	scanf("%d %f",&x.beat,&x.p);
}
int main()
{
	int test;
	nhiptim x[2];
	scanf("%d",&test);
	for(int i=0;i<test;i++)
			doc(x[i]);
	for(int i=0;i<test;i++)
		{
			if(x[i].beat > x[i].p)
				{
					int k=0;
					float buocnhay=abs((float)(60/x[i].p));
					float nhip=abs(buocnhay*x[i].p);
					while(k<3)
					{
						printf(" %0.4f ",nhip);
						k++;
						nhip+=buocnhay;
					}
				}
			else 
				{
					int k=0;
					float buocnhay=((float)(60/x[i].p));
					float nhip=buocnhay;
					while(k<3)
					{
						printf(" %0.4f ",nhip);
						k++;
						nhip+=buocnhay;
					}
				}
			printf("\n");
		}
	return 0;
}
