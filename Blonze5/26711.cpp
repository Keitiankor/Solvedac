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

    string s1, s2;
    cin >> s1 >> s2;

    string ans = "";
    bool carry = false;

    string::reverse_iterator i1, i2;
    i1 = s1.rbegin();
    i2 = s2.rbegin();
    while(i1 != s1.rend() | i2 != s2.rend()) {
        char c = 0;
        if(i1 != s1.rend() & i2 != s2.rend()) {
            if(carry == true)
                c++;
            c += *i1 + *i2 - '0';
            if(c > '9') {
                c -= 10;
                carry = true;
            } else {
                carry = false;
            }
            i1++;
            i2++;
        } else if(i1 != s1.rend() & i2 == s2.rend()) {
            if(carry == true)
                c++;
            c += *i1;
            if(c > '9') {
                c -= 10;
                carry = true;
            } else {
                carry = false;
            }
            i1++;
        } else if(i1 == s1.rend() & i2 != s2.rend()) {
            if(carry == true)
                c++;
            c += *i2;
            if(c > '9') {
                c -= 10;
                carry = true;
            } else {
                carry = false;
            }
            i2++;
        }
        ans += c;
    }
    if(carry == true)
        ans += '1';
    for(string::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it;
    }

    return 0;
}