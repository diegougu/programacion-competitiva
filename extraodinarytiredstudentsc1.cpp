#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, caso = 1;

    while (cin >> n && n != 0) {
        vector<int> A(n), B(n), C(n);

        for (int i = 0; i < n; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        int tiempo = 0;
        int despiertos;

        while (true) {
            despiertos = 0;

            for (int i = 0; i < n; i++) {
                int ciclo = A[i] + B[i];
                int estado = C[i] % ciclo;

                if (estado < A[i]) {
                    despiertos++;
                }
            }

            if (despiertos == n) {
                cout << "Case " << caso++ << ": " << tiempo << '\n';
                break;
            }

            bool cambio = false;

            for (int i = 0; i < n; i++) {
                int ciclo = A[i] + B[i];
                int estado = C[i] % ciclo;

                if (estado == A[i] - 1) {
                    int dormidos = 0;

                    for (int j = 0; j < n; j++) {
                        int otroCiclo = A[j] + B[j];
                        int otroEstado = C[j] % otroCiclo;

                        if (otroEstado >= A[j]) {
                            dormidos++;
                        }
                    }

                    if (dormidos > n - dormidos) {
                        C[i] = (C[i] + 1) % ciclo;
                        cambio = true;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                int ciclo = A[i] + B[i];
                int estado = C[i] % ciclo;

                if (estado != A[i] - 1 || !cambio) {
                    C[i] = (C[i] + 1) % ciclo;
                }
            }

            tiempo++;

            if (tiempo > 100000) {
                cout << "Case " << caso++ << ": -1\n";
                break;
            }
        }
    }

    return 0;
}
