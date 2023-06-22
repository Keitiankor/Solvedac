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
#define E 0b1000
#define S 0b100
#define T 0b10
#define J 0b1

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++) {
        int student;
        cin >> student;
        int *mbti = new int[student];
        int max   = 16;
        for(int i = 0; i < student; i++) {
            string s;
            cin >> s;
            mbti[i] = 0;
            if(s[0] == 'E')
                mbti[i] = mbti[i] | E;
            if(s[1] == 'S')
                mbti[i] = mbti[i] | S;
            if(s[2] == 'T')
                mbti[i] = mbti[i] | T;
            if(s[3] == 'J')
                mbti[i] = mbti[i] | J;
        }

        for(int i = 0; i < student - 2; i++) {
            for(int j = i + 1; j < student - 1; j++) {
                for(int k = j + 1; k < student; k++) {
                    int ij, jk, ik;
                    ij       = mbti[i] ^ mbti[j];
                    jk       = mbti[k] ^ mbti[j];
                    ik       = mbti[i] ^ mbti[k];
                    int ijij = ((ij & E) >> 3) + ((ij & S) >> 2) + ((ij & T) >> 1) + (ij & J);
                    int jkjk = ((jk & E) >> 3) + ((jk & S) >> 2) + ((jk & T) >> 1) + (jk & J);
                    int ikik = ((ik & E) >> 3) + ((ik & S) >> 2) + ((ik & T) >> 1) + (ik & J);
                    int ijk  = ijij + jkjk + ikik;
                    if(max > ijk)
                        max = ijk;
                }
                if(max == 0)
                    break;
            }
            if(max == 0)
                break;
        }
        cout << max << '\n';
    }

    return 0;
}