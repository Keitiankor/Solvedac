#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int *sum = new int[n + 1];
    sum[0]   = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum[i + 1] = sum[i] + t;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << '\n';
    }

    return 0;
}