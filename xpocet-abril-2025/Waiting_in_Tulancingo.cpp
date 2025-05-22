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
    int a;
    int b;
    int index;
};

void solve() {
    int x, n;
    cin >> x >> n;
    vector<vector<int>> v(n, vector<int>(4, 0));
    int minl = INT32_MAX;
    int maxr = 0;
    vector<int> suben(105, 0);
    vector<bool> bajan(105, 0);
    map<int, pair<int, int>> ans;
    vector<bro> pq;
    for(int i = 0; i < x; i++) {
        int l, r;
        cin >> l >> r;
        minl = min(l, minl);
        maxr = max(maxr, r);
        suben[l]++;
        bajan[r] = 1;
        bro t = {l, r, i};
        pq.push_back(t);
    }

    
    sort(pq.begin(), pq.end(), [](const bro& t, const bro& f) {
        if (t.a != f.a) return t.a > f.a;  
        if (t.b != f.b) return t.b > f.b;  
        return t.index > f.index;                        
    });

    for(int i = minl; i <= maxr; i++) {
        if(bajan[i]) {
            for(int k = 0; k < n; k++) {
                if(v[k][1] == i) {
                    v[k][1] = 0;
                }
                if (v[k][2] == i) {
                    v[k][2] = 0;
                }
                if (v[k][0] == i) {
                    v[k][0] = v[k][1];
                    v[k][1] = 0;
                } 
                if (v[k][3] == i) {
                    v[k][3] = v[k][2];
                    v[k][2] = 0;
                }
            }
        }

        while(suben[i]) {
            bro tmp = pq.back();
            pq.pop_back();
            bool ok = false;
            for(int k = 0; k < n && !ok; k++) {
                if(v[k][0] == 0) {
                    ans[tmp.index] = make_pair(k, 0);
                    v[k][0] = tmp.b;
                    break;
                } else if (v[k][3] == 0) {
                    ans[tmp.index] = make_pair(k, 3);
                    v[k][3] = tmp.b;
                    break;
                } else if (v[k][1] == 0) {
                    ans[tmp.index] = make_pair(k, 1);
                    v[k][1] = tmp.b;
                    break;
                } else if (v[k][2] == 0) {
                    ans[tmp.index] = make_pair(k, 2);
                    v[k][2] = tmp.b;
                    break;
                }
                if(k == n - 1)
                    ok = true;
            }
            suben[i]--;
            if(ok)
                ans[tmp.index] = make_pair(-1, 0);
        }
    }

    for(auto c : ans) {
        pair<int, int> tmp = c.second;
        if(tmp.first != -1) {
            cout << tmp.first+1 << ' ' << tmp.second+1 << edl;
        } else {
            cout << -1 << edl;
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