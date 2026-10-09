#include <iostream>
using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        int edades[101] = {};

        for (int i = 0; i < n; i++) {
            int edad;
            cin >> edad;
            edades[edad]++;
        }

        bool primero = true;

        for (int i = 1; i <= 100; i++) {
            while (edades[i] > 0) {
                if (!primero) cout << ' ';
                cout << i;
                primero = false;
                edades[i]--;
            }
        }

        cout << '\n';
    }

    return 0;
}
