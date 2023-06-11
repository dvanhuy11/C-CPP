#include<stdio.h>
#include<math.h>
int snt(int x)
{
	if (x<2)
		return 0;
	for(int i=2;i<=sqrt(x);i++)
		if (x%i==0)
			return 0;
	return 1;
}
int MAX(int a,int b)
{
	if (a>b)
		return a;
	else 
		return b;
} 
int tong2so(int a,int b)
{
	return a+b;
}
void sx(int a[],int n)
{
	int t;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;        
            }
        }
    }	
}
int main()
{
	int n,a[10000],b[10000],ans=0,d=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int max=0,k=0;
	for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				{
					if(snt(tong2so(a[i],a[j])))
						{
							d++;
							if(d==n-1)
								printf("%d",n);
							break;
						}
					else
						{
							if(d>0)
								b[k]=d+1;
							k++;
							d=0;
						}
				}
	for(int i=0;i<k;i++)
			if(b[i]==1)
				b[i]=b[i]-1;
	sx(b,k);
	for(int i=0;i<k;i++)
		{
			printf(" %d ",b[i]);
		}
	return 0;
}

