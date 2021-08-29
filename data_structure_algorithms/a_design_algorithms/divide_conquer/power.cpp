#include <iostream>
using namespace std;

void Input(int &x, int &y) {
    cin >> x;
    do
    {
        cin >> y;
    } while (y < 0);
}

int Power(int x, int y)
{
    if (y == 0) {
        return 1;
    }
    else if (y % 2 == 0) {
        return Power(x, y / 2) * Power(x, y / 2);
    }
    else {
        return x * Power(x, y / 2) * Power(x, y / 2);
    }
}

int main()
{
    int x;
    int y;
    Input(x, y);

    // Divide & Conquer
    cout << Power(x, y);
    return 0;
}

