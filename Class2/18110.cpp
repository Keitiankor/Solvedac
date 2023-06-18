#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> rating;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        rating.push_back(temp);
    }
    sort(rating.begin(), rating.end());
    float temp = (float)rating.size() * 0.15;
    int range  = round(temp);

    int sum = 0;
    for (int i = range; i < rating.size() - range; i++)
        sum += rating[i];

    float rate = (float)sum / (rating.size() - (range * 2));

    int ans = round(rate);
    if (n == 0) ans = 0;
    cout << ans;

    return 0;
}
