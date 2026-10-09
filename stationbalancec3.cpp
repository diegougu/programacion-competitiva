#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int C, S;
    int set_num = 0;

    while (cin >> C >> S) {
        int mass[2 * C];
        set_num++;

        for (int i = 0; i < S; i++) {
            cin >> mass[i];
        }

        for (int i = S; i < 2 * C; i++) {
            mass[i] = 0;
        }

        sort(mass, mass + 2 * C);

        vector<int> centrifuge[C];
        int sum[C];
        double sum_of_all = 0;

        for (int i = 0; i < C; i++) {
            if (mass[i])
                centrifuge[i].push_back(mass[i]);

            if (mass[2 * C - 1 - i])
                centrifuge[i].push_back(mass[2 * C - 1 - i]);

            sum[i] = 0;
            sum[i] += mass[i];
            sum[i] += mass[2 * C - 1 - i];

            sum_of_all += sum[i];
        }

        double avg = sum_of_all / C;
        double diff = 0;

        cout << "Set #" << set_num << '\n';

        for (int i = 0; i < C; i++) {
            cout << setw(2) << i << ":";

            for (int j : centrifuge[i])
                cout << " " << j;

            cout << '\n';
            diff += abs(avg - sum[i]);
        }

        cout << fixed << setprecision(5);
        cout << "IMBALANCE = " << diff << "\n\n";
    }

    return 0;
}
