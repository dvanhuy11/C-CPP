#include<stdio.h>
int k,n,v,ans,i;
int check(int a) {
        if (a == 1) {
            return 1678;
        }
        if (a == 2) {
            return 1734;
        }
        if (a == 3 || a == 4) {
            return 2014;
        }
        if (a == 5 || a == 6) {
            return 2536;
        }
        if (a == 7 || a == 8) {
            return 2834;
        }

        return 2927;

    }
int main()
{
    scanf("%d",&n);
	 k = n / 50;
	 v = n % 50;
     ans = v * check(k + 1);
    for ( i = 1; i <= k; i++)
            ans = ans + 50 * check(i);
    if(ans%10 >5)
    	ans=ans+((int)ans/10 +1);
    else 
    	ans=ans+((int)ans/10);
     printf("%d",ans);
	 return 0;	
}
