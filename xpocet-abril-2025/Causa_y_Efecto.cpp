#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 5; i++) {
        if (n % 2 == 0) {
            cout << "Iniciando prueba " << i+1 << " en modo par\n";
            cout << "Tiempo actual " << n << " minutos\n";
            if (n > 50) {
                cout << "Advertencia: tiempo inestable\n";
                cout << "Ejecutando formula de recorte\n";
                n -= 10;
            } else {
                cout << "Rango de tiempo moderado\n";
                cout << "Ejecutando formula de regresion\n";
                n += 15;
            }
        } else {
            cout << "Iniciando prueba " << i+1 << " en modo impar\n";
            cout << "Tiempo actual " << n << " minutos\n";
            if (n > 50) {
                cout << "Advertencia: tiempo inestable\n";
                cout << "Ejecutando formula de recorte\n";
                n -= 10;
            } else {
                cout << "Rango de tiempo moderado\n";
                cout << "Ejecutando formula de regresion\n";
                n += 15;
            }
        }
        cout << "Nuevo tiempo " << n << " minutos\n\n";
        if(n == m){
            cout << "Prueba exitosa\n";
            return;
        }
    }

    cout << "Prueba fallida\n";

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
}