#include <bits/stdc++.h>
#include <chrono>   // semilla
#include <random>   // random
using namespace std;

int main() {
    // Número de casos a generar (puedes cambiarlo)
    int numCases = 10;

    // Cambia esta ruta a la carpeta donde quieras guardar tus casos
    // Ejemplo: "C:\\Users\\TuNombre\\Desktop\\StaticRangeSum\\cases\\case"
    string basePath = "D:\\Projects\\CPC-UAEH\\campamento_fall_2025\\Static Range Sum Queries\\3\\cases\\case";

    // Semilla para el generador aleatorio
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    // Rangos según el problema:
    // 1 <= N <= 1e6
    // 1 <= Q <= 1e6
    // 1 <= a_i <= 1e9
    uniform_int_distribution<int> distN(1, 1000000);
    uniform_int_distribution<int> distQ(1, 1000000);
    uniform_int_distribution<int> distA(1, 1000000000);

    for (int id = 1; id <= numCases; id++) {
        // Archivo de entrada: case1.in, case2.in, ...
        string rutaIn = basePath + to_string(id) + ".in";
        ofstream salidaIn(rutaIn);

        if (!salidaIn.is_open()) {
            cerr << "No se pudo abrir el archivo de entrada: " << rutaIn << "\n";
            continue; // intenta el siguiente caso
        }

        // Generamos N y Q
        int N = distN(generator);
        int Q = distQ(generator);
        salidaIn << N << " " << Q << "\n";

        // Generamos el arreglo a_1 ... a_N
        vector<long long> a(N + 1);
        vector<long long> pref(N + 1);
        pref[0] = 0;

        for (int i = 1; i <= N; i++) {
            a[i] = distA(generator);
            pref[i] = pref[i - 1] + a[i];

            salidaIn << a[i];
            if (i < N) salidaIn << " ";
        }
        salidaIn << "\n";

        // Generamos Q queries: cada una es un par (L, R) con 1 <= L <= R <= N
        uniform_int_distribution<int> distL(1, N);
        vector<pair<int,int>> queries(Q);

        for (int i = 0; i < Q; i++) {
            int L = distL(generator);
            uniform_int_distribution<int> distR(L, N);
            int R = distR(generator);

            queries[i] = {L, R};
            salidaIn << L << " " << R << "\n";
        }
        salidaIn.close();

        // Archivo de salida correspondiente: case1.out, case2.out, ...
        string rutaOut = basePath + to_string(id) + ".out";
        ofstream salidaOut(rutaOut);

        if (!salidaOut.is_open()) {
            cerr << "No se pudo abrir el archivo de salida: " << rutaOut << "\n";
            continue;
        }

        // Para cada query (L, R), la respuesta es pref[R] - pref[L - 1]
        for (int i = 0; i < Q; i++) {
            int L = queries[i].first;
            int R = queries[i].second;
            long long ans = pref[R] - pref[L - 1];
            salidaOut << ans << "\n";
        }

        salidaOut.close();
    }

    return 0;
}
