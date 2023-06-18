#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int div3 = n;
        int div2 = n;
        if (i == 1)
            v[i] = 0;
        else if (i == 2)
            v[i] = 1;
        else if (i == 3)
            v[i] = 1;
        else {
            if (i % 3 == 0) div3 = v[i / 3] > v[i - 1] ? v[i - 1] + 1 : v[i / 3] + 1; // 3으로 나누어질때
            if (i % 2 == 0) div2 = v[i / 2] > v[i - 1] ? v[i - 1] + 1 : v[i / 2] + 1; // 2로 나누어질때
            v[i] = div2 > div3 ? div3 : div2; // 2로 나누어질때와 3으로 나누어질때중 작은값
            v[i] = v[i] > v[i - 1] ? v[i - 1] + 1 : v[i]; // 위의값과 -1 중 작은값
        }
    }
    cout << v[n];

    return 0;
}