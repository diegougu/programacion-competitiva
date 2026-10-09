#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;

    while (cin >> N) {
        vector<int> libros(N);

        for (int i = 0; i < N; i++) {
            cin >> libros[i];
        }

        int M;
        cin >> M;

        sort(libros.begin(), libros.end());

        int izquierda = 0;
        int derecha = N - 1;
        int mejorI = 0, mejorJ = 0;
        int menorDiferencia = 1000001;

        while (izquierda < derecha) {
            int suma = libros[izquierda] + libros[derecha];

            if (suma == M) {
                int diferencia = libros[derecha] - libros[izquierda];

                if (diferencia < menorDiferencia) {
                    menorDiferencia = diferencia;
                    mejorI = libros[izquierda];
                    mejorJ = libros[derecha];
                }

                izquierda++;
                derecha--;
            }
            else if (suma < M) {
                izquierda++;
            }
            else {
                derecha--;
            }
        }

        cout << "Peter should buy books whose prices are "
             << mejorI << " and " << mejorJ << ".\n\n";
    }

    return 0;
}
