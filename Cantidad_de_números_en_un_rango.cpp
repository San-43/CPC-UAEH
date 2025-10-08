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

vector<bool> prime;


vector<ll> sieve(int n)
{
    vector<bool> s(n + 1, true);
    prime = s;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vi res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p * p);
        }
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi v = sieve(1000005);

    while(q--) {
        ll l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        auto low = lower_bound(v.begin(), v.end(), l);
        auto up = upper_bound(v.begin(), v.end(), r);
        cout << up - low << edl;
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