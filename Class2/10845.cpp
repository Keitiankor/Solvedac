#include <iostream>
#include <map>
#include <queue>

using namespace std;

enum { PUSH, POP, SIZE, EMPTY, FRONT, BACK };

static queue<int> q;
static map<string, int> m;
void init() {
    m["push"]  = PUSH;
    m["pop"]   = POP;
    m["size"]  = SIZE;
    m["empty"] = EMPTY;
    m["front"] = FRONT;
    m["back"]  = BACK;
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

    for (int i = 0; i < line; i++) {
        string s;
        cin >> s;
        switch (m[s]) {
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
    q.push(a);
}

void command(string s) {
    switch (m[s]) {
    case POP:
        if (q.empty())
            cout << -1 << '\n';
        else {
            cout << q.front() << '\n';
            q.pop();
        }
        break;
    case SIZE:
        cout << q.size() << '\n';
        break;
    case EMPTY:
        if (q.empty())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        break;
    case FRONT:
        if (q.empty())
            cout << -1 << '\n';
        else
            cout << q.front() << '\n';
        break;
    case BACK:
        if (q.empty())
            cout << -1 << '\n';
        else
            cout << q.back() << '\n';
        break;
    }
}