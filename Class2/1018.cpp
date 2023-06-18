#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
int diff(vector<string> vmn);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    tuple<int, int, int> point;
    int m, n;
    cin >> m >> n;
    vector<string> vmn;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        vmn.push_back(t);
    }

    cout << diff(vmn);

    return 0;
}

int diff(vector<string> vmn) {
    int x     = vmn[0].size() - 8;
    int y     = vmn.size() - 8;
    int min   = 2500;
    int count = 0;
    char w    = 'W';
    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= x; j++) {
            for (int ii = 0; ii < 8; ii++) {
                for (int jj = 0; jj < 8; jj++) {
                    if (vmn[ii + i][jj + j] != w) count++;
                    w = w == 'W' ? 'B' : 'W';
                }
                w = w == 'W' ? 'B' : 'W';
            }

            if (count > 32) count = 64 - count;
            if (count < min) min = count;
            count = 0;
        }
    }

    return min;
}