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

    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        map<string, int> cloths;
        int c;
        cin >> c;
        for(int j = 0; j < c; j++) {
            string n, t;
            cin >> n >> t;
            if(!cloths.count(t))
                cloths.emplace(t, 1);
            else
                cloths.find(t)->second++;
        }
        vector<int> setup;
        for(auto i : cloths)
            setup.push_back(i.second);
        int count = 1;
        for(auto i : setup)
            count *= i + 1;
        cout << count - 1 << '\n';
    }

    return 0;
}