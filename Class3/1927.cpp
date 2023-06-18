#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<int> minheap;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t != 0) {
            minheap.insert(t);
        } else {
            auto iter = minheap.begin();
            if (minheap.empty())
                cout << 0 << '\n';
            else {
                cout << *iter << '\n';
                minheap.erase(iter);
            }
        }
    }

    return 0;
}