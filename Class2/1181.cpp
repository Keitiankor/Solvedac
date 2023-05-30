#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> v;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(find(v.begin(), v.end(), s) == v.end()) v.push_back(s);
	}

	sort(v.begin(), v.end(), [](string s1, string s2) {
		int cmp = s1.compare(s2);
		if(s1.length() == s2.length())
			if(cmp < 0)
				return true;
			else
				return false;
		else if(s1.length() < s2.length())
			return true;
		else
			return false;
	});

	for(string s : v) cout << s << '\n';

	return 0;
}