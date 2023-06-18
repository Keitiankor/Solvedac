#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<string> nseen;
    set<string> nlisten;
    set<string> nsl;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        nseen.insert(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        nlisten.insert(s);
    }
    int count = 0;
    for (auto i : nlisten) {
        if (nseen.find(i) != nseen.end()) {
            count++;
            nsl.insert(i);
        }
    }

    cout << count << '\n';
    for (auto i : nsl)
        cout << i << '\n';

    return 0;
}