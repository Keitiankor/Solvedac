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

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for(auto i : v)
        cout << i << '\n';

    return 0;
}