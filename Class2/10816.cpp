#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(mp.find(temp) == mp.end())
            mp.insert(make_pair(temp, 1));
        else
            mp.find(temp)->second++;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if(mp.find(temp) == mp.end())
            cout << 0 << " ";
        else
            cout << mp.find(temp)->second << " ";
    }

    return 0;
}