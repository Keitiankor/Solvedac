#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n, k;
        cin >> m >> n >> k;
        int bug = 0;
        vector<pair<int, int>> pm;
        pm.push_back(make_pair(1, 0));
        pm.push_back(make_pair(-1, 0));
        pm.push_back(make_pair(0, 1));
        pm.push_back(make_pair(0, -1));

        vector<vector<bool>> field(m, vector<bool>(n, false));
        vector<pair<int, int>> cabbage;
        queue<pair<int, int>> q;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            cabbage.push_back(make_pair(x, y));
        }

        for (auto j : cabbage) {
            if (!field[j.first][j.second]) {
                q.push(j);
                bug++;
                field[j.first][j.second] = true;
            }
            while (!q.empty()) {
                pair<int, int> point = q.front();
                q.pop();
                field[point.first][point.second] = true;
                for (auto k : pm) {
                    pair<int, int> ppmm = make_pair(point.first + k.first, point.second + k.second);
                    pair<int, int> mmpp = make_pair(ppmm.second, ppmm.first);
                    if (find(cabbage.begin(), cabbage.end(), ppmm) != cabbage.end() &&
                        !field[ppmm.first][ppmm.second]) {
                        q.push(ppmm);
                        field[ppmm.first][ppmm.second] = true;
                    }
                }
            }
        }
        cout << bug << '\n';
    }
    return 0;
}