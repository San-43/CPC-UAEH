#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    string s;
    string f;
    getline(cin, s);
    getline(cin, f);
    string tmp1;
    for (int i = 0; i < s.length(); i++){ 
        if (s[i] != '#'){
            tmp1.push_back(s[i]);
        } else {
            if (tmp1.length() != 0) {
                tmp1.pop_back();
            }
        }
    }
    string tmp2;
    for (int i = 0; i < f.length(); i++){ 
        if (f[i] != '#'){
            tmp2.push_back(f[i]);
        } else {
            if (tmp2.length() != 0) {
                tmp2.pop_back();
            }
        }
    }

    tmp1 == tmp2 ? cout << "SI\n" : cout << "NO\n";
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}