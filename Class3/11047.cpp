#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
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

    int n, k;
    cin >> n >> k;

    stack<int> coins;

    int count = 0;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        coins.push(t);
    }
    while(!coins.empty()) {
        int t = coins.top();
        coins.pop();
        count += k / t;
        k %= t;
    }

    if(k != 0) count++;

    cout << count;

    return 0;
}