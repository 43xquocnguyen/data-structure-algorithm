#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> H;
    H.resize(1000001, 0);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if(H[t] == 0) {
            H[t - 1]++;
        }
        else {
            H[t - 1]++;
            H[t]--;
        }
    }

    int min = 0;
    for(int i = 0; i < 1000000; i++) {
        min += H[i];
    }
    cout << min << endl;
}
