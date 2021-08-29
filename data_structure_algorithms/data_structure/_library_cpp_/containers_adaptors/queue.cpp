/* Queue:

    * Thuộc tính:

        + Queue là một hàng đợi
        + FIFO (First in first out)
        + Cấp phát động (Allocator-aware)

    * Template parameters <T, Container>:

        + T: Kiểu dữ liệu cần chứa (Type of ele contained)
        + Container: Kiểu dữ liệu sử dụng bên trong (Underlying container type)

    * Function member:

        - Constructor:
            + queue(): khởi tạo với 0 element
            + queue(Container<T>): khởi tạo mà copy toàn bộ dữ liệu từ container<T>

        - Capacity:
            + size(): => size
            + empty(): => queue có rỗng? (true or false)

        - Element access:
            + font(): => reference ele[0] 
            + back(): => reference ele[n - 1] 

        - Modifiers:
            + push(value): chèn sao chép phần tử vào cuối
            + pop(value): xóa phần tử đầu
            + emplace(value): chèn trực tiếp phần tử vào cuối
            + swap(queue): hoán đổi dữ liệu 2 swap

        - Non-member function overloads:
            + swap(queue): hoán đổi dữ liệu 2 queue.
            + relational operators(dque): dùng để biểu thị toán tử quan hệ

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/

*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> a;

}