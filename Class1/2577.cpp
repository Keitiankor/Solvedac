#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int mult	  = a * b * c;
	int count[10] = {0};
	string s	  = to_string(mult);
	for(int i = 0; i < s.length(); i++) count[s.at(i) - '0']++;
	for(int i = 0; i < 10; i++) cout << count[i] << '\n';
}