#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    if(n == k) {
        cout << 0;
        return 0;
    }

    if(n > k) {
        cout << n - k;
        return 0;
    }

    int count = 0;
    bool isVisited[MAX];
    fill_n(isVisited, MAX, false);
    queue<int> trace;
    trace.push(n);
    isVisited[n] = true;
    trace.push(-1);
    while(true) {
        if(trace.front() == k) break;
        if(trace.front() == -1) {
            count++;
            trace.push(-1);
        } else {
            if(trace.front() * 2 < MAX && !isVisited[trace.front() * 2]) {
                trace.push(trace.front() * 2);
                isVisited[trace.front() * 2] = true;
            }
            if(!isVisited[trace.front() + 1] && trace.front() + 1 < MAX) {
                isVisited[trace.front() + 1] = true;
                trace.push(trace.front() + 1);
            }
            if(!isVisited[trace.front() - 1] && trace.front() - 1 >= 0) {
                isVisited[trace.front() - 1] = true;
                trace.push(trace.front() - 1);
            }
        }
        trace.pop();
    }

    cout << count;

    return 0;
}