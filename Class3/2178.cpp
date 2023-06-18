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

pair<int, int> operator+(pair<int, int> lValue, pair<int, int> rValue) {
    return make_pair(lValue.first + rValue.first, lValue.second + rValue.second);
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    vector<pair<int, int>> moveTo;
    moveTo.push_back(make_pair(1, 0));
    moveTo.push_back(make_pair(-1, 0));
    moveTo.push_back(make_pair(0, 1));
    moveTo.push_back(make_pair(0, -1));

    int n, m;
    cin >> n >> m;
    bool **maze = new bool *[n];
    for(int i = 0; i < n; i++) {
        maze[i] = new bool[m];
    }

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            maze[i][j] = s[j] == '1' ? 1 : 0;
        }
    }

    queue<pair<int, int>> graph;
    int length = 1;
    graph.push(make_pair(0, 0));
    graph.push(make_pair(-1, -1));
    while(true) {
        pair<int, int> t = graph.front();
        graph.pop();
        if(t.first == m - 1 & t.second == n - 1)
            break;
        if(t.first == -1 & t.second == -1) {
            length++;
            graph.push(make_pair(-1, -1));
        } else {
            for(int i = 0; i < 4; i++) {
                pair<int, int> temp = t + moveTo[i];
                int x               = temp.first;
                int y               = temp.second;
                if(x >= 0 & x < m & y >= 0 & y < n)
                    if(maze[y][x]) {
                        maze[y][x] = false;
                        graph.push(make_pair(x, y));
                    }
            }
        }
    }

    cout << length;

    return 0;
}