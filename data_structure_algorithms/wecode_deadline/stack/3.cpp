/* Đề bài: 
Yêu cầu đề bài:

Chúng ta sẽ thực hiện tính toán biểu thức Postfix bao gồm 4 phép toán (+ - / *).

Gợi ý: Sử dụng cấu trúc ngăn xếp, chúng ta sử dụng thư viện
http://www.cplusplus.com/reference/stack/stack/
càng tốt, khuyến khích các bạn sử dụng thư viện.

Lưu ý: Trong bài tập này chúng ta chỉ làm việc với số nguyên dương và giới hạn
của nó nhỏ hơn 1 triệu.

Đầu vào mẫu:
2 6 1 - * 2 / 4 *

Đầu ra mẫu:
20

*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/  

#include <iostream>
using namespace std;

struct Stack
{
    int a[100];
    int top;
};
void Init(Stack &s) {
    s.top = -1;
} 
void Push(Stack &s, int x) {
    s.a[++s.top] = x;
}
void Pop(Stack &s, int &x) {
    x = s.a[s.top--];
}
void sTop(Stack s, int &x) {
    x = s.a[s.top];
}


int Postfix(char str[]) {
    int result;
    Stack s;
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t') i++;
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
            int x, y;
            Pop(s, x);
            Pop(s, y);

            switch (str[i])
            {
                case '+': {
                    Push(s, y + x);
                    break;
                }
                case '-': {
                    Push(s, y - x);
                    break;
                }
                case '*': {
                    Push(s, y * x);
                    break;
                }
                case '/': {
                    Push(s, y / x);
                    break;
                }
            }
        }
		else Push(s, (int)(str[i] - '0'));
    }
    sTop(s, result);
    return result;
}

int main() {
    char str[100];
    cin.getline(str, 100);
    cout << Postfix(str);
}
