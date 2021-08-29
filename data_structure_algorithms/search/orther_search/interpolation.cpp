// interpolation search

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_search_.h"

// Độ phức tạp: 
// Time: O(log(logn)) | Memory: O(1)
// Ưu điểm: 
// - Phiên bản cải tiến của BS
// Nhược điểm: 
// - Điều kiện là mảng đã sắp xếp
template<class T> lli InterpolationSearch(T *arr, lli n, T target)
{
    lli left = 0;
    lli right = n - 1;
    lli pos;

    while (left <= right && target >= arr[left] && target <= arr[right])
    {
        // Giống như BS, nhưng dùng công thức để tìm vị trí chính xác hơn
        pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));

        if (arr[pos] == target) {
            return pos;
        }
        else if (arr[pos] > target) {
            right = pos - 1;
        }
        else {
            left = pos + 1;
        }
    }

    if (target == arr[left]) {
        return left;
    }

    return -1;
}

// Interpolation Search đệ quy
template<class T> lli InterpolationSearch_UseRecurtion(T *arr, lli left, lli right, T target) 
{
    if (left <= right) {
        lli pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));
        if (arr[pos] == target) {
            return pos;
        }
        else if (arr[pos] < target) {
            return InterpolationSearch_UseRecurtion(arr, pos + 1, right, target);
        }
        else {
            return InterpolationSearch_UseRecurtion(arr, left, pos - 1, target);
        }
    }
    return -1;
}

int main() {
    lli *arr, target{};
    lli n{};
    Input(arr, n, target);
    target = InterpolationSearch_UseRecurtion(arr, 0, n - 1, target);
    Output(arr, n, target);
    return 0;
}