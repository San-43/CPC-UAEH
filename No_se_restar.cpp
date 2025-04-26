#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 4 == 0)
        cout << "Maullin\n";
    else
        cout << "Benito\n";
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