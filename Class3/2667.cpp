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

    int n;
    cin >> n;
    bool **block = new bool *[n];
    for(int i = 0; i < n; i++) {
        block[i] = new bool[n];
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            block[i][j] = s[j] == '1';
        }
    }
    int blocks = 0;
    vector<int> houses;
    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            if(block[a][b] == true) {
                blocks++;
                queue<pair<int, int>> group;
                group.push(make_pair(a, b));
                int house   = 1;
                block[a][b] = false;
                while(!group.empty()) {
                    pair<int, int> temp = group.front();
                    group.pop();
                    for(auto t : moveTo) {
                        pair<int, int> tt = t + temp;
                        int x             = tt.first;
                        int y             = tt.second;
                        if(x >= 0 & x < n & y >= 0 & y < n) {
                            if(block[x][y]) {
                                house++;
                                block[x][y] = false;
                                group.push(tt);
                            }
                        }
                    }
                }
                houses.push_back(house);
            }
        }
    }

    cout << blocks << '\n';
    sort(houses.begin(), houses.end());
    for(auto i : houses) {
        cout << i << '\n';
    }

    return 0;
}