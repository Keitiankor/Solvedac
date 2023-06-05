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

	vector<pair<int, int>> pm = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	pair<int, int> goal;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> bmap(n, vector<int>(m, -1));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int t;
			cin >> t;
			map[i][j] = t;
			if(t == 2) goal = make_pair(i, j);
			if(t == 0) bmap[i][j] = 0;
		}
	}

	queue<pair<int, int>> graph;
	graph.push(make_pair(-1, -1));
	graph.push(goal);
	bmap[goal.first][goal.second] = 0;
	int distance				  = 0;
	while(!graph.empty()) {
		pair<int, int> point = graph.front();
		graph.pop();
		if(point == make_pair(-1, -1)) {
			point = graph.front();
			graph.pop();
			graph.push(make_pair(-1, -1));
			distance++;
		}
		for(auto i : pm) {
			pair<int, int> temp = make_pair(point.first + i.first, point.second + i.second);
			if(temp.first >= 0 && temp.second >= 0 && temp.first < n && temp.second < m) {
				if(map[temp.first][temp.second] == 1 && bmap[temp.first][temp.second] == -1) {
					bmap[temp.first][temp.second] = distance;
					graph.push(temp);
				}
			}
		}
	}
	for(auto i : bmap) {
		for(auto j : i) cout << j << " ";
		cout << '\n';
	}

	return 0;
}