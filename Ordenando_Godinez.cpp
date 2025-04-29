#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    for(int i =0; i < n ; i++){
        string s;
        int x;
        cin >> s >> x;
        v[i] = make_pair(s, x);
    }

    sort(v.begin(), v.end(),  [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first; 
    });

    for(auto x : v) {
        cout << x.first << '\n';
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