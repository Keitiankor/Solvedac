#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

enum {
    ADD,
    REMOVE,
    CHECK,
    TOGGLE,
    ALL,
    EMPTY,
};

static map<string, int> m;
void init() {
    m["add"]    = ADD;
    m["remove"] = REMOVE;
    m["check"]  = CHECK;
    m["toggle"] = TOGGLE;
    m["all"]    = ALL;
    m["empty"]  = EMPTY;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    bool* bs = new bool[21];
    fill_n(bs, 21, false);

    int M;
    cin >> M;

    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        switch(m[s]) {
        case ALL:
            fill_n(bs, 21, true);
            break;
        case EMPTY:
            fill_n(bs, 21, false);
            break;
        default:
            int t;
            cin >> t;
            switch(m[s]) {
            case ADD:
                bs[t] = true;
                break;
            case REMOVE:
                bs[t] = false;
                break;
            case CHECK:
                cout << (bs[t] ? 1 : 0) << '\n';
                break;
            case TOGGLE:
                bs[t] = !bs[t];
                break;
            }
            break;
        }
    }

    return 0;
}