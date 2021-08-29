// bubble insertion sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n) | Avarage: O(n^2) | Worst: O(n^2) | Memory: O(1) | Stable
// Complete Algorithms
// Adaptive sort
// Internal sort
// Ưu điểm: 
// - Code đơn giản
// - Dễ cài đặt
// - Hiệu quả với dữ liệu nhỏ
// Nhược điểm: 
// - Độ phức tạp lớn
// - Không nhanh với dữ liệu lớn
template<class T> void BubbleSort(T *arr, lli n)
{
    bool haveSwap = false;
    for (lli i = 0; i < n - 2; i++)
    {
        for (lli j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1]) {
                // Đổi chỗ 2 phần tử nghịch thế cạnh nhau
                Swap(arr[j], arr[j - 1]);
                haveSwap = true;
            }
        }
        if (!haveSwap) {
            break;
        }
    }
}

// Bubble Sort dùng đệ quy
template<class T> void BubbleSort_UseRecursion(T *arr, lli n) {
    if (n == 1) {
        return;
    }
    for (lli i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1]) {
            Swap(arr[i], arr[i + 1]);
        }
    }
    BubbleSort_UseRecursion(arr, n - 1);
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    BubbleSort(arr, n);
    Output(arr, n);
    return 0;
}