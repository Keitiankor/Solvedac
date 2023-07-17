#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
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

bool visited[8] = {false};
int *output;
int *input;
set<vector<int>> ov;

void bt(int n, int m, int i) {
    if(i == m) {
        vector<int> v;
        for(int k = 0; k < m; k++) {
            if(!v.empty() && v[v.size() - 1] > output[k])
                return;
            v.push_back(output[k]);
        }
        ov.insert(v);
        return;
    }

    for(int k = 0; k < n; k++) {
        output[i] = input[k];
        bt(n, m, i + 1);
    }
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int n, m;
    cin >> n >> m;
    input  = new int[n];
    output = new int[m];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input + n);

    bt(n, m, 0);

    for(auto iter = ov.begin(); iter != ov.end(); iter++) {
        for(int t : *iter)
            cout << t << ' ';
        cout << '\n';
    }

    return 0;
}