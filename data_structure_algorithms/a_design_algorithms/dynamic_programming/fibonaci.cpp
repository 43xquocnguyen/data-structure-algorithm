#include <iostream>
using namespace std;

int Fibonaci(int n)
{
    // Mảng lưu kết quả các bài toán con
    int *fibo = new int[n + 1];
    int i;
    fibo[0] = 0;
    fibo[1] = 1;
    for (i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[n];
}

int main()
{
    int n;
    cin >> n;

    // Dynamic Programming
    cout << "Fibonaci number " << n << " is " << Fibonaci(n);
    return 0;
}