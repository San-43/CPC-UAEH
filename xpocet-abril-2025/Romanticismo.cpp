#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> m(n, vector<char>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];

    vector<vector<int>> a(n+1, vector<int>(n+1));
    vector<vector<int>> r = a, t = a;

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + (m[i-1][j-1]=='*');
        r[i][j] = r[i-1][j] + r[i][j-1] - r[i-1][j-1] + (m[i-1][j-1]=='#');
        t[i][j] = t[i-1][j] + t[i][j-1] - t[i-1][j-1] + (m[i-1][j-1]=='-');
      }
    }

    int q;
    cin >> q;
    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        int r1 = max(1, i - k);
        int c1 = max(1, j - k);
        int r2 = min(n, i + k); 
        int c2 = min(n, j + k);

        int as = a[r2][c2] - a[r1-1][c2] - a[r2][c1-1] + a[r1-1][c1-1];
        int rs = r[r2][c2] - r[r1-1][c2] - r[r2][c1-1] + r[r1-1][c1-1];
        int ts = t[r2][c2] - t[r1-1][c2] - t[r2][c1-1] + t[r1-1][c1-1];
        cout << as << " " << rs << " " << ts << "\n";  
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}