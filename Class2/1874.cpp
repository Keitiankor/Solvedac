#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ostringstream ss;
    stack<int> q;
    int length, k, n;

    cin >> length;
    int* squence = new int[length];

    for(int i = 0; i < length; i++) cin >> squence[i];

    /****************
     * initializing *
     ****************/
    k = 0, n = 1;
    q.push(n);
    ss << "+\n";
    n++;

    // While Stack is not empty //
    while(q.size() > 0) {
        // While Stack's top is same with input Squence
        while(!q.empty() && q.top() == squence[k]) {
            q.pop();
            ss << "-\n";
            k++;
        }
        // Stack's top is not same with input Squence and stack size is shotter than squence length
        if(n <= length) {
            q.push(n);
            n++;
            ss << "+\n";
        }
        // Stack's top is not same with input Squence and stack is longer than squence length
        if(!q.empty() && q.top() != squence[k] && n > length) {
            cout << "NO";
            return 0;
        }
    }
    cout << ss.str();

    return 0;
}