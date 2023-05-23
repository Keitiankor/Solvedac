#include <iostream>
using namespace std;
int main()
{
    int arr[10];
    int check[43] = {0};
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] % 42;
        check[arr[i]]++;
    }
    for (int i = 0; i < 43; i++)
        if (check[i] != 0)
            counter++;
    cout << counter;
}