#include <algorithm>
#include <iostream>
#include <queue>

/*🍅*/
using namespace std;

class pii : public pair<int, int> {
    public:
    inline bool in(int a, int b) {
        bool ch1, ch2;
        ch1 = this->first >= 0 && this->second >= 0 ? true : false;
        ch2 = this->first < a && this->second < b ? true : false;
        return ch1 & ch2;
    }
    pii(int a, int b) {
        this->first  = a;
        this->second = b;
    }
    pii(pair<int, int> p) {
        this->first  = p.first;
        this->second = p.second;
    }
    pii operator+(const pii& p) { return make_pair(this->first + p.first, this->second + p.second); }
    bool operator!=(const pii& p) { return this->first != p.first || this->second != p.second ? false : true; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    char** tomatos = new char*[n];
    bool** checker = new bool*[n];
    for (int i = 0; i < n; i++) {
        tomatos[i] = new char[m];
        checker[i] = new bool[m];
        fill_n(&checker[i][0], m, false);
    }

    queue<pii> tomato;
    pii grow[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            tomatos[i][j] = t;
            if (t == -1) checker[i][j] = true;
            if (t == 1) {
                checker[i][j] = true;
                tomato.push(make_pair(i, j));
            }
        }
    int days = 0;
    tomato.push({-1, -1});
    while (!tomato.empty()) {
        pii growth = tomato.front();
        tomato.pop();
        if (growth == make_pair(-1, -1)) {
            if (tomato.empty()) break;
            tomato.push({-1, -1});
            days++;
        } else {
            for (int i = 0; i < 4; i++) {
                pii t = growth + grow[i];
                if (t.in(n, m) && !checker[t.first][t.second]) {
                    checker[t.first][t.second] = true;
                    if (tomatos[t.first][t.second] == 0) {
                        tomatos[t.first][t.second] = 1;
                        tomato.push(t);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!checker[i][j]) days = -1;

    cout << days;

    return 0;
}