#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    map<int, string> m;
    m[0] = "abcdef";
    m[1] = "bc";
    m[2] = "abged";
    m[3] = "abgcd";
    m[4] = "fgbc";
    m[5] = "afgcd";
    m[6] = "afgcde";
    m[7] = "abc";
    m[8] = "abcdefg";
    m[9] = "abcdgf";

    vector<pair<int, string>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    for(int i = 0; i < n; i++) {
        int j = v[i].first;
        string tmp = v[i].second;
        bool band = true;
        if(tmp.length() != m[j].length()) {
            cout << "MAL\n";
        } else {
            for(auto c1 : tmp) {
                if(find(m[j].begin(), m[j].end(), c1) == m[j].end() || (count(tmp.begin(), tmp.end(), c1) > 1)) {
                    band = false;
                    break;
                }
            }
            band ? cout << "BIEN\n" : cout << "MAL\n";
        }
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