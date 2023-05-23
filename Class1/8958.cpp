#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string *s = new string[n];
    for (int i = 0; i < n; i++)
    {
        int score = 0;
        int cont = 0;
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++)
        {
            if (s[i].at(j) == 'O')
                cont++;
            else
                cont = 0;
            score += cont;
        }
        cout << score << '\n';
    }
}