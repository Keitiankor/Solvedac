#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int countof2 = 0;
    int countof5 = 0;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int temp = i;

        while (temp % 2 == 0) {
            temp = temp / 2;
            countof2++;
        }
        while (temp % 5 == 0) {
            temp = temp / 5;
            countof5++;
        }
    }

    cout << (countof2 > countof5 ? countof5 : countof2);

    return 0;
}