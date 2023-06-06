#include <iostream>
using namespace std;
int main() {
    int m;
    cin >> m;
    float max    = 0;
    float sum    = 0;
    float* score = new float[m];
    for(int i = 0; i < m; i++) {
        cin >> score[i];
        if(score[i] > max) max = score[i];
    }
    for(int i = 0; i < m; i++) sum += (score[i] / max) * 100;
    float avg = sum / m;
    cout << avg << '\n';
}