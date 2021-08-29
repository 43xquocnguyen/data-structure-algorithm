// binary insertion sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"
    
// Độ phức tạp: 
// Best: O(n) | Avarage: O(nlogn) | Worst: O(nlogn) | Memory: O(1) | Stable
// Ưu điểm: 
// - Cải tiến từ Insertion sort
// - Tận dụng Binary Search để tìm vị chèn nhanh
// Nhược điểm: 
// - Không nhanh với thuật toán khác
template<class T> void BinaryInsertionSort(T *arr, lli n)
{
    lli left, right, mid;
    T key;

    for (lli i = 1; i < n; i++)
    {
        key = arr[i];
        left = 0;
        right = i - 1;

        // Tìm vị trí chèn x 
        while (left <= right) 
        {
            // Tìm vị trí thích hợp mid
            mid = (left + right) / 2;
            if (key < arr[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        for (lli j = i - 1; j >= left; j--) {
            // Dời các phần tử sẽ đứng sau key
            arr[j + 1] = arr[j]; 
        }
        // Chèn lại key vào dãy
        arr[left] = key;  
    }
}

// Inserion Sort đệ quy
template<class T> void BinaryInsertionSort_UseRecursion(T *arr, lli n) {
    if (n <= 1) {
        return;
    }
    BinaryInsertionSort_UseRecursion(arr, n - 1);
    int key = arr[n - 1];
    lli left = 0;
    lli right = n - 1;
    lli mid;
    while (left <= right) 
    {
        // Tìm vị trí thích hợp mid
        mid = (left + right) / 2;
        if (key < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    lli j;
    for (j = right - 1; j >= left; j--) {
        // Dời các phần tử sẽ đứng sau key
        arr[j + 1] = arr[j]; 
    }
    // Chèn lại key vào dãy
    arr[j + 1] = key;
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    BinaryInsertionSort(arr, n);
    Output(arr, n);
    return 0;
}