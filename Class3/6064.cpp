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

static long long gcd(long long a, long long b) {
    long long c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    long long tc;
    cin >> tc;
    for(long long tcc = 0; tcc < tc; tcc++) {
        long long ans = -1;
        long long m, n, x, y;
#ifdef NDEBUG
        cin >> m >> n >> x >> y;
#else
        m                 = rand() % 400 + 1;
        n                 = rand() % 400 + 1;
        long long counter = rand() % m * n + 1;
        x                 = counter % m + 1;
        y                 = counter % n + 1;
#endif
        int tm    = (n > m ? m : 0);
        int tn    = (m > n ? n : 0);
        int cm    = 0;
        int cn    = 0;
        int igcd  = gcd(m, n);
        bool flag = true;
        while(tm + x != tn + y) {
            if(x + tm > m * n / igcd | y + tn > n * m / igcd) {
                flag = false;
                break;
            }
            if(tm + x > tn + y) {
                tn += n;
                cn++;
            } else {
                tm += m;
                cm++;
            }
        }
        if(flag)
            ans = tm + x;

        if(x == y)
            ans = x;
#ifdef NDEBUG
        cout << ans << '\n';
#else
        if(x == y)
            ;
        else if(ans != counter % gcd(m, n)) {
            cout << "error";
            cout << "\ncounter:" << counter << " ans:" << ans;
            cout << "\nm:" << m << " n:" << n << " x:" << x << " y:" << y;
            cout << "\ntm:" << tm << " tn" << tn << " cm:" << cm << " cn:" << cn;
            break;
        } else
            cout << "NP\n";
#endif
    }

    return 0;
}