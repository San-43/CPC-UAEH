#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    queue<string> a;
    queue<string> t;
    for(int i =0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "LLEGA") {
            cin >> s;
            if(s == "ALUMNO") {
                cin >> s;
                a.push(s);
            } else {
                cin >> s;
                t.push(s);
            }
        } else {
            if (!t.empty()) {
                cout << t.front() << '\n';
                t.pop();
            } else if(!a.empty()) {
                cout << a.front() << '\n';
                a.pop();
            }
        }
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