#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
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

    int n;
    cin >> n;

    int **cost = new int *[n];
    for(int i = 0; i < n; i++) {
        cost[i] = new int[3];
        fill_n(cost[i], 3, 0);
        int r, g, b;
        cin >> r >> g >> b;
        if(i == 0) {
            cost[i][0] = r;
            cost[i][1] = g;
            cost[i][2] = b;
#ifndef NDEBUG
            cout << "debug:: " << cost[i][0] << " " << cost[i][1] << " " << cost[i][2] << '\n';
#endif
        } else {
            cost[i][0] = r + (cost[i - 1][1] < cost[i - 1][2] ? cost[i - 1][1] : cost[i - 1][2]);
            cost[i][1] = g + (cost[i - 1][0] < cost[i - 1][2] ? cost[i - 1][0] : cost[i - 1][2]);
            cost[i][2] = b + (cost[i - 1][1] < cost[i - 1][0] ? cost[i - 1][1] : cost[i - 1][0]);
#ifndef NDEBUG
            cout << "debug:: " << cost[i][0] << " " << cost[i][1] << " " << cost[i][2] << '\n';
#endif
        }
    }
    int res = cost[n - 1][0] < cost[n - 1][1] ? (cost[n - 1][0] < cost[n - 1][2] ? cost[n - 1][0] : cost[n - 1][2]) :
                                                (cost[n - 1][1] < cost[n - 1][2] ? cost[n - 1][1] : cost[n - 1][2]);

    cout << res;

    return 0;
}