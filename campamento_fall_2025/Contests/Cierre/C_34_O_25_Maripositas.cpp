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
    int t, n, k;
    cin >> t >> n >> k;
    vi a(t + 5, 0);
    while(n--) {
        int l, r;
        cin >> l >> r;
        for(int i = l; i <= r; i++) {
            a[i]++;
        }
    }
    
    for(int i = 1; i <= t; i++) {
        if(a[i] == 0) {
            int count = 0;
            int l = i;
            while(a[l] == 0 && l <= t) {
                count++;
                l++;
                if(count == k) {
                    cout << "SI" << edl;
                    return;
                }
            }
        }
    }
    cout << "NO" << edl;
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