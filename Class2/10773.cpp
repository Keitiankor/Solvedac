#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    stack<int> s;

    cin >> k;

    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;

        if (temp == 0)
            s.pop();
        else
            s.push(temp);
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}