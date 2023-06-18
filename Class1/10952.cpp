#include <iostream>
using namespace std;
int main() {
    int a, b;
    while (true) {
        cin >> a;
        if (a == 0) break;
        cin >> b;
        cout << a + b << '\n';
    }
}