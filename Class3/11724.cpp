#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph;
    vector<bool> cGraph(n + 1, false);
    cGraph[0] = true;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.push_back(make_pair(a, b));
    }
    int couter = 0;

    while (find(cGraph.begin(), cGraph.end(), false) != cGraph.end()) {
        queue<int> point;
        int t = 0;
        for (int i = 0; i < cGraph.size(); i++)
            if (!cGraph[i]) {
                t = i;
                break;
            }

        cGraph[t] = true;
        point.push(t);
        while (!point.empty()) {
            int f = point.front();
            point.pop();

            for (int j = 0; j < graph.size(); j++) {
                if (graph[j].first == f && cGraph[graph[j].second] == false) {
                    cGraph[graph[j].second] = true;
                    point.push(graph[j].second);
                }
                if (graph[j].second == f && cGraph[graph[j].first] == false) {
                    cGraph[graph[j].first] = true;
                    point.push(graph[j].first);
                }
            }
        }
        couter++;
    }
    cout << couter;
    return 0;
}
