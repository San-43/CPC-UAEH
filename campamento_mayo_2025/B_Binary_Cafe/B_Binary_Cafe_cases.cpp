#include <bits/stdc++.h>
using namespace std;


int solve_case(int n, int k) {
    k = min(k, 30);
    return min(n, (1 << k) - 1) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    const int NUM_FILES = 20;

    for (int file_id = 8; file_id <= 10; ++file_id) {
        string in_name = "test" + to_string(file_id) + ".in";
        string out_name = "test" + to_string(file_id) + ".out";

        ofstream in_file(in_name);
        ofstream out_file(out_name);

        int t =1000; 
        in_file << t << "\n";

        for (int i = 0; i < t; ++i) {
            int n = 1e9;  // 1 ≤ n ≤ 1e9
            int k = rng() % 100 + 1;  // 1 ≤ k ≤ 1e9

            in_file << n << " " << k << "\n";

            int result = solve_case(n, k);
            out_file << result << "\n";
        }

        in_file.close();
        out_file.close();
    }

    return 0;
}
