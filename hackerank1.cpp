#include<stdio.h>
int max(int a[],int n)
{
    int max1=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max1)
            max1=a[i];
    return max1;
}
int list(int a[],int n)
{
	int i,dem[100],dem1[100];
	for(i=0;i<=max(a,n);i++)
		dem[i]=0;
    for(int h =0; h<n;h++)
        dem[a[h]]+=1;
    int min2;
    for(i=0;i<= max(a,n)-1;i++)
   	 for(int v=i+1;v<max(a,n);v++)
        if(dem[i]==1 && dem[v]==1)
			{
				dem[i]<dem[v];
				min2=dem[i];
			}
	int min2,v,g;
	for(v=0;v<j-1;v++)
		for(g=v+1;g<j;g++)
			if(dem1[v]<dem1[g])
				min2=dem1[v];
	if(j>0)
		return v+1;
	else 
		return -1;        	
}
int main()
{
	int a[100],b[100],n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		{
			printf("nhap case %d:",i);
			scanf("%d",&b[i]);
			for(int j=0;j<b[i];j++)
				{
					printf("nhap a[%d]",j);
					scanf("%d",&a[j]);
				}
		}
//	int i,dem[100],dem1[100];
	for(int i=0;i<n;i++)
//			{
//				for(i=0;i<=max(a,n);i++)
//				dem[i]=0;
//   				for(i =0; i<n;i++)
//      				  dem[a[i]]+=1;
//   				int j=0;
//   				for(i=0;i<= max(a,n);i++)
//       			if(dem[i]==1)
//					{
//						dem1[j]=dem[i];
//						j++;
//					}
//			int min2,v,g;
//			for(v=0;v<j-1;v++)
//			for(g=v+1;g<j;g++)
//			if(dem1[v]<dem1[g])
//				min2=dem1[v];
//			if(j>0)
//				printf("%d",v+1) ;
//			else 
//				printf("-1");        	
//			}
	printf("%d\n",list(a,b[i]));
	return 0;
}
