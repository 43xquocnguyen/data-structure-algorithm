#include <iostream>
using namespace std;

// Đếm số bit 1 có trong số {x}
int CountBit(int i) {
    int count = 0;

    while (i)
    {
        // Đếm tính theo bit cuối
        count += (i & 1);
        
        // Dịch phải cho mất bit cuối 
        i = i >> 1;
    }

    return count;
}

// Đếm tổng bit từ [1 - n]
int CountBitForm1ToN(int n) 
{
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += CountBit(i);
    }

    return total;
}

int main() {
    int n;
    cin >> n;
    cout << "Total bit set: " << CountBitForm1ToN(n) << endl;
    return 0;
}