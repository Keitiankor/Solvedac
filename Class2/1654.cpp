#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;
    vector<int> lan;
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        lan.push_back(temp);
    }
    long min = 0;
    long max = 2147483647;
    long ans = 0;
    while(min <= max) {
        long mid   = (min + max) / 2;
        long count = 0;
        for(int i = 0; i < k; i++) {
            count += lan[i] / mid;
        }
        if(count < n)
            max = mid - 1;
        else {
            if(ans < mid)
                ans = mid;
            min = mid + 1;
        }
    }

    cout << ans;

    return 0;
}