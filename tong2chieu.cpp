#include<iostream>

using namespace std;

int main() {
    int a[100][100],n,m,sum=0;
    cin>>n>>m;
    for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
        {
			cin >> a[i][j];
            if (a[i][j] % 5==0)
                sum+=a[i][j];
        }
    cout << sum;
    return 0;
}

