#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, N;

    while (cin >> H >> W >> N) {
        if (H == 0 && W == 0 && N == 0) {
            break;
        }

        vector<vector<int>> mapa(H, vector<int>(W));
        vector<vector<int>> nuevo(H, vector<int>(W));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> mapa[i][j];
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int dia = 0; dia < N; dia++) {
            nuevo = mapa;

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                            if (mapa[ni][nj] == (mapa[i][j] + 1) % H) {
                                nuevo[ni][nj] = mapa[i][j];
                            }
                        }
                    }
                }
            }

            mapa = nuevo;
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (j > 0) cout << " ";
                cout << mapa[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
