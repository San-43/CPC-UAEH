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

template <typename T>
void fill_seq(vector<T> &v, T start = 1) {
    iota(v.begin(), v.end(), start);
}

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    vector<vector<string>> v(3, vector<string>(n));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    unordered_map<string, int> m;
    for(int i = 0; i < 3; i++) {
        for(auto s : v[i]) {
            m[s]++;
        }
    }

    vector<int> ans(3);
    for(int i = 0; i < 3; i++) {
        for(auto &s : v[i]) {
            if(m[s] == 1) ans[i] += 3;
            else if(m[s] == 2) ans[i] += 1;
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}