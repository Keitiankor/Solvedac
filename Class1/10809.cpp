#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int str[26];
	fill_n(str, 26, -1);
	for(int i = 0; i < s.length(); i++) {
		int c = s.at(i) - 'a';
		if(str[c] == -1) str[c] = i;
	}
	for(int i = 0; i < 26; i++) cout << str[i] << " ";
}