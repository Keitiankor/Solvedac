#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p.begin(), p.end());

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += p[i] * (n - i);

    cout << sum;

    return 0;
}