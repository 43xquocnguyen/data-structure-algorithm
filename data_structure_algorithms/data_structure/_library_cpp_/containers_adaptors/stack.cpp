/* Stack:

    * Thuộc tính:

        + Stack là một ngăn xếp
        + LIFO (Last in first out)
        + Cấp phát động (Allocator-aware)

    * Template parameters <T, Container>:

        + T: Kiểu dữ liệu cần chứa (Type of ele contained)
        + Container: Kiểu dữ liệu sử dụng bên trong (Underlying container type)

    * Function member:

        - Constructor:
            + stack(): khởi tạo với 0 element
            + stack(Container<T>): khởi tạo mà copy toàn bộ dữ liệu từ container<T>

        - Capacity:
            + size(): => size
            + empty(): => stack có rỗng? (true or false)

        - Element access:
            + top(): => reference ele[n - 1] 

        - Modifiers:
            + push(value): chèn sao chép phần tử vào cuối
            + pop(value): xóa phần tử đầu
            + emplace(value): chèn trực tiếp phần tử vào cuối
            + swap(stack): hoán đổi dữ liệu 2 swap

        - Non-member function overloads:
            + swap(stack): hoán đổi dữ liệu 2 stack.
            + relational operators(dque): dùng để biểu thị toán tử quan hệ

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    vector<int> b;
    stack<int> a;
}