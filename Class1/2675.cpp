#include <iostream>
using namespace std;
int main() {
	int line;
	cin >> line;
	for(int i = 0; i < line; i++) {
		int times;
		cin >> times;
		string s;
		cin >> s;
		string out;
		for(int j = 0; j < s.length(); j++)
			for(int k = 0; k < times; k++) out.push_back(s.at(j));
		cout << out << '\n';
	}
}