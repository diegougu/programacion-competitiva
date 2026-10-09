#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d, r;

    while (cin >> n >> d >> r) {
        if (n == 0 && d == 0 && r == 0)
            break;

        vector<int> manana(n), tarde(n);

        for (int i = 0; i < n; i++)
            cin >> manana[i];

        for (int i = 0; i < n; i++)
            cin >> tarde[i];

        sort(manana.begin(), manana.end());
        sort(tarde.begin(), tarde.end());

        int total = 0;

        for (int i = 0; i < n; i++) {
            int jornada = manana[i] + tarde[n - 1 - i];

            if (jornada > d)
                total += (jornada - d) * r;
        }

        cout << total << '\n';
    }

    return 0;
}
