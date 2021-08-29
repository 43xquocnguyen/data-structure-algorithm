// counting sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n + k) | Avarage: O(n + k) | Worst: O(n + k) | Memory: O(n + k) | Stable
// Ưu điểm: 
// - Nhanh
// - Tối ưu khi sort mảng số nguyên dương
// Nhược điểm: 
// - Không dùng được với chuỗi
// - Cần tốn thêm bộ nhớ
// - Hạn chế với dữ liệu lớn
template<class T> void CountingSort(T *&arr, lli n)
{
    // Check mảng dương
    for (lli i = 0; i < n; i++)
    {
        if (arr[i] < 0) {
            // Có phần tử âm
            return;
        }
    }

    T *output = new T[n]; 
    T max = arr[0];
    T min = arr[0];
    lli i;

    // Tìm max, min
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max) {
            max = arr[i]; 
        }
        else if (arr[i] < min) {
            min = arr[i]; 
        }
    }

    // Mảng đếm
    lli numElements = max - min + 1;
    T *count = new T[numElements]{0};

    // Đếm các phần tử
    for (i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    // count[i] += count[i - 1]
    for (i = 1; i < numElements; i++) {
        count[i] += count[i - 1];
    }

    // Đổ lại mảng output
    for (i = 0; i < n; i++)
    {
        lli index = count[(arr[i] - min)];
        output[index - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Trả lại mảng gốc
    delete arr;
    arr = output;
    output = nullptr;
    delete output;
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    CountingSort(arr, n);
    Output(arr, n);
    return 0;
}