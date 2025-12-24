#include <bits/stdc++.h>

#define edl '\n'
using ll = long long;
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<double> a(n);
    double mx = 0;
    for(auto &e : a) {
        cin >> e;
        mx = max(mx, e);
    }

    auto ok = [&](double x) {
        ll tmp = 0;
        for(auto i : a) {
            tmp += (ll)(i / x);
        }

        return tmp >= k;
    };

    double l = 0, r = mx;
    for(int i = 0; i < 70; i++) {
        double mid = l + (r - l) / 2;
        if(ok(mid)) l = mid;
        else r = mid;
    }

    cout << setprecision(7) << l << edl;
}