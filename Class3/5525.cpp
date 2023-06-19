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
#define MAX 1000001

#ifdef ONLINE_JUDGE
#    define NDEBUG
#endif

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, m;
    string s;
    cin >> n >> m >> s;
    int *str = new int[m];

    for(int i = 0; i < m; i++) {
        switch(i) {
        case 0:
            str[i] = s[i] == 'I' ? 1 : -1;
            break;
        case 1:
            str[i] = s[i] == 'I' ? 1 : -1;
            break;
        default:
            if(s[i] == 'I') {
                if(str[i - 1] == -1 && str[i - 2] > 0)
                    str[i] = str[i - 2] + 1;
                else
                    str[i] = 1;
            } else
                str[i] = -1;
            break;
        }
    }

    int count = 0;
    for(int i = n - 1; i < m; i++)
        if(str[i] > n)
            count++;

    cout << count;

    return 0;
}