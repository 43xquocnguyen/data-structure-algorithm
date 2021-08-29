/* Đề bài: 
Tìm số tổ hợp giá trị không có thứ tự của N con xúc xắc thỏa tổng của chúng là M

INPUT:

- Giá trị thứ nhất là số xúc xắc N (một số nguyên dương không quá 12).

- Giá trị thứ hai là tổng M của N xúc xắc trên mà chúng ta kỳ vọng.

OUTPUT:

- Số cách chọn N con xúc xắc sao cho tổng của chúng bằng M, lưu ý số cách chọn 
không phân biệt thứ tự xúc xắc trước sau.

VÍ DỤ:
____________________________________________________________________
|   Input   | Output |                  Giải thích                 |
____________________________________________________________________
| 2 5       | 2      | {4, 1}, {3, 2}                              |
____________________________________________________________________
| 2 7       | 3      | {6, 1}, {5, 2}, {4, 3}                      |
____________________________________________________________________
| 3 9       | 6      | {6, 2, 1}, {5, 3, 1}, {4, 4, 1}, {5, 2, 2}, |
|           |        | {4, 3, 2}, {3, 3, 3}                        |
____________________________________________________________________

*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/     

#include <iostream>
using namespace std;

int SoToHop(int soConLai, int tong, int viTriHienTai) {
    if (soConLai == 0) {
        if (tong == 0) {
            return 1;
        }
        return 0;
    }
    
    if (tong < 0) {
        return 0;
    }

    int keuQua = 0;

    for (int x = viTriHienTai; x <= 6; x++)
    {
        keuQua += SoToHop(soConLai - 1, tong - x, x);
    }
    
    return keuQua;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << SoToHop(n, m, 1);
    return 0;
}