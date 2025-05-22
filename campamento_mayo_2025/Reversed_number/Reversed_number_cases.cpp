#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using uint = unsigned int;

uint reverse_bits(uint n) {
    uint k = 0;
    while (n > 0) {
        k <<= 1;
        k |= (n & 1);
        n >>= 1;
    }
    return k;
}

int main() {
    // Motor de RNG
    std::mt19937_64 rng(std::random_device{}());
    // Distribución uniforme de 0 a 2^32 - 1
    std::uniform_int_distribution<uint> dist(0, std::numeric_limits<uint>::max());
    
    for (int tc = 1; tc <= 20; ++tc) {
        // Generar nombre de fichero con dos dígitos
        char in_name[16], out_name[16];
        sprintf(in_name,  "case%02d.in",  tc);
        sprintf(out_name, "case%02d.out", tc);
        
        // Generar número de prueba
        uint n = dist(rng);
        
        // Calcular reverse bits
        uint k = reverse_bits(n);
        
        // Escribir .in
        ofstream fin(in_name);
        fin << n << "\n";
        fin.close();
        
        // Escribir .out
        ofstream fout(out_name);
        fout << k << "\n";
        fout.close();
        
        cout << "Generados " << in_name << " / " << out_name << "\n";
    }

    return 0;
}
