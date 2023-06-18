#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    /* 산술 평균 */
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int avg = round((float)sum / (float)n);
    cout << avg << endl;

    /* 중앙값 */
    cout << arr[n / 2] << endl;

    /* 최빈값 */
    vector<pair<int, int>> frequency;
    stack<int> q;
    for (auto i : arr) {
        auto iter = find_if(frequency.begin(), frequency.end(), [i](const pair<int, int> &e) { return e.first == i; });
        if (iter != frequency.end())
            iter->second++;
        else
            frequency.push_back(make_pair(i, 1));
    }
    int maxf = 0;
    for (const auto &[key, value] : frequency) {
        if (value > maxf) {
            maxf = value;
            while (!q.empty())
                q.pop();
            q.push(key);
        } else if (value == maxf)
            q.push(key);
    }
    while (q.size() > 2)
        q.pop();
    cout << q.top() << endl;

    /* 범위 */
    cout << (arr.back() - arr.front()) << endl;
    return 0;
}