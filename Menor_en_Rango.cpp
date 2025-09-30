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

    vector<int> lg(n + 1, 0);
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;

    int LG = lg[n] + 1;

    vector<vector<pair<ll, int>>> st(LG, vector<pair<ll, int>>(n));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st[0][i] = {x, i};
    }

    auto best = [](const pair<ll,int>& x, const pair<ll,int>& y) {
        return min(x, y);
    };

    for (int k = 1; k < LG; k++)
        for (int i = 0; i + (1 << k) <= n; i++)
            st[k][i] = best(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);

    int l, r; 
    cin >> l >> r;  
    int k = lg[r - l + 1];
    auto ans = min(st[k][l], st[k][r - (1 << k) + 1]);   

    cout << ans.second << edl;
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