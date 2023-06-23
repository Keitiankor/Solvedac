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

    int n;
    cin >> n;
    int *arr = new int[n];
    int *dp  = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    fill_n(dp, n, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        int t = 0;
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                if(t < dp[j])
                    t = dp[j];
        dp[i] = t + 1;
    }
    int max = 0;
    for(int i = 0; i < n; i++)
        max = max > dp[i] ? max : dp[i];

    cout << max;

    return 0;
}