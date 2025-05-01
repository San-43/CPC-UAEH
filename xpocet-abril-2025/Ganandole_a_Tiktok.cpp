#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string tmp = s;
        reverse(s.begin(), s.end());
        if(tmp == s) {
            cout << tmp << '\n';
            continue;
        }
        string tmp2 = "";
        bool ok = false;
        do {
            int j = 0;
            string ans = "";
            for(int i = s.length() - 1; i >= 0; i--) {
                int sum = j;

                sum += s[i] - '0';
                sum += tmp[i] - '0';

                ans += (sum % 10) + '0';
                j = sum / 10;
            }
            if(j) {
                ans += j + '0';
            }
            tmp = ans;
            reverse(tmp.begin(), tmp.end());
            s = ans;
            tmp2 = ans;
            reverse(tmp2.begin(), tmp2.end());
            if(tmp2 == ans) {
                cout << tmp2 << '\n';
                ok = true;
                break;
            }
        } while (tmp2.length() < 5005);
        if(!ok) {
            cout << "-1\n";
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