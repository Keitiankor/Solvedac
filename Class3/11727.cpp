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

    int tiling[1000];
    for (int i = 0; i < 1000; i++) {
        switch (i) {
        case 0:
            tiling[i] = 1;
            break;
        case 1:
            tiling[i] = 3;
            break;
        default:
            tiling[i] = tiling[i - 1] + tiling[i - 2] * 2;
            tiling[i] %= 10007;
        }
    }
    int n;
    cin >> n;
    cout << tiling[n - 1];

    return 0;
}