#include <iostream>
using namespace std;

int Comb(int n, int k) {
    // Tính tổ hợp bằng quy hoạch động

    // Mảng lưu giá trị 
    int **matrixC = new int*[n + 1]{};
    for (int i = 0; i < n + 1; i++)
    {
        matrixC[i] = new int[n + 1]{};
    }
    
    // Dynamic Programming
    matrixC[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        matrixC[i][0] = 1;
        matrixC[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            matrixC[i][j] = matrixC[i - 1][j - 1] + matrixC[i - 1][j];
        }
    }

    return matrixC[n][k];
}

int main() {
    int n, k;
    cin >> k >> n;
    cout << Comb(n, k);
    return 0;
}