#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> fibo0(41);
    vector<int> fibo1(41);

    for (int i = 0; i < 41; i++) {
        if (i == 0) {
            fibo0[i] = 1;
            fibo1[i] = 0;
        } else if (i == 1) {
            fibo0[i] = 0;
            fibo1[i] = 1;
        } else if (i == 2) {
            fibo0[i] = 1;
            fibo1[i] = 1;
        } else {
            fibo0[i] = fibo0[i - 1] + fibo0[i - 2];
            fibo1[i] = fibo1[i - 1] + fibo1[i - 2];
        }
    }
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int in;
        cin >> in;
        cout << fibo0[in] << " " << fibo1[in] << '\n';
    }

    return 0;
}