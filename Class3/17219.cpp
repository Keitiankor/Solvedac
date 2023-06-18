#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef ONLINE_JUDGE
#    define NDEBUG
#endif

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    unordered_map<string, string> mapss;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string url, pass;
        cin >> url >> pass;
        pair<string, string> tp = make_pair(url, pass);
        mapss.emplace(url, pass);
    }
    for (int i = 0; i < m; i++) {
        string url;
        cin >> url;
        cout << mapss.find(url)->second << '\n';
    }
    return 0;
}