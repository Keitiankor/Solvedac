#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> landscape;

    int n, m, b;
    cin >> n >> m >> b;

    for(int i = 0; i < n * m; i++) {
        int temp;
        cin >> temp;
        landscape.push_back(temp);
    }

    sort(landscape.begin(), landscape.end());

    int low = landscape[0];

    int ans = 2100000000;
    int height;

    while(true) {
        bool isValid = false;
        int fill     = 0;
        int cut      = 0;
        for(int i = 0; i < n * m; i++) {
            if(landscape[i] < low)
                fill += low - landscape[i];
            if(landscape[i] > low)
                cut += landscape[i] - low;
        }
        if((b + cut) - fill >= 0)
            isValid = true;
        if(isValid) {
            int time = fill + cut * 2;
            if(ans >= time) {
                ans    = time;
                height = low;
                low++;
            } else {
                break;
            }
        } else
            break;
    }

    cout << ans << " " << height;

    return 0;
}