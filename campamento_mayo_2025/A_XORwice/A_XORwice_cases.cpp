#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist_t(1, 10000);
    uniform_int_distribution<int> dist_val(1, 1000000000);

    for (int file_idx = 7; file_idx <= 10; ++file_idx) {
        // Generar t aleatorio para este archivo
        int t = dist_t(rng);
        string in_file = "input" + to_string(file_idx) + ".in";
        string out_file = "input" + to_string(file_idx) + ".out";

        ofstream fin(in_file);
        ofstream fout(out_file);
        if (!fin || !fout) {
            cerr << "No se pudo crear los archivos " << in_file << " o " << out_file << "\n";
            return 1;
        }

        vector<pair<int, int>> cases;
        while ((int)cases.size() < t) {
            int a = dist_val(rng);
            int b = dist_val(rng);
            cases.emplace_back(a, b);
        }
        shuffle(cases.begin(), cases.end(), rng);

        fin << t << '\n';
        for (auto &p : cases) {
            fin << p.first << " " << p.second << '\n';
        }
        fin.close();

        for (auto &p : cases) {
            fout << (p.first ^ p.second) << '\n';
        }
        fout.close();
    }

    return 0;
}
