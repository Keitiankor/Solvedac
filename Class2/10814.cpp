#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int year;
    string name;
    vector<tuple<int, int, string>> pr;
    for (int i = 0; i < n; i++) {
        cin >> year >> name;
        pr.push_back(make_tuple(i + 1, year, name));
    }

    sort(pr.begin(), pr.end(), [](tuple<int, int, string>& p1, tuple<int, int, string>& p2) {
        return get<1>(p1) == get<1>(p2) ? get<0>(p1) < get<0>(p2) ? true : false :
               get<1>(p1) < get<1>(p2)  ? true :
                                          false;
    });

    for (tuple<int, int, string> i : pr)
        cout << get<1>(i) << " " << get<2>(i) << '\n';

    return 0;
}