#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int l = s.length();
    while(n--) {
        long long x;
        cin >> x;
        if (x <= l) {
            cout << s[x-1] << '\n';
        } else {
            int count = 1;
            while(x > l) {
                x -= l - count;
                count++;
            }
            cout << s[x - count] << '\n';
        }
    }
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