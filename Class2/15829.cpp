#include <cmath>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int r = 31;
    const int m = 1234567891;

    long long hash = 0;

    int l;
    cin >> l;
    string s;
    cin >> s;

    for(int i = 0; i < l; i++) {
        long temp = s[i] - 'a' + 1;
        long ri   = 1;
        for(int j = 0; j < i; j++) ri = (ri * r) % m;
        hash += (long long)temp * ri;
        hash %= m;
    }

    cout << hash;

    return 0;
}