#include <bits/stdc++.h>

#define edl '\n'
using ll = long long;
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (n / 10) + (n % 10) << edl;
    }
}