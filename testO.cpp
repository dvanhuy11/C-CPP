#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int n,x[100],y[100],ans=0,ans1=0,i,j,k,can,tri;

int check(int x[],int y[], int k,int j)
{
		can=(int) sqrt(pow(x[k]-x[j],2)+pow(y[k]-y[j],2));
		tri=abs(x[k]-x[j])+abs(y[k]-y[j]);
		if(can==tri)
			return ans++;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)	
		scanf("%d %d",&x[i],&y[i]);
	for(j=1;j<=n;j++)
	{
		if(j>=2)
			ans1+=check(x,y,j-1,j);
		if(j==n)
			ans1+=check(x,y,1,j);
	}
	printf("%d",ans);
	return 0;
	
}

