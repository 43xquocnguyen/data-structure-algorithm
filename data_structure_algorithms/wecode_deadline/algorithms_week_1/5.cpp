/* Đề bài: 
Tìm số cách sắp xếp một bộ số nguyên dương [a_1, a_2, ..., a_n] vào một hàng gồm
m chỗ trống (m > n) theo thứ tự như trong bộ số. Phần tử thứ i là a_i của bộ số
sẽ chiếm a_i chỗ. Lưu ý, một điều kiện nữa đó là khoảng cách giữa mỗi a_i và 
a_j là tối thiểu một khoảng trắng.

Giới hạn: 1 <= m <= 30; 1 <= n <= 6.

Ví dụ minh hoạ chúng ta có tổng cộng 6 cách sắp xếp bộ số [2, 1] vào một hàng 
gồm 6 chỗ trống.
 

Cách 1:   |*|*|_|*|_|_|

Cách 2:   |*|*|_|_|*|_|

Cách 3:   |*|*|_|_|_|*|

Cách 4:   |_|*|*|_|*|_|

Cách 5:   |_|*|*|_|_|*|

Cách 6:   |_|_|*|*|_|*|

Ví dụ mẫu (hàng đầu tiên là kích cỡ của hàng gồm m chỗ trống; hàng thứ hai là 
kích cỡ của bộ số (n); n hàng tiếp theo là các phần tử của bộ số; kết quả xuất
ra là số cách sắp xếp).

__________________
|  Input  |Output|
__________________
| 9       | 6    |
| 2       |      |
| 2 4     |      |
__________________
| 20      | 126  |
| 4       |      |
| 2 5 1 4 |      |
__________________

*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/     

#include <iostream>
#include <vector>
using namespace std;

void Input(vector<int> arr, int &n, int &m, int &sumArr) {
	cin >> m;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sumArr += x;
		arr.push_back(x);
	}
}
int Comb(int k, int n) {
	// tính tổ hợp bằng quy hoạch động
	int **matrixC = new int *[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		matrixC[i] = new int[n + 1];
	}
	
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

int main()
{
	int m, n;
	vector<int> arr;
	int sumArr = 0;
	Input(arr, n, m, sumArr);

	int vtn = m - sumArr - n + 1;
	cout << Comb(vtn, vtn + n);
	return 0;
}