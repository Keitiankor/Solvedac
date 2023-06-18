#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int check[26] = {0};
    char lower    = 'a';
    char upper    = 'A';
    char output   = '0';
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < s.length(); j++)
            if(s.at(j) == lower || s.at(j) == upper)
                check[i]++;
        lower++;
        upper++;
    }
    int max    = 0;
    bool multi = false;
    for(int i = 0; i < 26; i++) {
        if(check[i] == max)
            multi = true;
        if(check[i] > max) {
            max    = check[i];
            output = i + 'A';
            multi  = false;
        }
    }
    if(multi)
        cout << "?";
    else
        cout << output;
}