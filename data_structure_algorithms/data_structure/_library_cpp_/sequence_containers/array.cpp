/* Array:

    * Thuộc tính:
    
        - Array là một mảng một chiều
        - Cấu trúc tuần tự (Sequence)
        - Liên tiếp nhau trong bộ nhớ (Contiguous storage)
        - Size cố định (Fixed-size)

    * Template parameters <T, N>:

        + T: Kiểu dữ liệu cần chứa (Type of ele contained)
        + N: Kích thước array (Size of array)

    * Function member:

        - Constructor:
            + array(): khởi tạo với 0 element

        - Iterators:
            + begin(): => iterator: ele[0]
            + end(): => iterator: ele[n]
            + rbegin(): => reverse_iterator: ele[0] (reverse value)
            + rend(): => reverse_iterator: ele[n] (reverse value)
            + cbegin(): => const_iterator: ele[0] (Không thể thay đổi giá trị *it)
            + cend(): => const_iterator: ele[n] (Không thể thay đổi giá trị *it)
            
        - Capacity:
            + size(): => size
            + maxsize(): => maximum size
            + empty(): => array is empty? (true or false)

        - Element access:
            + operator[i]: => reference ele[i] (Không thể check index đúng/sai i)
            + at(i): => reference ele[i] (Có thể check index đúng/sai i)
            + font(): => reference ele[0] 
            + back(): => reference ele[n - 1] 
            + data(): => pointer ele[0]

        - Modifiers:
            + fill(value): gán ele[0; n - 1] với value
            + swap(array<>): đổi dữ liệu 2 array<>

        - Non-member function overloads:
            + get(array<>): ele[i] (tuple interface)
            + relational operators(array): dùng để biểu thị toán tử quan hệ

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/

*/

#include <iostream>
#include <array>
using namespace std;

int main() {
    cout << "===== Array =====\n";

    // -- Constructor -- //
    array<int, 5> first = {1, 2, 3, 4, 5};
    array<int, 5> second;

    // -- Iterator -- //
    array<int, 5>::iterator it = first.begin();
    cout << "Array: ";
    for (; it != first.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // -- Capacity -- //
    cout << "Size: " << first.size() << endl;
    cout << "Max size: " << first.max_size() << endl;
    cout << "Is empty: " << (first.empty() == true) ? "True\n" : "False\n";

    // -- Element access -- //
    cout << "Array[1]: " << first[1] << endl;
    cout << "Array.at(1): " << first.at(1) << endl;
    cout << "Front: " << first.front() << endl;
    cout << "Back: " << first.back() << endl;

    // -- Modifiers -- //
    first.fill(1000);
    swap(first, second);
    cout << "Array 2 after fill & swap: ";
    for (it = second.begin(); it != second.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}