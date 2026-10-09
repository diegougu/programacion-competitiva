#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int caso = 1; caso <= T; caso++) {
        int N;
        cin >> N;

        string nombres[100];
        int dias[100];

        for (int i = 0; i < N; i++) {
            cin >> nombres[i] >> dias[i];
        }

        int D;
        cin >> D;

        string tema;
        cin >> tema;

        int tiempo = -1;

        for (int i = 0; i < N; i++) {
            if (nombres[i] == tema) {
                tiempo = dias[i];
                break;
            }
        }

        cout << "Case " << caso << ": ";

        if (tiempo == -1 || tiempo > D + 5) {
            cout << "Do your own homework!";
        }
        else if (tiempo <= D) {
            cout << "Yesss";
        }
        else {
            cout << "Late";
        }

        cout << '\n';
    }

    return 0;
}
