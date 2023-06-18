#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> sumation123(12);
    for (int i = 1; i < 12; i++) {
        switch (i) {
        case 1:
            sumation123[i] = 1;
            break;
        case 2:
            sumation123[i] = 2;
            break;
        case 3:
            sumation123[i] = 4;
            break;

        default:
            sumation123[i] = sumation123[i - 1] + sumation123[i - 2] + sumation123[i - 3];
            break;
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << sumation123[n] << '\n';
    }

    return 0;
}