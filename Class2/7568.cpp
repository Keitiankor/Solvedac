#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> v;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    for(int i = 0; i < n; i++) {
        int dc = 0;
        for(int j = 0; j < n; j++)
            if(v[i].first < v[j].first && v[i].second < v[j].second) dc++;
        cout << dc + 1 << " ";
    }

    return 0;
}