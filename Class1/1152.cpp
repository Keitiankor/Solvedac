#include <iostream>
using namespace std;

int main(void)
{
    string text;
    int count = 1;

    cin.clear();
    getline(cin, text);

    for (int i = 0; i < text.size(); i++)
        if (text[i] == ' ')
            count++;

    if (text[0] == ' ')
        count--;
    if (text[text.size() - 1] == ' ')
        count--;
    cout << count;
}