// jump search

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_search_.h"

// Độ phức tạp: 
// Time: O(sqrt(n)) | Memory: O(1)
// Ưu điểm: 
// - Nhanh hơn Linear Search
// - Chỉ cần duyệt mảng qua 1 lần
// Nhược điểm: 
// - Chậm hơn Binary Search
// - Điều kiện là mảng đã sắp xếp
template<class T> lli JumpSearch(lli *arr, lli n, lli target)
{
    lli step = sqrt(1.0 * n); // căn bậc 2 của n
    lli prev = 0;
    lli jump = step;

    // Tìm khoảng chứa target
    while (arr[Min(jump, n) - 1] < target)
    {
        prev = jump;
        jump += step;
        if (jump > n) {
            jump = n;
        }
        if (prev > n) {
            return -1;
        }
    }

    // Nếu có khoảng chứa target => Linear search khoảng đó
    while (arr[prev] < target)
    {
        prev++;
        if (prev == Min(jump, n))
        {
            return -1;
        }
    }

    if (arr[prev] == target) {
        return prev;
    }
    return -1;
}

int main() {
    lli *arr, target{};
    lli n{};
    Input(arr, n, target);
    target = JumpSearch(arr, n, target);
    Output(arr, n, target);
    return 0;
}