#include <bits/stdc++.h>

using namespace std;

int dias[1000005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> dias[i];
    }

    int l, r;
    cin >> l >> r;

    long long ans = 0;
    for(int i = l; i <= r; i++) {
        ans = ans + dias[i];
    }

    cout << ans << '\n';
}