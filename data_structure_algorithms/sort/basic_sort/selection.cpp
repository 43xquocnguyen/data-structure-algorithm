// selection sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n^2) | Avarage: O(n^2) | Worst: O(n^2) | Memory: O(1) | Unstable
// Greedy
// Non-adaptive sort
// Internal sort
// Ưu điểm: 
// - Code đơn giản
// - Dễ cài đặt
// - Hiệu quả với dữ liệu nhỏ
// Nhược điểm: 
// - Độ phức tạp lớn
// - Không nhanh với dữ liệu lớn
template<class T> void SelectionSort(T *arr, lli n) {
    lli minIdx{};
    for (lli i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (lli j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx]) {
                // Min trong dãy 
                minIdx = j;
            }
        }
        Swap(arr[minIdx], arr[i]);
    }
}

// Selection Sort đệ quy
template<class T> void SelectionSort_UseRecursion(T *arr, lli n, lli i, lli j, bool check)
{
    if (i < n - 1)
    {
        if (check)
        {
            j = i + 1;
        }
        if (j < n)
        {
            if (arr[i] > arr[j])
            {
                Swap(arr[i], arr[j]);
            }
            SelectionSort_UseRecursion(arr, n, i, j + 1, false);
        }
        SelectionSort_UseRecursion(arr, n, i + 1, 0, true);
    }
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    SelectionSort_UseRecursion(arr, n, 0, 0, true);
    Output(arr, n);
    return 0;
}