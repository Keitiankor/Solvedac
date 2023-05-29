#include <iostream>
using namespace std;
int main() {
	int t;
	int cs = 0;
	for(int i = 0; i < 5; i++) {
		cin >> t;
		cs += t * t;
	}
	cout << cs % 10;
}