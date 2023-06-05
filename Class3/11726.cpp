#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> tiling(1001);
	for(int i = 1; i < 1001; i++) {
		switch(i) {
		case 1:
			tiling[i] = 1;
			break;
		case 2:
			tiling[i] = 2;
			break;

		default:
			tiling[i] = (tiling[i - 1] + tiling[i - 2]) % 10007;
			break;
		}
	}

	int n;
	cin >> n;
	cout << tiling[n];

	return 0;
}