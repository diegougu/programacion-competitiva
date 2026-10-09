#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    int caso = 1;

    while (cin >> N >> Q) {
        if (N == 0 && Q == 0) {
            break;
        }

        vector<int> canicas(N);

        for (int i = 0; i < N; i++) {
            cin >> canicas[i];
        }

        sort(canicas.begin(), canicas.end());

        cout << "CASE# " << caso << ":\n";

        for (int i = 0; i < Q; i++) {
            int x;
            cin >> x;

            vector<int>::iterator it;
            it = lower_bound(canicas.begin(), canicas.end(), x);

            if (it != canicas.end() && *it == x) {
                cout << x << " found at "
                     << (it - canicas.begin() + 1) << '\n';
            } else {
                cout << x << " not found\n";
            }
        }

        caso++;
    }

    return 0;
}
