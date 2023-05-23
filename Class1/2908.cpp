#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string s1r, s2r;
    for (int i = 0; i < s1.length(); i++)
        s1r.push_back(s1.at(s1.length() - i - 1));
    for (int i = 0; i < s2.length(); i++)
        s2r.push_back(s2.at(s2.length() - i - 1));
    int n1 = stoi(s1r);
    int n2 = stoi(s2r);
    if (n1 > n2)
        cout << n1;
    else
        cout << n2;
}