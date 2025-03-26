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
    int s, m, l, xl, xxl, xxxl;
    int t, p;
    cin >> n;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    cin >> t >> p;

    if(s % t == 0) {
        s = s / t;
    } else {
        s = s / t + 1;
    }

    if(m % t == 0) {
        m = m / t;
    } else {
        m = m / t + 1;
    }

    if(l % t == 0) {
        l = l / t;
    } else {
        l = l / t + 1;
    }

    if(xl % t == 0) {
        xl = xl / t;
    } else {
        xl = xl / t + 1;
    }

    if(xxl % t == 0) {
        xxl = xxl / t;
    } else {
        xxl = xxl / t + 1;
    }

    if(xxxl % t == 0) {
        xxxl = xxxl / t;
    } else {
        xxxl = xxxl / t + 1;
    }

    int ps = n / p;
    int pe = n % p;
    int ts = s + m + l + xl + xxl + xxxl;
    cout << ts << endl << ps << " " << pe;
    return 0;
}