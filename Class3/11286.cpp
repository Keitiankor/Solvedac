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

    multiset<pair<int, int>> absHeap;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t != 0) {
            absHeap.insert(make_pair(abs(t), t));
        } else {
            if(absHeap.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << absHeap.begin()->second << '\n';
            absHeap.erase(absHeap.begin());
        }
    }

    return 0;
}