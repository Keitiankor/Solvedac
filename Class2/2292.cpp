#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int hexaCount = 0;
    int depth     = 0;
    cin >> n;
    n -= 1;
    while (n > hexaCount) {
        n -= hexaCount;
        depth++;
        hexaCount += 6;
    }

    cout << depth + 1;

    return 0;
}