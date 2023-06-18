#include <deque>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

void command(string s);
void command(string s, int i);

enum { PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK };
static deque<int> d;
static map<string, int> m;
void init() {
    m["push_front"] = PUSH_FRONT;
    m["push_front"] = PUSH_FRONT;
    m["push_back"]  = PUSH_BACK;
    m["pop_front"]  = POP_FRONT;
    m["pop_back"]   = POP_BACK;
    m["size"]       = SIZE;
    m["empty"]      = EMPTY;
    m["front"]      = FRONT;
    m["back"]       = BACK;
}

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
        case PUSH_BACK:
        case PUSH_FRONT:
            int temp;
            cin >> temp;
            command(s, temp);
            break;
        default:
            command(s);
            break;
        }
    }

    return 0;
}

void command(string s) {
    switch(m[s]) {
    case SIZE:
        cout << d.size() << '\n';
        break;
    case EMPTY:
        if(d.empty())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        break;
    case FRONT:
        if(d.empty())
            cout << -1 << '\n';
        else
            cout << d.front() << '\n';
        break;
    case BACK:
        if(d.empty())
            cout << -1 << '\n';
        else
            cout << d.back() << '\n';
        break;
    case POP_FRONT:
        if(d.empty())
            cout << -1 << '\n';
        else {
            cout << d.front() << '\n';
            d.pop_front();
        }
        break;
    case POP_BACK:
        if(d.empty())
            cout << -1 << '\n';
        else {
            cout << d.back() << '\n';
            d.pop_back();
        }
        break;
    }
}

void command(string s, int i) {
    switch(m[s]) {
    case PUSH_FRONT:
        d.push_front(i);
        break;
    case PUSH_BACK:
        d.push_back(i);
        break;
    }
}