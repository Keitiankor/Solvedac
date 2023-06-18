#include <iostream>

using namespace std;

int check(bool* paper, int w, int b, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    bool* paper = new bool[n * n];
    bool* check = new bool[n * n];
    for (int i; i < n * n; i++) {
        int t;
        cin >> t;
        paper[i] = t;
    }
    fill_n(check, n * n, false);
    int tempt  = n;
    int countw = 0;
    int countb = 0;

    while (true) {
        for (int i = 0; i < n; i += tempt) {
            for (int j = 0; j < n; j += tempt) {
                if (check[i * n + j] == false) {
                    bool flagw = true;
                    bool flagb = true;
                    for (int y = i; y < i + tempt; y++) {
                        for (int z = j; z < j + tempt; z++) {
                            if (paper[y * n + z] != false) flagw = false;
                            if (paper[y * n + z] != true) flagb = false;
                        }
                    }
                    if (flagw) {
                        countw++;
                        for (int y = i; y < i + tempt; y++)
                            fill_n(&check[y * n + j], tempt, true);
                    }
                    if (flagb) {
                        countb++;
                        for (int y = i; y < i + tempt; y++)
                            fill_n(&check[y * n + j], tempt, true);
                    }
                }
            }
        }
        if (tempt == 1) break;
        tempt /= 2;
    }

    cout << countw << '\n' << countb;

    return 0;
}