#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    set<int> x;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        x.insert(arr[i]);
    }
    map<int, int> m;
    set<int>::iterator iter = x.begin();
    for(int i = 0; iter != x.end(); i++, iter++) m.insert(make_pair(*iter, i));
    for(int i = 0; i < n; i++) cout << m.find(arr[i])->second << " ";

    return 0;
}