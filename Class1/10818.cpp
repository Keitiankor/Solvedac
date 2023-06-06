#include <iostream>
using namespace std;
int main() {
    int n;
    int min = 1000001;
    int max = -1000001;
    cin >> n;
    int* l = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> l[i];
        if(l[i] < min) min = l[i];
        if(l[i] > max) max = l[i];
    }
    cout << min << " " << max << '\n';
}