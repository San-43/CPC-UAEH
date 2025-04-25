#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    bitset<32> b(n);
    string s = b.to_string();
    auto x = s.find('1');
    cout << s.substr(x, s.length());
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}