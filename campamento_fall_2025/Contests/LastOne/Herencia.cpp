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

    vector<vector<pair<int, int>>> a(n + 5, vector<pair<int, int>>());

    unordered_map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int j;
        cin >> j;
        mp[i] = j;
    }

    if (n == 1) {
        cout << -1 << edl;
        return;
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].emplace_back(y, mp[y]);
    }

    for (int i = 1; i < n; i++) {
        if (!a[i].empty()) {
            sort(a[i].begin(), a[i].end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second < b.second;
            });
        }
    }

    /*for(int i = 1; i < n; i++) {
        cout << "i = " << i << edl;
        for(auto j : a[i]) {
            cout << j.first << " " << j.second << edl;
        }
    }*/

    int nodo = 1;
    queue<int> q;
    vector<int> ans(n, -1);

    ans[nodo] = 0;
    q.push(nodo);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : a[u]) {
            if(ans[v.first] == -1) {
                ans[v.first] = ans[u] + 1;
                q.push(v.first);
                if(v.second <= x) {
                    x -= v.second;
                    if(x == 0 && k > 0) {
                        cout << -1 << edl;
                        return;
                    } else {
                        k--;
                        if(k == 0) {
                            cout << ans[v.first] << edl;
                            return;
                        }
                    }
                }
            }
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