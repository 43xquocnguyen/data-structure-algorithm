// radix sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp:
// Best: O(n * k) | Avarage: O(n * k) | Worst: O(n * k) | Memory: O(n + k) | Stable
// Internal sort 
// Ưu điểm:
// - Thuật toán không dùng so sánh
// - Có thể chạy nhanh hơn các thuật toán sort có so sánh khác trong vài TH
// - Chạy tốt với small keys
// Nhược điểm:
// - Hạn chế với long keys
// - Hạn chế với số thực
// - Hạn chế với số âm
template<class T> void RadixSort(T *&arr, lli n)
{
    // Tìm max của mảng
    lli i;
    T max = arr[0];
    for (lli i = 1; i < n; i++)
    {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    // Radix sort
    T exp = 1;
    T *output = new T[n]{};
    lli count[10]{};
    lli radix;
    while (max / exp > 0)
    {
        for (i = 0; i < n; i++)
        {
            // Phần cơ số
            radix = (arr[i] / exp) % 10;
            count[radix]++;
        }

        // Sử dụng như couting sort
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        // Đổ về lại mảng output
        for (i = n - 1; i >= 0; i--)
        {
            radix = (arr[i] / exp) % 10;
            output[count[radix] - 1] = arr[i];
            count[radix]--;
        }

        // Đổ về mảng arr
        for (i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

int main()
{
    lli *arr;
    lli n{};
    Input(arr, n);
    RadixSort(arr, n);
    Output(arr, n);
    return 0;
}