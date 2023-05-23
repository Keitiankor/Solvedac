#include <iostream>
using namespace std;
int main()
{
    int n[9];
    int max = 0;
    int maxi = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> n[i];
        if (n[i] > max)
        {
            max = n[i];
            maxi = i;
        }
    }
    cout << max << '\n'
         << maxi + 1;
}