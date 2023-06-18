#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, v;
    cin >> a >> b >> v;

    int height = v - a;
    int days   = height / (a - b);
    if(height % (a - b) != 0)
        days++;
    days++;

    cout << days;

    return 0;
}