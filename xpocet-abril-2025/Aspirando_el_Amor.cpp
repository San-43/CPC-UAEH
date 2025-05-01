#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++) {

        char c;
        cin >> c;
        if (c == '<') {
            c1++;
        } else  {
            c2++;
        }
    }

    if(c1 == 0 )
        cout << 0;
    else if (c2 == 0) 
        cout << 0;
    else if (c1 <= c2) {
        cout << c1;
    } else 
        cout << c2;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}