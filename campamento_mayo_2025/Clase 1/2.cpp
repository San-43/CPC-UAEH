#include <bits/stdc++.h>

using namespace std;

int dias[1000005];
long long acum[1000005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int q;
    cin >> q;
    for(int i = 1; i <= n; i++) {
        cin >> dias[i];
    }
    
    for(int i = 1; i <= n; i++) {
        acum[i] = acum[i - 1] + dias[i];
    }


    for(int i = 0; i < q; i++) { /// O(Q) pero Q = N entonces tenemos O(N).
        int r; // 1
        cin >> r; // 1
        cout << acum[r] << '\n';
    }
}