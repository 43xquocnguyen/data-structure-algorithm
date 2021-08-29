/* Map:

    * Thuộc tính:

        + Liên kết giữa key và value (Associative)
        + Trình tự nghiêm ngặt (Ordered)
        + Mỗi key ánh xạ 1 value (Map)
        + Các key là duy nhất (Unique key)
        + Cấp phát động (Allocator-aware)

    * Template parameters <Key, T, Compare, Alloc>:

        + Key: Kiểu dữ liệu của key (Type of key)
        + T: Kiểu dữ liệu cần chứa (Type of value)
        + Compare: Đối tượng so sánh thuộc tính (Binary Predicate)
        + Alloc: Type of allocation object

    * Function member:

        - Constructor:
            + map(): khởi tạo với 0 element
            + map(first, last): khởi tạo với range[first, last]
            + map(Container<T>): khởi tạo mà copy toàn bộ dữ liệu container<T>

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
            + empty(): => Map có rỗng? (true or false)

        - Element access:
            + operator[i]: => reference ele[i] (Không thể check i đúng/sai)
            + at(i): => reference ele[i] (Có thể check i đúng/sai)

        - Modifiers:
            + insert(it, {key, value})/(it, n, {key, value})/(it, <>)/(it, it1, it2): chèn phần tử
            + erase(it)/(first, last): xóa phần tử
            + swap(map): hoán đổi dữ liệu 2 map
            + clear(): xóa toàn bộ dữ liệu
            + emplace(it, {key, value}): chèn trực tiếp phần tử vào pos
            + emplace_hint(it, {key, value}): chèn gợi ý

        - Observers:
            + key_comb: => key_compare (comparison object). Dùng để sắp xếp key
            + value_comb: => value_compare (comparison object). Dùng để sắp xếp value

        - Operations: 
            + find(key): => iterator ele có key
            + count(key): => có tồn tại {key} (true/false)
            + lower_bound(key): => iterator: chặn dưới key
            + upper_bound(key): => iterator: chặn trên key
            + equal_range(key): => pair<map::iterator, map::iterator> (first: same lower_bound | second: upper_bound)

        - Allocator:
            + get_allocator(count): return bản sao được cấp phát

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/
 
*/

#include <iostream>
#include <map>
using namespace std;

int main() {

}