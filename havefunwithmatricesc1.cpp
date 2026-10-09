#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int caso = 1; caso <= T; caso++) {
        int n;
        cin >> n;

        int a[10][10];

        for (int i = 0; i < n; i++) {
            string fila;
            cin >> fila;

            for (int j = 0; j < n; j++) {
                a[i][j] = fila[j] - '0';
            }
        }

        int m;
        cin >> m;

        while (m--) {
            string op;
            cin >> op;

            if (op == "row") {
                int x, y;
                cin >> x >> y;
                x--;
                y--;

                for (int j = 0; j < n; j++) {
                    int temp = a[x][j];
                    a[x][j] = a[y][j];
                    a[y][j] = temp;
                }
            }
            else if (op == "col") {
                int x, y;
                cin >> x >> y;
                x--;
                y--;

                for (int i = 0; i < n; i++) {
                    int temp = a[i][x];
                    a[i][x] = a[i][y];
                    a[i][y] = temp;
                }
            }
            else if (op == "inc") {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        a[i][j] = (a[i][j] + 1) % 10;
                    }
                }
            }
            else if (op == "dec") {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        a[i][j] = (a[i][j] + 9) % 10;
                    }
                }
            }
            else if (op == "transpose") {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        int temp = a[i][j];
                        a[i][j] = a[j][i];
                        a[j][i] = temp;
                    }
                }
            }
        }

        cout << "Case #" << caso << '\n';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}
