#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<string> sueños;
    string comando, nombre;

    while (n--) {
        cin >> comando;

        if (comando == "Sleep") {
            cin >> nombre;
            sueños.push(nombre);
        }
        else if (comando == "Kick") {
            if (!sueños.empty())
                sueños.pop();
        }
        else if (comando == "Test") {
            if (sueños.empty())
                cout << "Not in a dream\n";
            else
                cout << sueños.top() << '\n';
        }
    }

    return 0;
}
