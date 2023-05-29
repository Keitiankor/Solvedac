#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, n;
	vector<pair<int, int>> point;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}

	sort(point.begin(), point.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
		return p1.first == p2.first ? (p1.second < p2.second ? true : false) : (p1.first < p2.first ? true : false);
	});

	for(auto i : point) { cout << i.first << " " << i.second << '\n'; }
	return 0;
}