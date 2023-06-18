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

    int lines;
    cin >> lines;

    multiset<int> maxHeap;

    for(int i = 0; i < lines; i++) {
        int t;
        cin >> t;
        if(t != 0)
            maxHeap.insert(t);
        else {
#ifndef NDEBUG
            cout << "ans : ";
#endif
            if(maxHeap.empty())
                cout << 0 << '\n';
            else {
                cout << *maxHeap.rbegin() << '\n';
                maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
            }
        }
    }

    return 0;
}