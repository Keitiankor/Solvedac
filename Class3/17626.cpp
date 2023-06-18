#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
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

    int lagrange[50001];
    fill_n(lagrange, 50001, 5);

    int multmap[224];
    for (int i = 0; i < 225; i++)
        multmap[i] = i * i;
    for (auto i : multmap)
        lagrange[i] = 1;

    int counter = 0;
    int multtimes;
    for (int i = 2; i < 50001; i++) {
        if (lagrange[i] != 1) {
            for (int j = 1; j < i / 2 + 1; j++) {
                if (lagrange[j] + lagrange[i - j] < lagrange[i]) lagrange[i] = lagrange[j] + lagrange[i - j];
            }
        }
    }

    int n;
    cin >> n;
    cout << lagrange[n];

    return 0;
}