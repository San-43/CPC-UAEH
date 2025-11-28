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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int l = 0;
    int r = 0;
    for(auto &e : a) {
        cin >> e;
        r = max(r, e);
    }
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int count = 0;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(mid > a[i]) count++;
            else count = 0;
            if(count > k) {
                ok = false;
            }
        }

        if(ok) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << edl;

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