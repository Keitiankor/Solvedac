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

set<int> in;
bool visited[8] = {false};
int output[8]   = {0};
int input[8]    = {0};

void bt(int n, int m, int i) {
    if(i == m) {
        for(int k = 0; k < m; k++)
            cout << output[k] << " ";
        cout << '\n';
        return;
    }

    for(int k = 0; k < n; k++) {
        if(!visited[k]) {
            visited[k] = true;
            output[i]  = input[k];
            bt(n, m, i + 1);
            visited[k] = false;
        }
    }
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        in.insert(t);
    }
    set<int>::iterator j = in.begin();
    for(int i = 0; i < n; i++) {
        input[i] = *j;
        j++;
    }

    bt(n, m, 0);

    return 0;
}