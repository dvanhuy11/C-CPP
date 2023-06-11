#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int x[100],y[100];
	scanf("%d",&n);
	int ans,check;
	float can, tri;
	for(int i=0;i<n;i++)
			scanf("%d %d",&x[i],&y[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)	
			{
				can=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
				tri=abs(x[i]-x[j])+abs(y[i]-y[j]);
				check=(int)can;
				if(check==tri)
					ans++;
			}
	printf("%d",ans);
	return 0;
	
}
