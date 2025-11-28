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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    auto ok = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    vector<vector<int>> d(n, vector<int>(m, INF));

    queue<pair<int,int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'T') {
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = tmp.first + dx[i];
            int ny = tmp.second + dy[i];

            if(!ok(nx, ny)) continue;
            if(g[nx][ny] == '#') continue;
            if(d[nx][ny] <= d[tmp.first][tmp.second] + 1) continue;

            int nd = d[tmp.first][tmp.second] + 1;

            if(nd > k) continue;

            d[nx][ny] = nd;
            q.push(make_pair(nx, ny));
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'C' && d[i][j] <= k) ans++;
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