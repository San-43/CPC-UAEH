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
constexpr int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto ok = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    auto ok2 = [&](int x, int y, int nx, int ny) {
        if (!ok(nx, ny) || !ok(x, y))
            return false;
        if (a[nx][ny] != '.')
            return false;

        if (abs(nx - x) == 1 && abs(ny - y) == 1) {
            if (a[x][ny] == '*' || a[nx][y] == '*')
                return false;
        }

        return true;
    };

    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    vector<pair<int, int>> st;

    st.emplace_back(n - 1, m - 1);

    vis[n - 1][m - 1] = true;

    while (!st.empty()) {
        pair<int, int> tmp = st.back();
        st.pop_back();

        for (int i = 0; i < 8; i++) {
            int nx = tmp.first + ddx[i];
            int ny = tmp.second + ddy[i];

            if (ok2(tmp.first, tmp.second, nx, ny) && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                st.emplace_back(nx, ny);
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (vis[x][y]) {
            cout << "Corre Maullin" << edl;
        } else {
            cout << "LoL Que Mal" << edl;
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