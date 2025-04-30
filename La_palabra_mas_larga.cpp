#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

string abc = "abcdefghijklmnñopqrstuvwxyz";

void solve () {
    string s;
    getline(cin, s);
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
        if(find(abc.begin(), abc.end(), s[i]) != abc.end()) {
            tmp++;
        } else {
            
            tmp = 0;
        }
        ans = max(tmp, ans);
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