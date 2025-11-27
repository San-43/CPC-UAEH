#include <bits/stdc++.h>
#include <chrono>   // semilla
#include <random>   // random
using namespace std;

int main() {
    // Número de casos a generar (puedes cambiarlo)
    int numCases = 10;

    // Cambia esta ruta a la carpeta donde quieras guardar tus casos
    // Ejemplo: "C:\\Users\\TuNombre\\Desktop\\CountingSort\\cases\\case"
    string basePath = "D:\\Projects\\CPC-UAEH\\campamento_fall_2025\\Counting Sort\\1\\cases\\case";

    // Semilla para el generador aleatorio
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    // Rangos según el problema:
    // 1 <= N <= 1e6
    // 0 <= a_i <= 1e6
    uniform_int_distribution<int> distN(1, 1000000);
    uniform_int_distribution<int> distA(0, 1000000);

    const int MAXA = 1000000;
    vector<int> cnt(MAXA + 1);

    for (int id = 1; id <= numCases; id++) {
        // Archivo de entrada: case1.in, case2.in, ...
        string rutaIn = basePath + to_string(id) + ".in";
        ofstream salidaIn(rutaIn);

        if (!salidaIn.is_open()) {
            cerr << "No se pudo abrir el archivo de entrada: " << rutaIn << "\n";
            continue; // intenta el siguiente caso
        }

        // Generamos N
        int N = distN(generator);
        salidaIn << N << "\n";

        // Generamos el arreglo a_1 ... a_N
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            a[i] = distA(generator);
            salidaIn << a[i];
            if (i + 1 < N) salidaIn << " ";
        }
        salidaIn << "\n";
        salidaIn.close();

        // Limpiamos el arreglo de conteo
        fill(cnt.begin(), cnt.end(), 0);

        // Contamos ocurrencias (counting sort)
        for (int i = 0; i < N; i++) {
            cnt[a[i]]++;
        }

        // Archivo de salida correspondiente: case1.out, case2.out, ...
        string rutaOut = basePath + to_string(id) + ".out";
        ofstream salidaOut(rutaOut);

        if (!salidaOut.is_open()) {
            cerr << "No se pudo abrir el archivo de salida: " << rutaOut << "\n";
            continue;
        }

        // Reconstruimos el arreglo ordenado y lo escribimos
        bool first = true;
        for (int value = 0; value <= MAXA; value++) {
            while (cnt[value] > 0) {
                if (!first) salidaOut << " ";
                first = false;
                salidaOut << value;
                cnt[value]--;
            }
        }
        salidaOut << "\n";
        salidaOut.close();
    }

    return 0;
}
