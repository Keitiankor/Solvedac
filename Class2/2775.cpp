#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int v[15][15];
    for (int ii = 0; ii < 15; ii++)
        v[ii][0] = 1;
    for (int ii = 0; ii < 15; ii++)
        v[0][ii] = ii + 1;

    for (int a = 1; a < 15; a++)
        for (int b = 1; b < 15; b++)
            v[a][b] = v[a - 1][b] + v[a][b - 1];
    for (int i = 0; i < t; i++) {
        int k, n;
        cin >> k >> n;
        cout << v[k][n - 1] << '\n';
    }
    return 0;
}