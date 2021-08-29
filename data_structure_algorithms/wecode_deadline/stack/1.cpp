/* Đề bài: 
Yêu cầu đề bài:

Chúng ta sẽ duyệt từ trái sang phải của biểu thức toán học (được đọc từ chuỗi đầu vào).
Trong lúc duyệt chúng ta sẽ in ra các thành phần của biểu thức và loại của chúng như sau

( open_parenthesis
) close_parenthesis
+ - * / operator
một số nguyên có nhiều chữ số operand
Lưu ý: Trong bài tập này chúng ta chỉ làm việc với số nguyên dương và giới hạn của nó
nhỏ hơn 1 triệu.

Đầu vào mẫu:

((23*(6-1))/2)*4

Đầu ra mẫu:

( open_parenthesis
( open_parenthesis
23 operand
* operator
( open_parenthesis
6 operand
- operator
1 operand
) close_parenthesis
) close_parenthesis
/ operator
2 operand
) close_parenthesis
* operator
4 operand

*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/  

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void print_queue(queue<char> q)
{
	while (!q.empty())
	{
		if (q.front() == '(')
		{
			cout << q.front() << " " << "open_parenthesis" << endl;
			q.pop();
		}
		else if (q.front() == ')')
		{
			cout << q.front() << " " << "close_parenthesis" << endl;
			q.pop();
		}
		else if (q.front() == '+' || q.front() == '-' || q.front() == '*' || q.front() == '/')
		{
			cout << q.front() << " " << "operator" << endl;
			q.pop();
		}
		else
		{
			while (!q.empty() && isdigit(q.front()))
			{
				cout << q.front();
				q.pop();
			}
			cout << " " << "operand" << endl;
		}
	}
	cout << endl;
}

int main()
{
	queue<char> q;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		q.push(s[i]);
	}
	print_queue(q);
	return 0;
}