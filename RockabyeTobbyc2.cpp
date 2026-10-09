#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Medicamento {
    int tiempo;
    int prioridad;
    string nombre;
    int frecuencia;
};

struct Comparador {
    bool operator()(const Medicamento& a, const Medicamento& b) {
        if (a.tiempo != b.tiempo)
            return a.tiempo > b.tiempo;
        return a.prioridad > b.prioridad;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        priority_queue<Medicamento, vector<Medicamento>, Comparador> pq;

        for (int i = 0; i < n; i++) {
            string nombre;
            int frecuencia;

            cin >> nombre >> frecuencia;

            pq.push({frecuencia, i, nombre, frecuencia});
        }

        for (int i = 0; i < k; i++) {
            Medicamento actual = pq.top();
            pq.pop();

            cout << actual.tiempo << " " << actual.nombre << '\n';

            actual.tiempo += actual.frecuencia;
            pq.push(actual);
        }
    }

    return 0;
}
