#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    while(s != "0") {
        bool validate;
        for(int i = 0; i < s.size(); i++) {
            if(s.at(i) == s.at(s.size() - 1 - i))
                validate = true;
            else {
                validate = false;
                break;
            }
        }
        if(validate)
            cout << "yes\n";
        else
            cout << "no\n";
        cin >> s;
    }

    return 0;
}