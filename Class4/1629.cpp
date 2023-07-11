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

    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = 1;

    while(b != 0) {
        if(b & 1)
            ans *= a;
        a *= a;
        b = b >> 1;
        a %= c;
        ans %= c;
    }

    cout << ans;

    return 0;
}