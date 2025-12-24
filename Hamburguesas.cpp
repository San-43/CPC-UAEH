#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    string s;
    cin >> s;
    ll nb, ns, nc;
    ll pb, ps, pc;
    cin >> nb >> ns >> nc >> pb >> ps >> pc;
    ll r;
    cin >> r;

    int sb = 0, ss = 0, sc = 0;
    for(const auto &e : s) {
        if(e == 'P') sb++;
        else if (e == 'S') ss++;
        else sc++;
    }
    auto ok = [&](ll x) {
        ll cb = max(0LL, x*sb - nb)  ;
        ll cs = max(0LL, x*ss - ns)  ;
        ll cc = max(0LL, x*sc - nc)  ;
        ll total = cb*pb + cs*ps + cc*pc;

        return total <= r;
    };

    ll lo = 0;
    ll hi = 1e13;
    while (lo + 1 < hi) {
        ll mid = lo + (hi-lo)/2;
        if (ok(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << edl;
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