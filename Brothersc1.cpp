#include <iostream>
using namespace std;

int main() {
    int N, R, C, K;

    while (cin >> N >> R >> C >> K) {
        if (N == 0 && R == 0 && C == 0 && K == 0)
            break;

        int a[100][100], b[100][100];

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> a[i][j];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (K--) {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    b[i][j] = a[i][j];

            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    int enemigo = (a[i][j] + 1) % N;

                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (x >= 0 && x < R && y >= 0 && y < C) {
                            if (a[x][y] == enemigo)
                                b[x][y] = a[i][j];
                        }
                    }
                }
            }

            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    a[i][j] = b[i][j];
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (j > 0)
                    cout << ' ';
                cout << a[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
