#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int right, up;
	right = w - x;
	up	  = h - y;

	int min = (right > x ? x : right) > (up > y ? y : up) ? (up > y ? y : up) : (right > x ? x : right);

	cout << min;
	return 0;
}