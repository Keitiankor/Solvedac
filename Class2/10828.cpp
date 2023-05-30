#include <iostream>
#include <map>
#include <stack>

using namespace std;

enum { PUSH, POP, SIZE, EMPTY, TOP };

static stack<int> st;
static map<string, int> m;
void init() {
	m["push"]  = PUSH;
	m["pop"]   = POP;
	m["size"]  = SIZE;
	m["empty"] = EMPTY;
	m["top"]   = TOP;
};

void command(string s);
void command(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();

	int line;
	cin >> line;

	for(int i = 0; i < line; i++) {
		string s;
		cin >> s;
		switch(m[s]) {
		case PUSH:
			int a;
			cin >> a;
			command(a);
			break;
		default:
			command(s);
			break;
		}
	}

	return 0;
}

void command(int a) {
	st.push(a);
}

void command(string s) {
	switch(m[s]) {
	case POP:
		if(st.empty())
			cout << -1 << '\n';
		else {
			cout << st.top() << '\n';
			st.pop();
		}
		break;
	case SIZE:
		cout << st.size() << '\n';
		break;
	case EMPTY:
		if(st.empty())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
		break;
	case TOP:
		if(st.empty())
			cout << -1 << '\n';
		else
			cout << st.top() << '\n';
		break;
	}
}