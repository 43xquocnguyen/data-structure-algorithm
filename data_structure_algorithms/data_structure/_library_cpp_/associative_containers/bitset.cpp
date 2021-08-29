/* Bitset:

    * Thuộc tính:

        - Lưu trữ các bit có giá trị (1/0, true/false,...)
        - Không gian lưu trữ ít hơn mảng và vector
        - Thao tác nhanh hơn mảng và vector
        - Size cố định (Fixed-size)

    * Template parameters <N>:

        + T: Kích thước của bitset, số bit (Size of bitset)

    * Function member:

        - Constructor:
            + biset(): khởi tạo với 0
            + biset(value): khởi tạo với bit của value
            + biset(c_string): khởi tạo với chuỗi chứa số (0/1)

        - Bitset operator:
            + member functions: &=, |=, ^=, <<=, >>=, ~, <<, >>, ==, !=
            + non-member functions: &, |, ^
            + iostream inserters/extractors: <<, >>

        - Bit access:
            + operator[i]: => reference bit[i] (Không thể check đúng/sai i)
            + count(): => số bit 1
            + size(): => số bit
            + test(i): => là bit 1 hay không?
            + any(): => có 1 bit 1 hay không?
            + none(): => có toàn bộ bit 0 hay không?
            + all(): => có toàn bộ bit 1 hay không?

        - Bit operations:
            + set(pos, index): set bit là 1 (nếu không có pos thì full 1)
            + reset(pos, index): reset bit là 0 (nếu không có pos thì full 0)
            + flip(pos, index): đảo bit (nếu không có pos thì đảo full)

        - Bitset operations
            + to_string(): convert sang string
            + to_ulong(): convert sang unsigned long int
            + to_ullong(): convert sang unsigned long long

              _       ____    __   _            _ __  
             (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
              /(                 .-/     .-/          
             (_)                (_/     (_/
    
*/

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<10> b1(1010101010);
    bitset<15> b1("10101");
    bitset<20> b1 = 13;
}