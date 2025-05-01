#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<long long> v(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    long long  ans = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 0; i <= n - k; i++) {
            if((v[k+i] - v[i]) % k == 0 )
                ans++;
        }
    }
    cout << ans;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}