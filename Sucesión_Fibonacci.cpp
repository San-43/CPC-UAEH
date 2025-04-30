#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

long long fib(int n){

    if (n <= 1) return n;

    long long curr = 0;

    long long prev1 = 1;
    long long prev2 = 0;

    for (int i = 2; i <= n; i++){

        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

void solve () {
    int n;
    cin >> n;
    cout << fib(n);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}