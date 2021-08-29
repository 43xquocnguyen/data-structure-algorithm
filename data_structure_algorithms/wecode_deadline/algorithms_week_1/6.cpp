/* Đề bài: 
Tìm số bộ nghiệm nguyên không âm của phương trình bậc nhất nhiều ẩn số

INPUT:

- Dòng đầu tiên chứa một số nguyên dương \(N\) nhỏ hơn \(10\), đây số lượng hệ số
 bên trái của phương trình bậc nhất nhiều ẩn.

- Dòng thứ hai chứa \(N\) số nguyên dương là giá trị của các hệ số nhỏ hơn \(120\),
cụ thể là \(k_1, k_2, ..., k_{N-1}, k_{N}\).

- Dòng cuối cùng chứa một số nguyên dương \(M\) là giá trị của vế phải của phương
trình bậc nhất nhiều ẩn số.

OUTPUT:

- Số bộ nghiệm nguyên không âm của phương trình đã cho, cụ thể là số bộ số nguyên
không âm \((x_1, x_2, ..., x_{N-1}, x_{N})\) thỏa mãn phương trình 
\(k_1x_1 + k_2x_2 + ... + k_{N-1}x_{N-1} + k_{N}x_{N} = M\).

VÍ DỤ:
______________________
|   Input   | Output |
______________________
| 1         | 1      |
| 2         |        |
| 4         |        |
______________________
| 2         | 1      |
| 3 4       |        |
| 9         |        |
______________________
| 3         | 3      |
| 2 3 4     |        |
| 9         |        |
______________________
| 4         | 5      |
| 1 9 9 6   |        |
| 14        |        |
______________________
| 2         | 0      |
| 100 90    |        |
| 50        |        |
______________________

*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/     

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &coeff, int n) {
    int x;
    while (n--)
    {
        cin >> x;
        coeff.push_back(x);
    }
}

int NumberSolution(vector<int> coeff, int start, int end, int m)
{
    if (m == 0) {
        return 1;
    }
    int result = 0;
 
    for (int i = start; i <= end; i++) {
        if (coeff[i] <= m) {
            result += NumberSolution(coeff, i, end, m - coeff[i]);
        }
    }
 
    return result;
}
 
int main()
{
    vector<int> coeff;
    int n, m;
    cin >> n;
    Input(coeff, n);
    cin >> m;
    cout << NumberSolution(coeff, 0, n - 1, m);
    

    return 0;
}