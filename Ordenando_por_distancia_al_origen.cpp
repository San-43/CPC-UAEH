#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

struct pt {
    int x;
    int y;
    double dist;
};

void solve () {
    int n;
    cin >> n;
    vector<pt> v(n);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        double dist = sqrt(pow(x, 2) + pow(y, 2));
        pt p = {x, y, dist};
        v[i] = p;
    }

    sort(v.begin(), v.end(), [](pt &a, pt &b) {
        if(a.dist != b.dist) {
            return a.dist < b.dist;
        }
        if(a.x != b.x) {
            return a.x < b.x;
        } 
        return a.y < b.y;
    });
    for (auto p : v) {
        cout << p.x << " " << p.y << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}