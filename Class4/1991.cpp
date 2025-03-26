#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef ONLINE_JUDGE
#    define NDEBUG
#endif

string preorder  = "";
string inorder   = "";
string postorder = "";

void traversal(vector<pair<int, string>> tree, int index) {
    auto pa = find_if(tree.begin(), tree.end(), [index](pair<int, string> p) { return p.first == index; });
    if(pa->second == ".")
        return;
    preorder.append(pa->second);
    traversal(tree, index * 2 + 1);
    inorder.append(pa->second);
    traversal(tree, index * 2 + 2);
    postorder.append(pa->second);
}

int main() {
#ifdef NDEBUG
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    vector<pair<int, string>> tree;
    tree.push_back(make_pair(0, "A"));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string c, l, r;
        cin >> c >> l >> r;
        auto pa   = find_if(tree.begin(), tree.end(), [c](pair<int, string> p) { return p.second == c; });
        int index = pa->first;
        tree.push_back(make_pair(index * 2 + 1, l));
        tree.push_back(make_pair(index * 2 + 2, r));
    }

    traversal(tree, 0);

    cout << preorder << endl << inorder << endl << postorder << endl;

    return 0;
}