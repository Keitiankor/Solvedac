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

int out[9];

void bt(int n, int m, int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++)
            cout << out[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        out[depth] = i;
        bt(n, m, depth + 1);
    }
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int n, m;
    cin >> n >> m;

    bt(n, m, 0);

    return 0;
}