/* Đề bài:
Mô tả Bài toán:
Cho mảng 1 chiều số nguyên có n phần tử A[0…n-1], cần tìm Diff(A[0…n-1) = A[j] – A[i] 
đạt giá trị lớn nhất mà 0 ≤ i ≤ j < n. Ví dụ, mảng gồm 6 phần tử 4, 2, 5, 8, 1, 7 thì 
độ lệch lớn nhất cần tìm là A[3] – A[1] = 8 – 2 = 6.

Mô tả Input:
 - Dòng đầu tiên là kích thước mảng n.
 - Dòng thứ hai gồm n số nguyên cách nhau bởi một dấu khoảng trắng có miền giá trị 
thuộc đoạn [-1,073,741,823, 1,073,741,823].

Mô tả Output:
 - Độ lệch lớn nhất như đã đề cập trong phần mô tả bài toán.

Minh họa Input:
6
4 2 5 8 1 7

Minh họa Output:
6
*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/     

#include <iostream>
using namespace std;

void NhapMang(int *&a, int &n) {
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int DoLech(int *a, int n)
{
    int max = a[1] - a[0];
    int min = a[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] - min > max) {
            max = a[i] - min;
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    return max;
}

int main() {
    int *a;
    int n;
    NhapMang(a, n);

    cout << DoLech(a, n) << endl;

    delete a;
    return 0;
}