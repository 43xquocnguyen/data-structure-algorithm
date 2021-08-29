// linear search 

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_search_.h"

// Độ phức tạp: 
// Time: O(n) | Memory: O(1)
// Ưu điểm: 
// - Code đơn giản
// - Dễ cài đặt
// - Hiệu quả với dữ liệu nhỏ
// Nhược điểm: 
// - Độ phức tạp lớn
// - Không nhanh với dữ liệu lớn
template<class T> lli LinearSearch_Simple(T *arr, lli n, T target)
{
    for (lli i = 0; i < n; i++)
    {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Linear search cải tiến O(n) -> O(n / 2)
template<class T> lli LinearSearch_Variant(T *arr, lli n, T target) {
    lli left = 0;
    lli right = n - 1;

    // Cải tiến bằng việc xét cả 2 đầu của danh sách
    for (; left < right;)
    {
        if (arr[left] == target) {
            return left;
        }

        if (arr[right] == target) {
            return right;
        }

        left++;
        right--;
    }
}

// Linear search code đệ quy
template<class T> lli LinearSearch_UseRecursion(T *arr, lli i, lli n, T target) {
    if (i >= n) {
        return -1;
    }
    else if (arr[i] == target) {
        return i;
    }
    return LinearSearch_UseRecursion(arr, i + 1, n, target);
}

int main() {
    lli *arr, target{};
    lli n{};
    Input(arr, n, target);
    target = LinearSearch_UseRecursion(arr, 0, n, target);
    Output(arr, n, target);
    return 0;
}