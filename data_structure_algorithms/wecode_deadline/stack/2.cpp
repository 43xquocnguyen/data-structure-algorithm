/* Đề bài: 
Yêu cầu đề bài:

Chúng ta sẽ chuyển đổi biểu thức toán học bình thường bao gồm 4 phép toán (+ - / *)
(được biểu diễn thông qua chuỗi đầu vào). Sau đó chúng ta sẽ duyệt từng thành phần
tử trái sang phải và chuyển đổi sang biểu thức Postfix.

Gợi ý: Sử dụng cấu trúc ngăn xếp, chúng ta sử dụng thư viện:
http://www.cplusplus.com/reference/stack/stack/
càng tốt, khuyến khích các bạn sử dụng thư viện.

Lưu ý: Trong bài tập này chúng ta chỉ làm việc với số nguyên dương và giới hạn của
nó nhỏ hơn 1 triệu.

Đầu vào mẫu:

((((2+3)*(4+5))*3)+9-2*10)/7

Đầu ra mẫu:

2 3 + 4 5 + * 3 * 9 + 2 10 * - 7 /

*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/  

#include <iostream>
#include <stack>
using namespace std;
 
int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s) {
 
    stack<char> st; 
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(')
            st.push('(');

        else if(c == ')') {
            while(!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        char temp = st.top();
        st.pop();
        result += temp;
    }
 
    cout << result << endl;
}
 
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}