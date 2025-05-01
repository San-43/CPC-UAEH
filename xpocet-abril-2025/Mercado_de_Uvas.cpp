#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n, k;
    cin >> n >> k;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % k == 0) 
            count++;
    }
    cout << count << '\n';
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}