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
#include <string>
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
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << endl;
    string aa = to_string(a);
    string bb = to_string(b);
    aa.append(bb);
    int ab = stoi(aa);
    cout << ab - c;

    return 0;
}