#include <bits/stdc++.h>
#include <chrono>   // semilla
#include <random>   // random
using namespace std;

int main() {
    // Número de casos a generar (puedes cambiarlo)
    int numCases = 10;

    // Cambia esta ruta a la carpeta donde quieras guardar tus casos
    // Ejemplo: "C:\\Users\\TuNombre\\Desktop\\CheeringLetters\\cases\\case"
    string basePath = "D:\\Projects\\CPC-UAEH\\campamento_fall_2025\\Counting Sort\\2\\cases\\case";

    // Semilla para el generador aleatorio
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    // Rangos según el problema:
    // 1 <= N <= 1e6
    // 1 <= Q <= 1e6
    // S y consultas: letras 'a' - 'z'
    uniform_int_distribution<int> distN(1, 1000000);
    uniform_int_distribution<int> distQ(1, 1000000);
    uniform_int_distribution<int> distLetter(0, 25); // para 'a'..'z'

    for (int id = 1; id <= numCases; id++) {
        // Rutas de los archivos de entrada y salida: case1.in, case1.out, ...
        string rutaIn  = basePath + to_string(id) + ".in";
        string rutaOut = basePath + to_string(id) + ".out";

        ofstream salidaIn(rutaIn);
        if (!salidaIn.is_open()) {
            cerr << "No se pudo abrir el archivo de entrada: " << rutaIn << "\n";
            continue; // intenta el siguiente caso
        }

        // Generamos N
        int N = distN(generator);
        // Generamos la cadena S de longitud N
        string S(N, 'a');
        for (int i = 0; i < N; i++) {
            char c = char('a' + distLetter(generator));
            S[i] = c;
        }

        // Generamos Q
        int Q = distQ(generator);

        // Escribimos N, S y Q en el .in
        salidaIn << N << "\n";
        salidaIn << S << "\n";
        salidaIn << Q << "\n";

        // Precalculamos frecuencias de cada letra en S
        long long freq[26];
        for (int i = 0; i < 26; i++) freq[i] = 0;
        for (char c : S) {
            freq[c - 'a']++;
        }

        // Generamos consultas (cada una es un carácter 'a'..'z')
        vector<char> queries(Q);
        for (int i = 0; i < Q; i++) {
            char c = char('a' + distLetter(generator));
            queries[i] = c;
            salidaIn << c << "\n";
        }
        salidaIn.close();

        // Ahora generamos el archivo de salida .out
        ofstream salidaOut(rutaOut);
        if (!salidaOut.is_open()) {
            cerr << "No se pudo abrir el archivo de salida: " << rutaOut << "\n";
            continue;
        }

        // Para cada consulta, imprimimos la frecuencia de esa letra en S
        for (int i = 0; i < Q; i++) {
            char c = queries[i];
            long long ans = freq[c - 'a'];
            salidaOut << ans << "\n";
        }

        salidaOut.close();
    }

    return 0;
}
