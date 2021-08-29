#include <iostream>
using namespace std;

// Cộng 2 số bằng bit
int Add(int x, int y) 
{
    while (y != 0)
    {
        // Bộ nhớ
        unsigned int carry = x & y;

        // Sum x & y
        x = x ^ y;

        // Sum + carry
        y = carry << 1;
    }

    return x;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Sum = " << Add(x, y) << endl;
    return 0;
}