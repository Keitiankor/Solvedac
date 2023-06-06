#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int line;
    cin >> line;
    for(int i = 0; i < line; i++) {
        string s;
        stack<char> stk;
        bool isVPS = true;
        cin >> s;
        for(char i : s) {
            if(i == '(')
                stk.push(i);
            else {
                if(!stk.empty() && stk.top() == '(')
                    stk.pop();
                else {
                    isVPS = false;
                    break;
                }
            }
        }
        if(!stk.empty()) isVPS = false;
        if(isVPS)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}