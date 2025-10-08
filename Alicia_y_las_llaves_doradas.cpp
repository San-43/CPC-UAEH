#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb push_back
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (auto &e : v)
        cin >> e;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        int lo = 0;
        int hi = n;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (v[mid] == x) {
                ans = mid;
                break;
            } else if (v[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        if (ans == -1)
            cout << 0 << ' ';
        else
            cout << ans + 1 << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    while (t--) {
        solve();
    }
    return 0;
}