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

vector<pair<int, int>> vInit() {
    vector<pair<int, int>> t;
    t.push_back(make_pair(1, 0));
    t.push_back(make_pair(-1, 0));
    t.push_back(make_pair(0, 1));
    t.push_back(make_pair(0, -1));
    return t;
}

pair<int, int> operator+(pair<int, int> lValue, pair<int, int> RValue) {
    return make_pair(lValue.first + RValue.first, lValue.second + RValue.second);
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> _moveAble = vInit();
    queue<pair<int, int>> _point;

    char** _map = new char*[n];
    for(int i = 0; i < n; i++)
        _map[i] = new char[m];
    bool** _visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        _visited[i] = new bool[m];
        fill_n(_visited[i], m, false);
    }

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            _map[i][j] = s[j];
            if(_map[i][j] == 'I') {
                _visited[i][j] = true;
                _point.push(make_pair(i, j));
            }
            if(_map[i][j] == 'X')
                _visited[i][j] = true;
        }
    }

    int ans = 0;
    while(!_point.empty()) {
        pair<int, int> t = _point.front();
        _point.pop();

        for(int i = 0; i < 4; i++) {
            pair<int, int> temp = t + _moveAble[i];
            int x               = temp.second;
            int y               = temp.first;
            if(x >= 0 & x < m & y >= 0 & y < n) {
                if(!_visited[y][x]) {
                    _visited[y][x] = true;
                    _point.push(temp);
                    if(_map[y][x] == 'P')
                        ans++;
                }
            }
        }
    }

    if(ans == 0) {
        cout << "TT";
    } else {
        cout << ans;
    }
    return 0;
}