/* Đề bài: 
Mô tả Bài toán:
Số Fibonacci bắt đầu từ số 0 và 1. Số Fibonacci khởi đầu sẽ là 0, và số Fibonacci
đầu tiên sẽ là 1. Kể từ đó, số thứ hai sẽ là tổng của hai số Fibonacci trước đó.
Công thức của Fn = Fn-1 + Fn-2 (n> = 2).

Các số Fibonacci đến n = 16 như sau: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
144, 233, 377, 610, 987.

Viết chương trình tìm ra số Fibonacci thứ n. Tuy nhiên, bởi vì con số đó có thể 
rất lớn, cho nên chúng ta sẽ in ra kết quả sau khi chia lấy dư với 1,000,000.

Các bạn có thể tham khảo 1001 số Fibonacci đầu tiên trong lúc debug chương trình 
của các bạn tại http://www.fullbooks.com/The-first-1001-Fibonacci-Numbers.html.

Tài liệu tham khảo: https://www.nayuki.io/page/fast-fibonacci-algorithms

Mô tả Input:
 - Dòng đầu tiên sẽ là số nguyên dương n với giá trị nhỏ hơn hoặc bằng 1,000,000,000,000,000,000.

Mô tả Output:
 - Kết quả của số Fibonacci thứ n sau khi chia lấy dư với 1,000,000.


Minh họa Input 1:
0

Minh họa Output 1:
0

Minh họa Input 2:
1

Minh họa Output 2:
1

Minh họa Input 3:
2

Minh họa Output 3:
1

Minh họa Input 4:
597

Minh họa Output 4:
881602
*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/     

#include <iostream>
#define hhd 1000000000
using namespace std;
const long long mod = 1000000;
long long n;
long long F[2][2], M[2][2];

void Mul(long long f[2][2], long long m[2][2])
{
	long long x = (f[0][0] * m[0][0] % mod + f[0][1] * m[1][0] % mod) % mod;
	long long y = (f[0][0] * m[0][1] % mod + f[0][1] * m[1][1] % mod) % mod;
	long long z = (f[1][0] * m[0][0] % mod + f[1][1] * m[1][0] % mod) % mod;
	long long t = (f[1][0] * m[0][1] % mod + f[1][1] * m[1][1] % mod) % mod;
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = t;
}

void Power(long long f[2][2], long long n)
{
	if (n <= 1) return;
	Power(f, n / 2);
	Mul(f, f);
	if(n & 1)
		Mul(f, M);
}

void Solve( )
{
	F[0][0] = F[0][1] = F[1][0] = 1;
	F[1][1] = 0;
	M[0][0] = M[0][1] = M[1][0] = 1;
	M[1][1] = 0;
		
	cin >> n;
	if ( n == 0)
		cout << 0;
	else
	{
		Power(F,n-1);
		cout << F[0][0];
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
    hhd;	
    Solve();
	return 0;		
}