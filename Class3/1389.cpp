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

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> friends;
    bool *checked = new bool[n + 1];
    int *cbcount  = new int[n + 1];
    fill_n(cbcount, n + 1, 0);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friends.push_back(make_pair(x, y));
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            queue<int> cb;
            fill_n(checked, n + 1, false);
            int counter = 0;
            cb.push(i);
            checked[i] = true;
            cb.push(-1);
            while(!cb.empty()) {
                int t = cb.front();
                cb.pop();
                if(t == j)
                    break;
                if(t == -1) {
                    cb.push(-1);
                    counter++;
                } else {
                    for(auto a : friends) {
                        int x = a.first;
                        int y = a.second;
                        if(x == t & !checked[y]) {
                            checked[y] = true;
                            cb.push(y);
                        }
                        if(y == t & !checked[x]) {
                            checked[x] = true;
                            cb.push(x);
                        }
                    }
                }
            }
#ifndef NDEBUG
            cout << "\n counter : " << counter;
#endif
            cbcount[i] += counter;
        }
#ifndef NDEBUG
        cout << "\n counter [" << i << "] : " << cbcount[i];
#endif
    }

#ifndef NDEBUG
    cout << '\n';
    for(int i = 0; i <= n; i++)
        cout << cbcount[i] << " ";
    cout << '\n';
#endif

    int min = 0x7fffffff;
    int person;
    for(int i = 1; i <= n; i++) {
        if(cbcount[i] < min) {
            min    = cbcount[i];
            person = i;
        }
    }
    cout << person;

    return 0;
}