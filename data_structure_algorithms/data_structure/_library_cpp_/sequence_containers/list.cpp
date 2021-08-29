/* List:

    * Thuộc tính:

        + List là một doubly linked list
        + Cấu trúc tuần từ (Sequence)
        + Danh sách liên kết (Linked list)
        + Cấp phát động (Allocator-aware)

    * Template parameters <T, Alloc>:

        + T: Kiểu dữ liệu cần chứa (Type of ele contained)
        + Alloc: Type of allocation object

    * Function member:

        - Constructor:
            + List(): khởi tạo với 0 element
            + List(n): khởi tạo với n element
            + List(n, value): khởi tạo với n element với giá trị value
            + List(first, last): khởi tạo với range(first, last)
            + List(List): khởi tạo mà copy toàn bộ dữ liệu
            + List() = {a, b, c,...} khởi tạo và gán phần tử
            + List(std::move(List)): khởi tạo chuyển dữ liệu

        - Iterators:
            + begin(): => iterator: ele[0]
            + end(): => iterator: ele[n]
            + rbegin(): => reverse_iterator: ele[0] (reverse value)
            + rend(): => reverse_iterator: ele[n] (reverse value)
            + cbegin(): => const_iterator: ele[0] (Không thể thay đổi giá trị *it)
            + cend(): => const_iterator: ele[n] (Không thể thay đổi giá trị *it)
            + crbegin(): => const_reverse_iterator: ele[0] (Không thể thay đổi giá trị *it)
            + crend(): => const_reverse_iterator: ele[n] (Không thể thay đổi giá trị *it)

        - Capacity:
            + size(): => size
            + max_size(): => maximum size
            + empty(): => có rỗng? (true or false)

        - Element access:
            + front(): => reference ele[0] 
            + back(): => reference ele[n - 1] 

        - Modifiers:
            + assign(first, last)/(pos, value): gán giá trị
            + emplace_front(value): chèn trực tiếp phần tử vào đầu
            + push_front(value): chèn sao chép phần tử vào đầu
            + pop_front(): xóa phần tử đầu
            + emplace_back(value): chèn trực tiếp phần tử vào cuối
            + push_back(value): chèn sao chép phần tử vào cuối
            + pop_back(): xóa phần tử cuối
            + emplace(pos, value): chèn trực tiếp phần tử vào pos
            + insert(it, value)/(it, n, value)/(it, <>)/(it, it1, it2): chèn phần tử
            + erase(it)/(first, last): xóa phần tử
            + swap(list): hoán đổi dữ liệu 2 list
            + resize(n, value): resize forward-list
            + clear(): xóa toàn bộ dữ liệu

        - Operations:
            + splice(argument): nối 2 forward-list
            + remove(value): xóa tất cả ele có value
            + remove_if(Predicate pred): pred là một điều kiện(có thể implement bằng function hoặc class)
            + unique(Predicate pred): xóa các phần tử lặp lại
            + merge(forward-list, comp): comp là một điều kiện để merge (std::greater<>())
            + sort(comp): sort list
            + reverse(): đảo ngược list

        - Non-member function overloads:
            + swap(list): hoán đổi dữ liệu 2 list
            + relational operators(dque): dùng để biểu thị toán tử quan hệ

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/

*/

#include <list>
#include <iostream>
using namespace std;

int main() {
    
}