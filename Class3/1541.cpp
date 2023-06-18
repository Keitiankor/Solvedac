#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef ONLINE_JUDGE
#    define NDEBUG
#endif

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    string s;
    cin >> s;
    int ans = 0;

    istringstream iss(s);
    vector<string> vs1;
    string temp;
    while(getline(iss, temp, '-')) vs1.push_back(temp);

    for(int i = 0; i < vs1.size(); i++) {
        int t = 0;
        istringstream iss(vs1[i]);
        while(getline(iss, temp, '+')) t += stoi(temp);
        ans += i == 0 ? t : -t;
    }

    cout << ans;

    return 0;
}