#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char x[100];
  int d=0;
  cin.get(x,99);
  for(int i=0;i<strlen(x);i++)
		{
		for(int k=i+1;k<=strlen(x);k++)
			if((x[i]==x[k]))
				{
					cout<<x[i];
					break;
					d=1;
				}
		if(d==1)
			break;
		if(i==strlen(x) && d==0)
			cout<<"null";
		}
  return 0;
}
