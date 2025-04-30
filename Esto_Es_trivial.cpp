#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> ans;
    vector<int> tmp;
    for (int i = n - 1;i >= 0; i--) {
        while(tmp.size() && tmp.back() <= v[i]) 
            tmp.pop_back();
        
        if(tmp.size()) 
            ans.push_back(tmp.back());
        else 
            ans.push_back(-1);

        tmp.push_back(v[i]);
    }
    for (int i = n - 1;i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << '\n';
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}