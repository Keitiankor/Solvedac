#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> timetable;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        timetable.push_back(make_pair(a, b));
    }

    sort(timetable.begin(), timetable.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second == b.second ? a.first < b.first ? true : false : a.second < b.second ? true : false;
    });

    int time    = timetable[0].second;
    int counter = 1;
    for (int index = 1; index < n; index++)
        if (timetable[index].first >= time) {
            time = timetable[index].second;
            counter++;
        }

    cout << counter;
    return 0;
}