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

class Graph {
    public:
    vector<vector<int>> lst;
    int v;

    Graph(int n);
    void addV(int a, int b);
};

Graph::Graph(int n) {
    lst = vector<vector<int>>(n + 1, vector<int>());
}

void Graph::addV(int a, int b) {
    lst[a].push_back(b);
    lst[b].push_back(a);
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int n;
    cin >> n;
    Graph graph(n);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph.addV(a, b);
    }

    queue<int> bfs;
    bool *visit = new bool[n + 1];
    int *parent = new int[n + 1];
    fill_n(visit, n + 1, false);
    fill_n(parent, n + 1, 0);

    visit[1] = true;
    bfs.push(1);

    while(!bfs.empty()) {
        int t = bfs.front();
        bfs.pop();

        for(int i = 0; i < graph.lst[t].size(); i++) {
            if(!visit[graph.lst[t][i]]) {
                bfs.push(graph.lst[t][i]);
                visit[graph.lst[t][i]]  = true;
                parent[graph.lst[t][i]] = t;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}