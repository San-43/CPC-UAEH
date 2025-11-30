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
    long long n, m, q;
    cin >> n >> m >> q;

    unordered_map<long long, long long> mp;

    set<long long> ans;
    unordered_map<long long, long long> cub;
    long long quedan = n;
    while (q--) {
        long long l, r;
        cin >> l >> r;

        if (mp.count(l) == 0) {
            mp[l] = m;
            cub[m]++;
            ans.insert(m);
            quedan--;
        } else if (mp[l] == 0) {
            long long b = ans.empty() ? 0 : *ans.rbegin();
            if (quedan > 0)
                b = max(b, m);
            cout << b << edl;
            continue;
        }

        long long arriba = (mp[l] - r) + 1;
        long long abajo = mp[l] - arriba;
        if (l == 1 && n != 1) { /// l = 1 mp[l + 1]
            if (mp.count(l + 1) == 0) {
                mp[l + 1] = m;
                cub[m]++;
                ans.insert(m);
                quedan--;
            }
            if (--cub[mp[l + 1]] == 0)
                ans.erase(mp[l + 1]);
            mp[l + 1] += abajo;
            ans.insert(mp[l + 1]);
            cub[mp[l + 1]]++;
        } else if (l == n && l - 1 > 0) { /// l = n mp[l - 1]
            if (mp.count(l - 1) == 0) {
                mp[l - 1] = m;
                cub[m]++;
                ans.insert(m);
                quedan--;
            }
            if (--cub[mp[l - 1]] == 0)
                ans.erase(mp[l - 1]);
            mp[l - 1] += arriba;

            ans.insert(mp[l - 1]);
            cub[mp[l - 1]]++;
        } else if (l > 1 && l < n) { /// l dentro del rango mp[l - 1] mp[l + 1]
            if (mp.count(l + 1) == 0) {
                mp[l + 1] = m;
                cub[m]++;
                ans.insert(m);
                quedan--;
            }
            if (--cub[mp[l + 1]] == 0)
                ans.erase(mp[l + 1]);
            mp[l + 1] += abajo;
            ans.insert(mp[l + 1]);

            if (mp.count(l - 1) == 0) {
                mp[l - 1] = m;
                cub[m]++;
                ans.insert(m);
                quedan--;
            }
            if (--cub[mp[l - 1]] == 0)
                ans.erase(mp[l - 1]);
            mp[l - 1] += arriba;

            ans.insert(mp[l - 1]);
            cub[mp[l + 1]]++;
            cub[mp[l - 1]]++;
        }

        if (--cub[mp[l]] == 0) {
            ans.erase(mp[l]);
        }
        mp[l] = 0;
        long long b = ans.empty() ? 0 : *ans.rbegin();
        if (quedan > 0)
            b = max(b, m);
        cout << b << edl;

        /*cout << "array" << edl;
        for(auto i : mp) cout << i.first << " key " << i.second << edl;
        cout << edl;

        cout << "cubeta" << edl;
        for(auto i : cub) cout << i.first << " key " << i.second << edl;
        cout << edl;*/
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