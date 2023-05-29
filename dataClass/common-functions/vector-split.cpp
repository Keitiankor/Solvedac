#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string s, char delimiter) {
	vector<string> splited;
	stringstream ss(s);
	string temp;

	while(getline(ss, temp, delimiter)) splited.push_back(temp);

	return splited;
}