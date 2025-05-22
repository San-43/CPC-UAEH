#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// Parámetros
constexpr int NUM_SMALL  = 5;
constexpr int NUM_MAX    = 10;
constexpr int NUM_RANDOM = 5;

// Límites
constexpr int SMALL_MIN_N = 3;
constexpr int SMALL_MAX_N = 11;       // n pequeño máximo
constexpr int  MAX_N      = 10000000; // 10^7
constexpr ull MAX_VAL     = 1000000000ULL; // 10^9

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

    uniform_int_distribution<int>  dist_small_n(SMALL_MIN_N, SMALL_MAX_N);
    uniform_int_distribution<int>  dist_rand_n(SMALL_MIN_N, MAX_N);

    int file_id = 1;

    auto make_case = [&](int n, ull unique_val){
        // nombres case01.in / case01.out, etc.
        ostringstream siname, soutname;
        siname  << "case" << setw(2) << setfill('0') << file_id << ".in";
        soutname<< "case" << setw(2) << setfill('0') << file_id << ".out";

        ofstream fin(siname.str()), fout(soutname.str());
        if(!fin || !fout){
            cerr<<"Error abriendo "<<siname.str()<<"\n";
            exit(1);
        }

        // Prepara el array de tamaño n
        vector<ull> a(n);
        int pairs = (n - 1) / 2;

        // Primer elemento: el único
        a[0] = unique_val;

        // Genera pares con valores 1,2,3,...
        // garantizados distintos de unique_val porque unique_val > pairs
        for(int i = 0, v = 1; i < pairs; ++i, ++v){
            int idx = 1 + 2*i;
            a[idx]   = v;
            a[idx+1] = v;
        }

        // Coloca el único en posición aleatoria
        uniform_int_distribution<int> dist_pos(0, n-1);
        int p = dist_pos(rng);
        swap(a[0], a[p]);

        // Escribe .in
        fin << n << "\n";
        for(int i = 0; i < n; ++i){
            fin << a[i] << (i+1<n ? ' ' : '\n');
        }

        // Calcula XOR y escribe .out
        ull xr = 0;
        for(ull v : a) xr ^= v;
        fout << xr << "\n";

        cout<<"Generado "<<siname.str()
            <<" -> "<<soutname.str()<<"\n";
        ++file_id;
    };

    // 5 casos pequeños: n random en [3,11], unique_val = SMALL_MAX_N+1=12
    for(int i = 0; i < NUM_SMALL; ++i){
        int n = dist_small_n(rng);
        if(n % 2 == 0) ++n;
        make_case(n, SMALL_MAX_N + 1ULL);
    }

    // 10 casos máximos: n = 10^7, unique_val = MAX_VAL
    for(int i = 0; i < NUM_MAX; ++i){
        int n = MAX_N;
        if(n % 2 == 0) --n;  // asegurar impar; MAX_N=1e7 es par, así que n=1e7-1
        make_case(n, MAX_VAL);
    }

    // 5 casos aleatorios: n random en [3,1e7], unique_val = MAX_VAL-1
    for(int i = 0; i < NUM_RANDOM; ++i){
        int n = dist_rand_n(rng);
        if(n % 2 == 0) ++n;
        make_case(n, MAX_VAL - 1ULL - i);
    }

    return 0;
}
