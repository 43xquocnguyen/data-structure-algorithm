/* Unordered Set:

    * Thuộc tính:

        + Unordered set là một binary search tree không có thứ tự
        + Liên kết giữa key và value (Associative)
        + Không cần có thứ tự (Unordered)
        + Key đồng thời là value (Set)
        + Các key là duy nhất (Unique key)
        + Cấp phát động (Allocator-aware)

    * Template parameters <Key, Hash, Pred, Alloc>:

        + Key: Kiểu dữ liệu của key (Type of key)
        + Hash: Hash function (A unary function object type)
        + Pred: Hàm so sánh bằng (Binary Predicate)
        + Alloc: Type of allocation object

    * Function member:

        - Constructor:
            + unordered_set(): khởi tạo với 0 element
            + unordered_set({value,..},..): khởi tạo với các keyvalue cụ thể
            + unordered_set(first, last): khởi tạo với range[first, last]
            + unordered_set(Container<T>): khởi tạo mà copy toàn bộ dữ liệu container<T>

        - Iterators:
            + begin(): => iterator: ele[0]
            + end(): => iterator: ele[n]
            + cbegin(): => const_iterator: ele[0] (Không thể thay đổi giá trị *it)
            + cend(): => const_iterator: ele[n] (Không thể thay đổi giá trị *it)

        - Capacity:
            + size(): => size
            + maxsize(): => maximum size
            + empty(): => unordered_set có rỗng? (true or false)

        - Elements lookup: 
            + find(key): => iterator ele có key
            + count(key): => có tồn tại {key} (true/false)
            + equal_range(key): => pair<unordered_set::iterator, unordered_set::iterator> (first: same lower_bound | second: upper_bound)

        - Modifiers:
            + insert(it, {key, value})/(it, n, {key, value})/(it, <>)/(it, it1, it2): chèn phần tử
            + erase(it)/(first, last): xóa phần tử
            + swap(unordered_set): hoán đổi dữ liệu 2 unordered_set
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
            + operators(unordered_set): Toán tử quan hệ
            + swap(unordered_set): Đổi dữ liệu 2 unordered_set

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/
 
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

}