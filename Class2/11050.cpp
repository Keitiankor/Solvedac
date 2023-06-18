#include <iostream>
using namespace std;

int fact(int a) {
    int r = 1;
    for(int i = 1; i <= a; i++)
        r *= i;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, np, kp, nkp;
    cin >> n >> k;
    int nk = n - k;

    np  = fact(n);
    kp  = fact(k);
    nkp = fact(nk);
    cout << np / (kp * nkp);

    return 0;
}
