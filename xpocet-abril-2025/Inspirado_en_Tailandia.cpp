#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;
unsigned long long ans = 0;
void dfs(int x, int y, vector<vector<char>>& v, vector<vector<bool>>& visited, string &s) {
    int n = v.size();
    int m = v[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) {
        return;
    };

    visited[x][y] = true;
    s += v[x][y];
    cout << s << "\n";
    bitset<64> b(s);
    ans = max(ans, b.to_ullong());
    dfs(x + 1, y, v, visited, s); 
    cout << s << "\n";
    dfs(x - 1, y, v, visited, s); 
    cout << s << "\n";
    dfs(x, y + 1, v, visited, s); 
    cout << s << "\n";
    dfs(x, y - 1, v, visited, s); 
    cout << s << "\n";
    
}


void solve () {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m, 0));
    for(int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for(int i = 0; i< n; i++) {
        for(int j = 0; j < m; j++) {
            string s1 = "";
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            dfs(1, 1, v, visited, s1);
        }
    }

    cout << ans;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}