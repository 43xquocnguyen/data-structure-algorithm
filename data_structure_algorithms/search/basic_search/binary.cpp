// binary search

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_search_.h"

// Độ phức tạp: 
// Time: O(logn) | Memory: O(1)
// Ưu điểm: 
// - Nhanh hơn Linear Search
// Nhược điểm: 
// - Điều kiện đầu vào mảng đã sắp xếp (ở dưới là sắp tăng)
template<class T> lli BinarySearch(T *arr, lli n, T target)
{
    lli left = 0;
    lli right = n - 1;
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

// Binary Search sử dụng đệ quy
template<class T> lli BinarySearch_UseRecurtion(T *arr, lli left, lli right, T target) 
{
    if (left <= right) {
        lli mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            return BinarySearch_UseRecurtion(arr, mid + 1, right, target);
        }
        else {
            return BinarySearch_UseRecurtion(arr, left, mid - 1, target);
        }
    }
    return -1;
}

int main() {
    lli *arr, target{};
    lli n{};
    Input(arr, n, target);
    target = BinarySearch_UseRecurtion(arr, 0, n - 1, target);
    Output(arr, n, target);
    return 0;
}