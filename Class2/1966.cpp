#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        deque<int> pq;

        int n, m, pc = 0;
        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            pq.push_back(temp);
        }

        while (true) {
            int front    = pq.front();
            bool trigger = false;
            for (int p = front + 1; p < 10; p++) {
                if (find(pq.begin(), pq.end(), p) != pq.end()) {
                    trigger = true;
                    break;
                }
            }
            pc++;
            if (!trigger && m == 0) break;

            if (trigger) {
                pq.push_back(pq.front());
                pc--;
            }
            pq.pop_front();
            m = m - 1;
            if (m < 0) m += pq.size();
        }

        cout << pc << '\n';
    }

    return 0;
}