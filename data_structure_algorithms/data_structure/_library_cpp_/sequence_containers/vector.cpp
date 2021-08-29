/* Vector:

    * Thuộc tính:
    
        - Vector là một mảng một chiều
        - Cấu trúc tuần tự (Sequence)
        - Mảng động (Dynamic array)
        - Cấp phát động (Allocator-aware)

    * Template parameters <T, Alloc>:

        + T: Kiểu dữ liệu cần chứa (Type of ele contained)
        + Alloc: Type of allocation object

    * Function member:

        - Constructor:
            + vector(): khởi tạo với 0 element
            + vector(n): khởi tạo với n element
            + vector(n, value): khởi tạo với n element với giá trị value
            + vector(first, last): khởi tạo với range(first, last)
            + vector(vector): khởi tạo mà copy toàn bộ dữ liệu
            + vector() = {a, b, c,...} khởi tạo và gán phần tử
            + vector(std::move(vector)): khởi tạo chuyển dữ liệu

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
            + resize(n): change size
            + capacity(): => trả về bộ nhớ cần lưu trữ
            + empty(): => deque có rỗng? (true or false)
            + reverse():
            + shink_to_fit(): điều chỉnh size cho vừa với số phần tử (dùng sau resize)

        - Element access:
            + operator[i]: => reference ele[i] (Không thể check index đúng/sai i)
            + at(i): => reference ele[i] (Có thể check index đúng/sai i)
            + font(): => reference ele[0] 
            + back(): => reference ele[n - 1] 
            + data(): => pointer ele[0]

        - Modifiers:
            + assign(first, last)/(pos, value): gán giá trị
            + push_back(value): chèn sao chép phần tử vào cuối
            + pop_back(value): xóa phần tử vào cuối
            + insert(it, value)/(it, n, value)/(it, <>)/(it, it1, it2): chèn phần tử
            + erase(it)/(first, last): xóa phần tử
            + swap(deque): hoán đổi dữ liệu 2 deque
            + clear(): xóa toàn bộ dữ liệu
            + emplace(it, value): chèn trực tiếp phần tử vào pos
            + emplace_back(value): chèn trực tiếp phần tử vào cuối  

        - Non-member function overloads:
            + swap(vector<>): đổi dữ liệu 2 vector<>
            + relational operators(vector): dùng để biểu thị toán tử quan hệ

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

}