#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, temp;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (binary_search(arr.begin(), arr.end(), temp))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}