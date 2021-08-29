// interchange sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n) | Avarage: O(n^2) | Worst: O(n^2) | Memory: O(1) | Unstable 
// Complete Algorithms
// Ưu điểm: 
// - Code đơn giản
// - Dễ cài đặt
// - Hiệu quả với dữ liệu nhỏ
// Nhược điểm: 
// - Độ phức tạp lớn
// - Không nhanh với dữ liệu lớn
template<class T> void InterchangeSort(T *arr, lli n) {
    for (lli i = 0; i < n - 1; i++)
    {
        for (lli j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j]) {
                // Đổi chỗ 2 phần tử nếu nghịch thế
                Swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    InterchangeSort(arr, n);
    Output(arr, n);
    return 0;
}