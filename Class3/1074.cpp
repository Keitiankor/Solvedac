#include <cmath>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c, r;
    cin >> n >> r >> c;
    bool *y = new bool[n];
    bool *x = new bool[n];

    for(int i = 1; i <= n; i++) {
        int t    = pow(2, n - i);
        y[n - i] = r / t == 1;
        x[n - i] = c / t == 1;
        r %= t;
        c %= t;
    }

    int sumy = y[0] * 2;
    int sumx = x[0];

    for(int i = 1; i < n; i++) {
        if(y[i])
            sumy += 2 * pow(4, i);
        if(x[i])
            sumx += pow(4, i);
    }

    int xy = sumy + sumx;
    cout << xy;
    return 0;
}