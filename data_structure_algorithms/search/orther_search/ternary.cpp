// ternary search

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_search_.h"

// Độ phức tạp: 
// Time: O(log(3)n) | Memory: O(1)
// Ưu điểm: 
// - Phiên bản giống BS (Chia mảng thành 3 phần)
// Nhược điểm: 
// - Cần mảng đã sắp xếp
template<class T> lli TernarySearch(T *arr, lli n, T target)
{
    lli left = 0;
    lli right = n - 1;
    lli mid1, mid2;

    while (left <= right)
    {
        mid1 = (right - left) / 3 + left;
        mid2 = 2 * (right - left) / 3 + left;

        if (arr[mid1] == target) {
            return mid1;
        }
        else if (arr[mid2] == target) {
            return mid2;
        }
        else if (arr[mid1] > target) {
            right = mid1 - 1;
        }
        else if (arr[mid2] > target) {
            right = mid2 - 1;
        }
        else {
            right = mid2 + 1;
        }
    }

    return -1;
}

// Ternary Search đệ quy
template<class T> lli TernarySearch_UseRecursion(T *arr, lli left, lli right, T target) 
{
    
   if (right >= left)
   {
        lli mid1 = left + (right - left)/3;
        lli mid2 = mid1 + (right - left)/3;
  
        if (arr[mid1] == target)  {
            return mid1;
        }
        if (arr[mid2] == target)  {
            return mid2;
        }
        if (arr[mid1] > target) {
            return TernarySearch_UseRecursion(arr, left, mid1 - 1, target);
        }
        if (arr[mid2] < target) {
            return TernarySearch_UseRecursion(arr, mid2 + 1, right, target);
        }
        return TernarySearch_UseRecursion(arr, mid1 + 1, mid2 - 1, target);
   }
   return -1;
}

int main() {
    lli *arr;
    lli n{}, target{};
    Input(arr, n, target);
    target = TernarySearch_UseRecursion(arr, 0,n-1, target);
    Output(arr, n, target);
    return 0;
}