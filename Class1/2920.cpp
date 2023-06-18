#include <iostream>
#include <string>
using namespace std;
int main() {
    int s[8];
    string str;
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
        str.push_back(s[i] + '0');
    }
    if (str.compare("12345678") == 0)
        cout << "ascending";
    else if (str.compare("87654321") == 0)
        cout << "descending";
    else
        cout << "mixed";
}