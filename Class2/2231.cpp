#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int m = 0;
	if(n == 1) {
		cout << 0;
		return 0;
	}
	while(m <= n) {
		m++;
		string s = to_string(m);
		vector<int> v;
		int sum = m;
		for(char c : s) sum += c - '0';
		if(sum == n) {
			cout << m;
			return 0;
		}
	}
	cout << 0;
	return 0;
}