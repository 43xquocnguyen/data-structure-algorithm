// shaker sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n) | Avarage: O(n^2) | Worst: O(n^2) | Memory: O(1) | Stable
// Ưu điểm: 
// - Phiên bản cải tiến của Bubble Sort
// Nhược điểm: 
// - Độ phức tạp lớn
// - Không nhanh với dữ liệu lớn
template<class T> void ShakerSort(T *arr, lli n) {
    lli left = 0;
    lli right = n - 1;
    lli k = 0;
    while (left < right)
    {
        // Lượt đi
        for (lli i = 0; i < right; i++)
        {
            if (arr[i] > arr[i + 1]) {
                Swap(arr[i], arr[i + 1]);
                k = i;
            }
        }

        // Lượt về
        right = k;
        for (lli j = right; j > left; j--)
        {
            if (arr[j] < arr[j - 1]) {
                Swap(arr[j], arr[j - 1]);
                k = j;
            }
        }
        left = k;
    }
    
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    ShakerSort(arr, n);
    Output(arr, n);
    return 0;
}