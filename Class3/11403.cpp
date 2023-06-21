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
    bool **graph = new bool *[n];
    for(int i = 0; i < n; i++) {
        graph[i] = new bool[n];
        fill_n(graph[i], n, false);
    }

    vector<pair<int, int>> way;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if(t == 1)
                way.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < n; i++) {
        queue<pair<int, int>> q;
        for(pair<int, int> p : way)
            if(p.first == i)
                q.push(p);
        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            if(!graph[i][temp.second]) {
                graph[i][temp.second] = true;
                for(pair p : way)
                    if(p.first == temp.second)
                        q.push(p);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j])
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << '\n';
    }

    return 0;
}