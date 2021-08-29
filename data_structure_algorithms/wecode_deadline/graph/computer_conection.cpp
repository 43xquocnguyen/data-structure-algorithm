/* Đề bài: 
Thầy Sơn mới thiết kế một hệ thống N máy tính (các máy tính được đánh số từ 1 đến N)
được nối lại thành một mạng bởi M kênh nối, mỗi kênh nối hai máy nào đó và cho phép
ta truyền tin từ máy này sang máy kia. Nhưng không may rằng Thầy Sơn đã bị một hacker
nào đó tấn công vào một máy bất kì trong N máy. Để khắc phục sự cố thì thầy Sơn cần
liệt kê ra các máy đã bị tấn công. Mặc dù vậy nhưng mà hệ thống máy tính của thầy
rất lớn nên không thể liệt kê bằng cách thông thường được. Em hãy viết chương trình
giúp thầy Sơn xác định các máy bị tấn công? Biết rằng, nếu một máy bị cấn công thì
các máy được kết nối trực tiếp cũng sẽ bị tấn công.  

Dữ liệu:  
 - Dòng thứ nhất gồm số nguyên N(1 <= N <= 10^5), M(1 <= M <= min(10^5, (N*(N-1)/2)))
Trong đó, N là số máy tính và M là số kênh nối. 
 - M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u và v (1 <= u != v <= N), cho biết máy
u sẽ kết nối trực tiếp với máy v. 
 - Dòng cuối cùng chứa số nguyên s (1 <= s <= N), là số hiệu của máy bị tấn công.

Kết quả:   
 - Dòng đầu tiên in ra số lượng các máy bị tấn công. 
 - Dòng thứ hai in ra dãy số hiệu các máy tính bị tấn công theo thứ tự tăng dần.  

VÍ DỤ:
______________________
|   Input   | Output |
______________________
| 5 4       | 4      |
| 1 2       | 1 2 3 5|
| 3 2       |        |
| 3 5       |        |
| 1 3       |        |
| 2         |        |
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

vector<vector<int>> v; // luu cac ket noi
vector<bool> check; // check
vector<int> u; // ket qua
int sum = 0; // so luong bi tan cong

void DFS(int s) {
    sum++;
    u.push_back(s);
    check[s] = true;
    for (auto i : v[s])
    {
        if (!check[i]) {
            DFS(i);
        }
    }
}

int main() {
    int n, m, a, b, s;
    cin >> n >> m;

    v.resize(n + 1);
    check.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> s;
    DFS(s);
    cout << sum << endl;
    sort(u.begin(), u.end());

    for (auto (i) : u)
    {
        cout << i << " ";
    }
    
    return 0;
}