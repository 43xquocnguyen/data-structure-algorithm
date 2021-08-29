// insertion sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n) | Avarage: O(n^2) | Worst: O(n^2) | Memory: O(1) | Stable 
// Dynamic Programming
// Online sort
// Adaptive sort
// Internal sort
// Ưu điểm: 
// - Code đơn giản
// - Dễ cài đặt
// - Hiệu quả với dữ liệu nhỏ
// Nhược điểm: 
// - Độ phức tạp lớn
// - Không nhanh với dữ liệu lớn
template<class T> void InsertionSort(T *arr, lli n) {
    for (lli i = 1; i < n; i++)
    {
        T last = arr[i];
        lli j = i - 1;

        // Tìm vị trị cần chèn & dời các phần sang bên phải
        while (j >= 0 && arr[j] > last)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Chèn vào
        arr[j + 1] = last;
    }
}

// Inserion Sort đệ quy
template<class T> void InsertionSort_UseRecursion(T *arr, lli n) {
    if (n <= 1) {
        return;
    }
    InsertionSort_UseRecursion(arr, n - 1);
    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key){
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    InsertionSort_UseRecursion(arr, n);
    Output(arr, n);
    return 0;
}