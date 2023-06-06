#include <cmath>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool primeT[1001];
    fill_n(primeT, 1001, false);

    for(int i = 2; i <= 1000; i++) {
        for(int j = 2; j <= (int)sqrt(i) + 1; j++) {
            if(j > (int)sqrt(i)) {
                primeT[i] = true;
                break;
            }
            if(i % j == 0) break;
        }
    }

    int temp, n, count = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(primeT[temp]) count++;
    }
    cout << count;
    return 0;
}