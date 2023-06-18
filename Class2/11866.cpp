#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    queue<int> q;
    int counter = 1;
    for(int i = 1; i <= n; i++)
        q.push(i);

    cout << "<";

    while(!q.empty()) {
        if(counter == k) {
            cout << q.front();
            q.pop();
            counter = 0;
            if(!q.empty())
                cout << ", ";
        } else {
            q.push(q.front());
            q.pop();
        }
        counter++;
    }
    cout << ">";

    return 0;
}