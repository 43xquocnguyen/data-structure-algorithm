// gnome sort

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
template<class T> void GnomeSort(T *arr, lli n)
{
    // Vị trí bắt đầu so sánh, arr[1]
    lli pos = 1; 
    T temp;
    while (pos < n)
    {
        // So sánh 2 phần tử liền kề
        if (arr[pos] >= arr[pos - 1])
        {
            // Đã đúng vị trí
            pos++;
        }
        else
        {
            // Chưa đúng vị trí
            temp = arr[pos];
            arr[pos] = arr[pos - 1];
            arr[pos - 1] = temp;

            // Lùi về để kiểm tra lại
            pos--;
            if (pos == 0)
            {
                pos = 1;
            }
        }
    }
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    GnomeSort(arr, n);
    Output(arr, n);
    return 0;
}