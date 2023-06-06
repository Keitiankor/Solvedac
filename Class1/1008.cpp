#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout.precision(9);
    cout << fixed << (double)a / b;
    return 0;
}