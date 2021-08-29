/* Đề bài: 
Yêu cầu đề bài:

Chúng ta sẽ thực hiện tính toán biểu thức số học thông thường bao gồm 4 phép toán (+ - / *).

Gợi ý: Sử dụng cấu trúc ngăn xếp, chúng ta sử dụng thư viện:
http://www.cplusplus.com/reference/stack/stack/
càng tốt, khuyến khích các bạn sử dụng thư viện.

Lưu ý: Trong bài tập này chúng ta chỉ làm việc với số nguyên dương và giới hạn của nó nhỏ
hơn 1 triệu.

Đầu vào mẫu:

((2*(6-1))/2)*4

Đầu ra mẫu:

20

*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/  

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}

int applyOp(int a, int b, char op){
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int evaluate(string str) {
	int i;
	stack<int> val;
	stack<char> ops;

	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') continue; 
		else if(str[i] == '(')
			ops.push(str[i]);
		else if (isdigit(str[i])) {
			int k = 0;
			while(i < str.length() && isdigit(str[i]))
			{
				k = (k * 10) + (str[i] - '0');
				i++;
			}
			
			val.push(k);
			i--;
		}
		else if (str[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				int val2 = val.top();
				val.pop();
				
				int val1 = val.top();
				val.pop();
				
				char op = ops.top();
				ops.pop();
				
				val.push(applyOp(val1, val2, op));
			}
			
			if(!ops.empty())
			ops.pop();
		}
		else
		{
			while(!ops.empty() && precedence(ops.top()) >= precedence(str[i])) {
				int val2 = val.top();
				val.pop();
				
				int val1 = val.top();
				val.pop();
				
				char op = ops.top();
				ops.pop();
				
				val.push(applyOp(val1, val2, op));
			}

			ops.push(str[i]);
		}
	}
	while (!ops.empty()) {
		int val2 = val.top();
		val.pop();
				
		int val1 = val.top();
		val.pop();
				
		char op = ops.top();
		ops.pop();
				
		val.push(applyOp(val1, val2, op));
	}
	return val.top();
}

int main() {
	string str;
	getline(cin, str);
	cout << evaluate(str);
	return 0;
}

