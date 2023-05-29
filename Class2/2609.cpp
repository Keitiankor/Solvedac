#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int min = 1, max = 1;
	for(int i = 2; i <= a || i <= b; i++) {
		if(a % i == 0 && b % i == 0) {
			min *= i;
			a /= i;
			b /= i;
			i = 1;
		}
	}
	max = a * b * min;
	cout << min << '\n' << max;

	return 0;
}