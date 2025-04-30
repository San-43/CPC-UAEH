#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans = 0;
    vector<int> v(a);
    for(int i = 0; i < a ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < a; i++) {
        if (v[i] <= b) {
            ans++;
            b += c;
        }
    }
    cout << ans << '\n';
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}