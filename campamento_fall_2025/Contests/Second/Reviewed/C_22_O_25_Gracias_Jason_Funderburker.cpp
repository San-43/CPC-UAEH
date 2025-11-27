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
    ll n, d;
    cin >> n >> d;
    vi a(n);
    for(auto &e : a) cin >> e;

    sort(a.begin(), a.end());

    for(int i = 0; i < n - 1; i++) {
        if(abs(a[i] - a[i+1]) == d) {
            cout << "Querido Dios, no tengo suficientes palabras para expresar lo mucho que estoy agradecido al mundo por la existencia de Jason Funderburker." << edl;
            return;
        }
    }
    cout << "Te perdono, Jason Funderburker." << edl;
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