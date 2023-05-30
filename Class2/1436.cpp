#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string sss = "666";

	int count = 0;
	int eow	  = 665;
	while(count != n) {
		eow++;
		string s = to_string(eow);
		if(s.find(sss) != string::npos) count++;
	}
	cout << eow;

	return 0;
}