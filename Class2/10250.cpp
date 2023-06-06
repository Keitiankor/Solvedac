#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++) {
        int h, w, n;
        cin >> h >> w >> n;
        int counter = 0;
        vector<vector<bool>> acmHotel(h, vector<bool>(w, false));
        pair<int, int> wh;
        for(int ww = 0; ww < w; ww++) {
            for(int hh = 0; hh < h; hh++) {
                acmHotel[hh][ww] = true;
                counter++;
                if(counter == n) {
                    wh = make_pair(ww, hh);
                    break;
                }
            }
            if(counter == n) break;
        }

        cout << wh.second + 1;
        cout << setw(2) << setfill('0') << wh.first + 1;
        cout << endl;
    }

    return 0;
}