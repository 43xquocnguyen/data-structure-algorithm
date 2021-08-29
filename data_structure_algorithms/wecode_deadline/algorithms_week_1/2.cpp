/* Đề bài: 
Mô tả Bài toán:
Giả sử chúng ta muốn biết quả của phép lũy thừa A ^ B. Tuy nhiên, bởi vì kết quả phép
lũy thừa trên có thể là một con số rất lớn, nên chúng ta sẽ thực hiện một phép chia 
lấy dư với C. Bạn hãy viết chương trình tìm số dư đó.

Mô tả Input:
 - Dòng đầu tiên sẽ là ba số nguyên dương A, B, C có giá trị nhỏ hơn 2,147,483,647.

Mô tả Output:
 - Kết quả phần dư sau khi thực hiện phép chia giữa A ^ B và C.

Minh họa Input:
2 10 1000

Minh họa Output:
24
*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/     

#include <iostream>
using namespace std;

long TimSoDu(int a, int b, int c)
{
	if (b == 0)
		return 1;
	else
	{
		if (b % 2 != 0)
			return (a * TimSoDu(a, b - 1, c)) % c;
		else
			return (TimSoDu(a, b / 2, c) * TimSoDu(a, b / 2, c)) % c;
	}
}

void NhapBaSo(int &a, int &b, int &c)
{
	cin >> a; cin >> b; cin >> c;
}

int main() 
{
	int a, b, c;
	NhapBaSo(a, b, c);
	cout << TimSoDu(a, b, c);
	return 0;
}