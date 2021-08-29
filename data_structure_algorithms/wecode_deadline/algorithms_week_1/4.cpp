/* Đề bài: 
Mô tả Bài toán:
Giả sử chúng ta có một tờ giấy hình vuông được biểu diễn bởi một ma trận vuông N x N. 
Các giá trị trong ma trận vuông đó có thể là 0, 1, 2. Mỗi phần tử trong ma trận tương 
ứng với mỗi ô vuông nhỏ trong tờ giấy. Nhiệm vụ của chúng ta là sẽ cầm kéo cắt tờ giấy 
này thành các tờ giấy con nhỏ hơn. Quy luật cắt giấy như sau:

(i) Việc cắt giấy sẽ kết thúc khi và chỉ khi chỉ có một loại giá trị duy nhất trong 
toàn bộ các tờ giấy con.

(ii) Đối với một tờ giấy con chưa thỏa điều kiện (i) chúng ta sẽ cắt tờ giấy con đó 
thành 9 tờ giấy con khác có kích thước bằng nhau. Sau đó chúng ta sẽ quay lại kiểm tra điều kiện (i).

Nhiệm vụ của chúng là sẽ đếm số lượng các tờ giấy con có giá trị 0, số lượng các tờ 
giấy con có giá trị 1, và số lượng các tờ giấy con có giá trị 2. Chúng ta lưu ý rằng 
tờ giấy con có kích thước nhỏ nhất sẽ là một ô vuông, tương ứng với một phần tử trong 
ma trận.

Mô tả Input:
 - Dòng đầu tiên là kích cỡ của ma trận vuông, N (1 <= N <= 3 ^ 7, N sẽ có dạng là 
3 ^ k, với k là số nguyên dương).
 - N dòng tiếp theo biểu diễn ma trận vuông.

Mô tả Output:
 - Dòng thứ nhất, số lượng các tờ giấy con có giá trị 0.
 - Dòng thứ hai, số lượng các tờ giấy con có giá trị 1.
 - Dòng thứ ba, số lượng các tờ giấy con có giá trị 2.

Minh họa Input:
9
0 0 0 1 1 1 2 2 2
0 0 0 1 1 1 2 2 2
0 0 0 1 1 1 2 2 2
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 2 0 1 2 0 1 2
0 2 1 0 1 2 0 1 2
0 1 2 1 0 2 0 1 2

Minh họa Output:
12
11
10
*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/           

#include <iostream>
#include <vector>
using namespace std;

void Input(vector<vector<int>> &arr, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

bool CheckSameSquare(vector<vector<int>>& arr, int x, int y, int width) 
{
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + width; j++) {
            if (arr[i][j] != arr[x][y]) {
                return false;
            }
        }
    }
    return true;
}
void Counting(vector<vector<int>> &arr, int numberSquare[3], int x, int y, int width) {
    if (CheckSameSquare(arr, x, y, width)) 
    {
        int index = arr[x][y];
        numberSquare[index]++;
    }
    else {
        for (int i = x; i < x + width; i += width / 3) {
            for (int j = y; j < y + width; j += width / 3) {
                Counting(arr, numberSquare, i, j, width / 3);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    
    int n = -1;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    Input(arr, n);

    int numberSquare[3] = {0, 0, 0};
    Counting(arr, numberSquare, 0, 0, n);

    cout << numberSquare[0] << endl << numberSquare[1] << endl << numberSquare[2];

    return 0;
}