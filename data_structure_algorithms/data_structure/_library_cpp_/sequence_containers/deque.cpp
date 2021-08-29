/* Deque:

    * Thuộc tính:

        + Deque là một double queue
        + Cấu trúc tuần tự (Sequence)
        + Mảng động (Dynamic deque)
        + Cấp phát động (Allocator-aware)

    * Template parameters <T, Alloc>:

        + T: Kiểu dữ liệu cần chứa (Type of ele contained)
        + Alloc: Type of allocation object

    * Function member:

        - Constructor:
            + deque(): khởi tạo với 0 element
            + deque(n): khởi tạo với n element
            + deque(n, value): khởi tạo với n element với giá trị value
            + deque(deque): khởi tạo mà copy toàn bộ dữ liệu

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
            + maxsize(): => maximum size
            + resize(n): change size
            + empty(): => deque có rỗng? (true or false)
            + shink_to_fit(): điều chỉnh size cho vừa với số phần tử (dùng sau resize)

        - Element access:
            + operator[i]: => reference ele[i] (Không thể check i đúng/sai)
            + at(i): => reference ele[i] (Có thể check i đúng/sai)
            + font(): => reference ele[0] 
            + back(): => reference ele[n - 1] 

        - Modifiers:
            + assign(first, last)/(pos, value): gán giá trị
            + emplace(it, value): chèn trực tiếp phần tử vào pos
            + emplace_font(value): chèn trực tiếp phần tử vào đầu
            + emplace_back(value): chèn trực tiếp phần tử vào cuối  
            + push_back(value): chèn sao chép phần tử vào cuối
            + push_font(value): chèn sao chép phần tử vào đầu
            + pop_back(value): xóa phần tử vào cuối
            + pop_font(value): xóa phần tử vào đầu
            + insert(it, value)/(it, n, value)/(it, <>)/(it, it1, it2): chèn phần tử
            + erase(it)/(first, last): xóa phần tử
            + swap(deque): hoán đổi dữ liệu 2 deque
            + clear(): xóa toàn bộ dữ liệu

        - Allocator:
            + get_allocator(count): return bản sao được cấp phát

        - Non-member function overloads:
            + swap(deque): hoán đổi dữ liệu 2 deque.
            + relational operators(dque): dùng để biểu thị toán tử quan hệ

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/
    
*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    cout << "===== Deque =====\n";

    // -- Constructor -- //
    deque<int> first = {1, 2, 3, 4}; // 1 2 3 4 
    deque<int> second(3); // 0 0 0
    deque<int> third(2, 2); // 2 2 
    deque<int> fourth(third); // 2 2

    // -- Iterator -- //
    deque<int>::iterator it = first.begin();
    cout << "Deque: ";
    for (; it != first.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // -- Capacity -- //
    cout << "Size: " << first.size() << endl;
    cout << "Max size: " << first.max_size() << endl;
    first.resize(5, 10);
    first.shrink_to_fit();
    cout << "Re size: " << first.size() << endl;
    cout << "Is empty: " << (first.empty() == true) ? "True\n" : "False\n";

    // -- Element access -- //
    cout << "deque[1]: " << first[1] << endl;
    cout << "deque.at(1): " << first.at(1) << endl;
    cout << "Front: " << first.front() << endl;
    cout << "Back: " << first.back() << endl;

    // -- Modifiers -- //
    swap(first, second);
    cout << "deque 2 after swap: ";
    for (it = second.begin(); it != second.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}