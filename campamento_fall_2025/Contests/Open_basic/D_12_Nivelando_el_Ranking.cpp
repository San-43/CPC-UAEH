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

struct bro {
    string s;
    int t;
    int c;
};

void solve() {
    int n;
    cin >> n;

    const int cat[3] = {0, 300, 400};

    vector<vector<bro>> a(3, vector<bro>());
    for (int i = 0; i < n; i++) {
        bro x;
        cin >> x.s >> x.t >> x.c;

        int l = 0;
        if (1 <= x.t && x.t <= 30)
            l = 2;
        else if (x.t <= 90)
            l = 1;
        else
            l = 0;

        int r = l;

        if (l < 2 && x.c >= cat[l + 1])
            r++;
        else if (l > 0 && x.c < cat[l])
            r--;

        a[r].push_back(x);
    }

    for (int i = 2; i >= 0; i--) {
        sort(a[i].begin(), a[i].end(), [](bro &x, bro &y) {
            if (x.t != y.t)
                return x.t < y.t;
            else if (x.c != y.c)
                return x.c > y.c;
            return false;
        });
        int m = a[i].size();
        for(int j = 0; j < min(3, m); j++) {
            cout << a[i][j].s << edl;
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