#include<stdio.h>
#include<math.h>
int n,x[100],y[100],ans=0,i,j=1,k=1,can,tri;

void check(int x[],int y[], int k,int  j)
{
		can=(int) sqrt(pow(x[k]-x[j],2)+pow(y[k]-y[j],2));
		tri=abs(x[k]-x[j])+abs(y[k]-y[j]);
		if(can==tri)
			ans+;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
			scanf("%d %d",&x[i],&y[i]);
	while(k<=n)
	{
		j++;
		if(j>n)
			{
				k++;
				j=k;
			}
		else check(x,y,k,j);
	}
	printf("%d",ans);
	return 0;
	
}

