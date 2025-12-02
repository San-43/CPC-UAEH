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
    ll n, x, k;
    cin >> n >> x >> k;
    vector<vector<int>> a(n+5, vector<int>());

    unordered_map<int, int> mp;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[i] = x;
    }

    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    int l = 0;
    int r = a.size();
    int nodo = 1;
    ll tmp = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        ll sum = 0;
        
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