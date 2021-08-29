#include <iostream>
using namespace std;

// Kiểm tra 2 số đối nhau
bool CheckDetectSign(int x, int y) {
    return ((x ^ y) < 0);
}

int main() {
    int x, y;
    cin >> x >> y;

    // Check
    if (!CheckDetectSign(x, y)) 
    {
        cout << "Same sign\n";
    }
    else 
    {
        cout << "Not same sign\n";
    }

    return 0;
}