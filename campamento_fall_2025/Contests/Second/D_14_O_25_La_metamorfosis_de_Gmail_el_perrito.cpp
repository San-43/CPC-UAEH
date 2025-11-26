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
    int n, m;
    cin >> n >> m;
    if(n % m == 0) {
        cout << "X es divisible por Y" << edl;
    } else cout << "X no es divisible por Y" << edl;

    if(n < m) cout << "X es menor que Y" << edl;
    if(n > m) cout << "X es mayor que Y" << edl;
    if(n == m) cout << "X es igual que Y" << edl;
    if((n % m) & 1) cout << "El residuo es impar" << edl;
    else cout << "El residuo es par" << edl;
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