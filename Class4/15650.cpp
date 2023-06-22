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

int *arr;
bool *visited;

void bt(int num, int count, int n, int m) {
    if(count == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            bt(i + 1, count + 1, n, m);
            visited[i] = false;
        }
    }
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    arr     = new int[9];
    visited = new bool[9];

    int n, m;
    cin >> n >> m;

    bt(1, 0, n, m);
    return 0;
}