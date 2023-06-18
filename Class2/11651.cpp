#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    vector<pair<int, int>> point;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }

    sort(point.begin(), point.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second == b.second ? a.first < b.first ? true : false : a.second < b.second ? true : false;
    });

    for (pair<int, int> i : point) {
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}