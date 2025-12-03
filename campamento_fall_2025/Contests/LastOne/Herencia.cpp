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

    vector<vector<int>> a(n+4);

    unordered_map<int, ll> mp;

    for (int i = 1; i <= n; i++) {
        int j;
        cin >> j;
        mp[i] = j;
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    if(n == 1) {
        cout << -1 << edl;
        return;
    }

    queue<int> q;
    vector<int> d(n+1, -1);
    int maxd = -1;
    d[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : a[u]) {
            if(d[v] == -1) {
                d[v] = d[u] + 1;
                maxd = max(maxd, d[v]);
                q.push(v);
            }
        }
    }

    auto ok = [&](int mid) {
        vector<ll> tmp;
        for(int i = 2; i <= n; i++) {
            if(d[i] <= mid) tmp.push_back(mp[i]);
        } 

        if(tmp.size() < k) return false;
        sort(tmp.begin(), tmp.end());

        ll sum = 0;
        for(int i = 0; i < k; i++) {
            sum += tmp[i];
        }
        return sum <= x;
    };

    int l = 1;
    int r = maxd;

    while(l < r) {
        int mid = l + (r - l) / 2;
        if(ok(mid)) r = mid;
        else l = mid + 1;
    }

    if(!ok(l)) cout << -1 << edl;
    else cout << l << edl;
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