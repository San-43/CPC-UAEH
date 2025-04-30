#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    string a;
    string b;
    cin >> a >> b;
    int n;
    cin >> n;
    if (n == 1) {
        cout << a;
    } else if (n == 2) {
        cout << b;
    } else {
        n -= 2;
        string ans = "";
        while(n--) {
            ans = a + b;
            a = b;
            b = ans;
        }
        cout << ans;
    }


};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}