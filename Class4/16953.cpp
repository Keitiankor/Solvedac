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

    int a, b;
    cin >> a >> b;
    int step = 1;

    while(b > a) {
        if(b % 10 == 1)
            b /= 10;
        else if(b % 2 == 0)
            b /= 2;
        else
            break;
        step++;
    }
    if(b != a)
        step = -1;
    cout << step;

    return 0;
}