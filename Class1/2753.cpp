#include <iostream>
using namespace std;
int main() {
    int y;
    cin >> y;
    int check = 0;
    if (y % 4 == 0)
        check = 1;
    if (y % 100 == 0)
        check = 0;
    if (y % 400 == 0)
        check = 1;
    cout << check;
    return 0;
}