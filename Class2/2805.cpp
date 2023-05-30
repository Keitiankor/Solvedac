#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> trees(n);

	int mini = 0;
	int maxi = 1000000000;
	long ans = 0;
	for(int i = 0; i < n; i++) cin >> trees[i];

	while(mini <= maxi) {
		long sum = 0;
		int mid	 = (maxi + mini) / 2;
		for(int i = 0; i < n; i++) {
			if(trees[i] > mid) sum = trees[i] - mid + sum;
		}
		if(m <= sum) {
			if(ans < mid) ans = mid;
			mini = mid + 1;
		} else
			maxi = mid - 1;
	}

	cout << ans;

	return 0;
}