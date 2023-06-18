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

    long long dp[100];
    int tc;
    cin >> tc;

    for (int i = 0; i < 100; i++) {
        switch (i) {
        case 0:
            dp[i] = 1;
            break;
        case 1:
            dp[i] = 1;
            break;
        case 2:
            dp[i] = 1;
            break;
        case 3:
            dp[i] = 2;
            break;
        case 4:
            dp[i] = 2;
            break;
        default:
            dp[i] = dp[i - 5] + dp[i - 1];
        }
    }

    for (int i = 0; i < tc; i++) {
        int t;
        cin >> t;
        cout << dp[t - 1] << '\n';
    }

    return 0;
}