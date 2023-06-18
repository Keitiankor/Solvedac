#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class doubleKeySet {
    private:
    unordered_map<int, string> ismap;
    unordered_map<string, int> simap;

    public:
    string findWInt(int i);
    int findWString(string s);
    void addSet(int i, string s);
    void addSet(string s, int i);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    doubleKeySet dks;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dks.addSet(i + 1, s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            int sti = stoi(s);
            cout << dks.findWInt(sti) << '\n';
        } else {
            cout << dks.findWString(s) << '\n';
        }
    }

    return 0;
}

string doubleKeySet::findWInt(int i) {
    return this->ismap.find(i)->second;
}
int doubleKeySet::findWString(string s) {
    return this->simap.find(s)->second;
}
void doubleKeySet::addSet(int i, string s) {
    ismap.insert(make_pair(i, s));
    simap.insert(make_pair(s, i));
}
void doubleKeySet::addSet(string s, int i) {
    ismap.insert(make_pair(i, s));
    simap.insert(make_pair(s, i));
}