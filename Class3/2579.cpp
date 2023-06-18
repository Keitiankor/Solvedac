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

    int n;
    cin >> n;
    int* stairs = new int[n];
    for (int i = 0; i < n; i++)
        cin >> stairs[i];

    int* score  = new int[n];
    int* scored = new int[n];
    for (int i = 0; i < n; i++) {
        switch (i) {
        case 0:
            score[i]  = stairs[i];
            scored[i] = stairs[i];
            break;
        case 1:
            score[i]  = stairs[i] + scored[i - 1];
            scored[i] = stairs[i];
            break;
        default:
            score[i]  = stairs[i] + (scored[i - 1] > score[i - 2] ? scored[i - 1] : score[i - 2]);
            scored[i] = stairs[i] + score[i - 2];
            break;
        }
    }

    cout << (score[n - 1] > scored[n - 1] ? score[n - 1] : scored[n - 1]);

    return 0;
}