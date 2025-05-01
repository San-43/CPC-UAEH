#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    long long  n;
    cin >> n;
    vector<long long > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += abs(v[i] - v[i+1]);
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