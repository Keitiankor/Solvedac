#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> m >> n;
    bool* prime = new bool[n + 1];
    fill_n(prime, n + 1, false);

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= (int)sqrt(i) + 1; j++) {
            if(j > (int)sqrt(i)) {
                prime[i] = true;
                break;
            }
            if(i % j == 0) break;
        }
    }

    for(int i = m; i <= n; i++)
        if(prime[i]) cout << i << "\n";
    return 0;
}
