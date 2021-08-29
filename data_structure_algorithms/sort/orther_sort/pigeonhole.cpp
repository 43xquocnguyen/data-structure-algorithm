// pigeonhole sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n + k) | Avarage: O(n + k) | Worst: O(n + k) | Memory: O(n + k) | Stable / Not stable
// Ưu điểm: 
// - Không cần so sánh
// - Chạy thời gian tuyến tính
// Nhược điểm: 
// - Chỉ sort được số nguyên dương
// - Không biết số chuồng cần thiết
template<class T> void PigeonholeSort(T *arr, lli n)
{
    // Tìm max và min của mảng
    T min = arr[0];
    T max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Số các giá trị có trong dãy
    lli range = max - min + 1;
 
    // Số chuồng
    vector<T> holes[range];
 
    // Đưa các phần tử vào chuồng tương ứng
    lli index;
    for (int i = 0; i < n; i++) {
        index = arr[i] - min;
        holes[index].push_back(arr[i]);
    }
 
    // Duyệt tất cả các chuồng và đưa vào mảng
    index = 0;
    lli size;
    for (lli i = 0; i < range; i++)
    {
        size = holes[i].size();
        if (size > 0) {
            for (lli j = 0; j < size; j++)
            {
                arr[index] = holes[i][j];
                index++;
            }
        }
    }
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    PigeonholeSort(arr, n);
    Output(arr, n);
    return 0;
}