#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = " ";

    while (true) {
        bool flag = true;
        stack<char> brackets;
        getline(cin, s);
        if (s == ".") break;

        for (int i = 0; s[i] != '.'; i++) {
            if (s[i] == '(' || s[i] == '[') brackets.push(s[i]);

            if (s[i] == ')') {
                if (!brackets.empty() && brackets.top() == '(') {
                    brackets.pop();
                } else {
                    flag = false;
                }
            }

            if (s[i] == ']') {
                if (!brackets.empty() && brackets.top() == '[') {
                    brackets.pop();
                } else {
                    flag = false;
                }
            }
        }
        if (!brackets.empty()) flag = false;

        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}