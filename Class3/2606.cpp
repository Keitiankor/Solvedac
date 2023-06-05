#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int computers;
	int connections;
	cin >> computers >> connections;
	vector<bool> isInfected(computers + 1, false);
	vector<pair<int, int>> connection;

	for(int i = 0; i < connections; i++) {
		int from, to;
		cin >> from >> to;
		connection.push_back(make_pair(from, to));
	}

	isInfected[1] = true;
	queue<int> infectionPool;
	infectionPool.push(1);

	int ans = 0;
	while(!infectionPool.empty()) {
		int from = infectionPool.front();
		infectionPool.pop();
		for(int i = 0; i < connection.size(); i++) {
			if(connection[i].first == from && isInfected[connection[i].second] == false) {
				isInfected[connection[i].second] = true;
				infectionPool.push(connection[i].second);
				ans++;
			}
			if(connection[i].second == from && isInfected[connection[i].first] == false) {
				isInfected[connection[i].first] = true;
				infectionPool.push(connection[i].first);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}