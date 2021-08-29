// comb sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(nlogn) | Avarage: O(n^2) | Worst: O(n^2) | Memory: O(1) | Unstable
// Ưu điểm: 
// - Dạng tổng quát và cải tiến của Bubble Sort
// Nhược điểm: 
// - Phải thay đổi khoảng cách là 1.3 (là 1 phân số)
template<class T> void CombSort(T *arr, lli n) 
{
    lli gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true) 
    { 
        // Tìm next gap
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }
  
        // Check có swap hay không?
        swapped = false; 
  
        // So sánh tất cả với gap
        for (lli i = 0; i < n - gap; i++)
        { 
            if (arr[i] > arr[i + gap]) 
            {
                swapped = true;
                Swap(arr[i], arr[i + gap]);
            } 
        } 
    } 
}

int main() {
    lli *arr;
    lli n;
    Input(arr, n);
    CombSort(arr, n);
    Output(arr, n);
    return 0;
}