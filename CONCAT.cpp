#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll t, n, l, r;
ll a[120000], poww10[20];

long len(long n) {
    long cnt = 0;
    while(n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    poww10[0] = 1;
    for(long i = 1; i < 17; i++)
        poww10[i] = poww10[i - 1] * 10;

    while(t--) {
        cin >> n >> l >> r;
        for(long i = 1; i <= n; i++) {
            cin >> a[i];
        }

        long long ans = 0;

        sort(a + 1, a + n + 1);
        for(long i = 1; i <= n; i++) {
            long length = len(a[i]);
            ll L = (l - a[i] + poww10[length] - 1) / poww10[length];
            ll R = (r - a[i]) / poww10[length];
            if(L <= R) ans += (upper_bound(a + 1, a + n + 1, R) - lower_bound(a + 1, a + n + 1, L));
            
        }
        cout << ans <<"\n";
    }
    return 0;
}
