#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int chieuCaoH;
    cin >> chieuCaoH;
    string duongDi;
    cin >> duongDi;

    int nodeMax = pow(2, chieuCaoH + 1);
    int viTri = 1;
    int length = duongDi.length();

    for (int i = 0; i < length; i++)
    {
        viTri = viTri * 2;
        if (duongDi[i] == 'R') viTri++;
    }

    cout << nodeMax - viTri << endl;
}
