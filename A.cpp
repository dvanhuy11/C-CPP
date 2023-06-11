#include<stdio.h>
#include<math.h>
int main()
{
	int n,d,j;
	int a[100],b[100];
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for( j=0;j<d;j++)
		scanf("%d",&b[j]);
	int nhan=0,sum,t;
		for(int j=0;j<d;j++)	
		{
			sum=0;
			for(int i=0;i<n;i++)
				{
					nhan = a[i]*b[j];
					sum+=nhan;
				}
			int kiemtra;
			kiemtra=sum%10;
			if(kiemtra==0)
				printf("\n%d",sum);
			else 
				{
					t=sum/10;
					printf("\n%d",t);
				}
		}
	return 0;
}
