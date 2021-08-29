/* Unordered Map:

    * Thuộc tính:

        + Unordered map là một hash table
        + Liên kết giữa key và value (Associative)
        + Using hash table (Unordered)
        + Mỗi key ánh xạ 1 value (Map)
        + Các key là duy nhất (Unique key)
        + Cấp phát động (Allocator-aware)

    * Template parameters <Key, T, Hash, Pred, Alloc>:

        + Key: Kiểu dữ liệu của key (Type of key)
        + T: Kiểu dữ liệu cần chứa (Type of value)
        + Hash: Hash function (A unary function object type)
        + Pred: Hàm so sánh bằng (Binary Predicate)
        + Alloc: Type of allocation object

    * Function member:

        - Constructor:
            + unordered_map(): khởi tạo với 0 element
            + unordered_map({key, value},...)
            + unordered_map(first, last): khởi tạo với range[first, last]
            + unordered_map(unordered_map): khởi tạo mà copy toàn bộ dữ liệu 

        - Iterators:
            + begin(): => iterator: ele[0]
            + end(): => iterator: ele[n]
            + cbegin(): => const_iterator: ele[0] (Không thể thay đổi giá trị *it)
            + cend(): => const_iterator: ele[n] (Không thể thay đổi giá trị *it)

        - Capacity:
            + size(): => size
            + maxsize(): => maximum size
            + empty(): => unordered_map có rỗng? (true or false)

        - Element access:
            + operator[i]: => reference ele[i] (Không thể check i đúng/sai)
            + at(i): => reference ele[i] (Có thể check i đúng/sai)

        - Elements lookup: 
            + find(key): => iterator ele có key
            + count(key): => có tồn tại {key} (true/false)
            + equal_range(key): => pair<unordered_map::iterator, unordered_map::iterator> (first: same lower_bound | second: upper_bound)

        - Modifiers:
            + insert(it, {key, value})/(it, n, {key, value})/(it, <>)/(it, it1, it2): chèn phần tử
            + erase(it)/(first, last): xóa phần tử
            + swap(unordered_map): hoán đổi dữ liệu 2 unordered_map
            + clear(): xóa toàn bộ dữ liệu
            + emplace(it, {key, value}): chèn trực tiếp phần tử vào pos
            + emplace_hint(it, {key, value}): chèn gợi ý

        - Buckets:
            + bucket_count(): => số lượng bucket
            + max_bucket_count(): => maximum bucket
            + bucket_size(i): => số lượng phần tử trong 1 bucket
            + bucket(key): => index bucket có key
        
        - Hash policy:
            + load_factor(): => trả về trung bình 1 bucket chứa (size / bucket_count)
            + max_load_factor(): => trả về max trung bình 1 bucket chứa (size / bucket_count)
            + rehash(n): Set số lượng bucket
            + reserve

        - Observers:
            + hash_function(): => hash function object
            + key_eq(key, key1): => 2 key qua hash_function có cùng value? (true/false)

        - Non-member function overloads:
            + operators(unordered_map): Toán tử quan hệ
            + swap(unordered_map): Đổi dữ liệu 2 unordered_map

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/
 
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    
}