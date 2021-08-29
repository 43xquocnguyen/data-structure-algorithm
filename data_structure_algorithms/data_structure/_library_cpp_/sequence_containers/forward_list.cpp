/* Foward List:

    * Thuộc tính:

        + Foward-list là một singly linked list
        + Cấu trúc tuần từ (Sequence)
        + Danh sách liên kết (Linked list)
        + Cấp phát động (Allocator-aware)

    * Template parameters <T, Alloc>:

        + T: Kiểu dữ liệu cần chứa (Type of ele contained)
        + Alloc: Type of allocation object

    * Function member:

        - Constructor:
            + forward-list(): khởi tạo với 0 element
            + forward-list(n): khởi tạo với n element
            + forward-list(n, value): khởi tạo với n element với giá trị value
            + forward-list(first, last): khởi tạo với range(first, last)
            + forward-list(forward-list): khởi tạo mà copy toàn bộ dữ liệu
            + forward-list() = {a, b, c,...} khởi tạo và gán phần tử
            + forward-list(std::move(forward-list)): khởi tạo chuyển dữ liệu

        - Iterators:
            + before_begin(): => iterator: before ele[0] (Dùng làm tham số, không tham chiếu)
            + before_begin(): => const_iterator: before ele[0] (Dùng làm tham số, không tham chiếu)
            + begin(): => iterator: ele[0]
            + end(): => iterator: ele[n]
            + cbegin(): => const_iterator: ele[0] (Không thể thay đổi giá trị *it)
            + cend(): => const_iterator: ele[n] (Không thể thay đổi giá trị *it)

        - Capacity:
            + maxsize(): => maximum size
            + empty(): => có rỗng? (true or false)

        - Element access:
            + front(): => reference ele[0] 

        - Modifiers:
            + assign(first, last)/(pos, value): gán giá trị
            + emplace_front(value): chèn trực tiếp phần tử vào đầu
            + emplace_after(pos, value): chèn trực tiếp phần tử vào pos
            + push_front(value): chèn sao chép phần tử vào đầu
            + pop_front(): xóa phần tử đầu
            + insert(it, value)/(it, n, value)/(it, <>)/(it, it1, it2): chèn phần tử
            + erase(it)/(first, last): xóa phần tử
            + swap(foward-list): hoán đổi dữ liệu 2 foward-list
            + resize(n, value): resize forward-list
            + clear(): xóa toàn bộ dữ liệu

        - Operations:
            + splice_after(argument): nối 2 forward-list
            + remove(value): xóa tất cả ele có value
            + remove_if(Predicate pred): pred là một điều kiện(có thể implement bằng function hoặc class)
            + unique(Predicate pred): xóa các phần tử lặp lại
            + merge(forward-list, comp): comp là một điều kiện để merge (std::greater<>())
            + sort(comp): sort list
            + reverse(): đảo ngược list

        - Non-member function overloads:
            + swap(foward-list): hoán đổi dữ liệu 2 foward-list
            + relational operators(forward-list): dùng để biểu thị toán tử quan hệ

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/
  
*/

#include <iostream>
#include <forward_list>
using namespace std;

int main() {
  
}