#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    stack<int> s;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if(c == 'M') {
            int x;
            cin >> x;
            s.push(x);
            sum += x;
        } else if (c == 'Q' && !s.empty()) {
            cout << sum << ' ' << s.top() << '\n';
        } else if(!s.empty()) {
            sum -= s.top();
            s.pop();
        }
    }
    cout << sum << '\n';
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