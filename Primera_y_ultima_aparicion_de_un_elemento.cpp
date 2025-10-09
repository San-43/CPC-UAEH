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
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(auto &e : v) cin >> e;
    sort(v.begin(), v.end());

    while(q--) {
        ll l;
        cin >> l;
        auto [low, up] = equal_range(v.begin(), v.end(), l);

        if(low == up) {
            cout << -1 << " " << -1 << edl;
        } else {
            int i = int(low - v.begin());
            int j = int(up - 1 - v.begin());
            cout << i+1 << " " << j+1 << edl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}