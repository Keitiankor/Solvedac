#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int count = 0;
    while (true) {
        if (n == 7 || n == 4) {
            count = -1;
            break;
        }
        while (n >= 5) {
            n -= 5;
            count++;
        }
        while (true) {
            if (n % 3 == 0)
                count += n / 3;
            else if ((n + 5) % 3 == 0)
                count += ((n + 5) / 3) - 1;
            else if ((n + 10) % 3 == 0)
                count += ((n + 10) / 3) - 2;
            else if ((n + 15) % 3 == 0)
                count += ((n + 15) / 3) - 3;
            break;
        }
        break;
    }
    cout << count;

    return 0;
}