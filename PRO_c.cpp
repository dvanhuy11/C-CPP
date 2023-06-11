#include<stdio.h>
using namespace std;
int main()
{
	int e,m;
	int count =1;
	while(cin >> e >> m)
	{
		int i=0;
		while((e+i)%365 !+0 || (m+i)%687!=0)
			i++;
		cout<< "Case " << count <<": "<< i << <<"\n";
		count++;
	}
}
