// exponential search

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_search_.h"

// Độ phức tạp: 
// Time: O(logn) | Memory: O(1)
// Ưu điểm: 
// - Phiên bản kết hợp giữa BS và tìm khoảng chứa phần tử (k * 2)
// - Hữu dụng với loại tìm kiếm số lượng phần tử vô hạn
// Nhược điểm: 
// - Cần mảng đã sắp xếp
template<class T> lli ExponentialSearch(T *arr, lli n, T target)
{
    // Kiểm tra phần tử đầu tiên
    if (arr[0] == target) {
        return 0;
    }

    // Tìm khoảng chứ target theo cấp số nhân (Exponential)
    lli index = 1;
    while (index < n && arr[index] < target)
    {
        index *= 2;
    }

    // Bước tìm kiếm nhị phân trong đoạn chứa target
    lli left = index / 2;
    lli right = Min(index, n - 1);
    lli mid;
    do 
    {
        mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    } while (left <= right);

    return -1;
}

int main() {
    lli *arr;
    lli n{}, target{};
    Input(arr, n, target);
    target = ExponentialSearch(arr, n, target);
    Output(arr, n, target);
    return 0;
}