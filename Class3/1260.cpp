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

    int n, m, v;
    cin >> n >> m >> v;

    vector<pair<int, int>> graph;
    bool* visited = new bool[n + 1];
    fill_n(visited, n + 1, false);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph.push_back(make_pair(x, y));
    }

    stack<int> dfs;
    vector<int> ans;
    dfs.push(v);
    while(!dfs.empty()) {
        int next = dfs.top();
        dfs.pop();
        if(find(ans.begin(), ans.end(), next) == ans.end()) ans.push_back(next);
        visited[next] = true;
        set<int> temp;
        for(pair<int, int> i : graph) {
            if(i.first == next && !visited[i.second]) temp.insert(i.second);
            if(i.second == next && !visited[i.first]) temp.insert(i.first);
        }
        for(auto iter = temp.rbegin(); iter != temp.rend(); iter++) dfs.push(*iter);
    }

    for(auto i : ans) cout << i << ' ';
    ans.clear();

    cout << '\n';

    queue<int> bfs;
    bfs.push(v);
    fill_n(visited, n + 1, false);
    visited[v] = true;
    ans.clear();

    while(!bfs.empty()) {
        int next = bfs.front();
        bfs.pop();
        if(find(ans.begin(), ans.end(), next) == ans.end()) ans.push_back(next);
        set<int> temp;
        for(pair<int, int> i : graph) {
            if(i.first == next && !visited[i.second]) {
                temp.insert(i.second);
                visited[i.second] = true;
            }
            if(i.second == next && !visited[i.first]) {
                temp.insert(i.first);
                visited[i.first] = true;
            }
        }
        for(auto i : temp) bfs.push(i);
    }
    for(auto i : ans) cout << i << ' ';

    return 0;
}