#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;

    while (getline(cin, s)) {
        stack<char> pila;
        bool correcto = true;

        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{' || c == '<') {
                pila.push(c);
            }
            else if (c == ')' || c == ']' || c == '}' || c == '>') {
                if (pila.empty()) {
                    correcto = false;
                    break;
                }

                char tope = pila.top();
                pila.pop();

                if ((c == ')' && tope != '(') ||
                    (c == ']' && tope != '[') ||
                    (c == '}' && tope != '{') ||
                    (c == '>' && tope != '<')) {
                    correcto = false;
                    break;
                }
            }
        }

        if (!pila.empty()) {
            correcto = false;
        }

        if (correcto) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
