#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    long long n;
    cin >> n;
    if (n > 1) {
        while(n > 1) {
            cout<< n << " ";
            if (n % 2 == 0) {
                n/=2;
            } else {
                n = n*3+1;
            }
        }
        cout << n << '\n';
        return;
    } else 
        cout << "1\n";

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}