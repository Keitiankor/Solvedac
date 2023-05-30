#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> sum;
	for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 0; i < n - 2; i++)
		for(int j = i + 1; j < n - 1; j++)
			for(int k = j + 1; k < n; k++) sum.push_back(v[i] + v[j] + v[k]);

	sort(sum.begin(), sum.end());
	for(auto i : sum)
		if(i <= m) ans = i;

	cout << ans;

	return 0;
}