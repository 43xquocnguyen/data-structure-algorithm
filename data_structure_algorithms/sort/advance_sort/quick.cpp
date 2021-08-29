// quick sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(nlogn) | Avarage: O(nlogn) | Worst: O(n^2) | Memory: O(nlogn) | Stable / Not stable
// Divide & Conquer
// Adaptive sort
// Internal sort
// Ưu điểm: 
// - Nhanh nhất trong các thuật toán sort
// - Không cần thêm bộ nhớ
// Nhược điểm: 
// - Phải dùng đệ quy (Khử được)
// - Worst case n^2
// - Phụ thuộc vào pivot

// Quick Sort khử đệ quy
template<class T> void QuickSort(T *arr, lli n) {
    
    // 2 mảng tạm
    T *begin = new T[n];
    T *end = new T[n];

    // left, right
    lli left, right;
    lli i = 0;

    begin[0] = 0;
    end[0] = n;

    while (i >= 0) {
        left = begin[i];
        right = end[i];

        if (right - left > 1) {
            lli mid = left + ((right - left) >> 1);
            lli piv = arr[mid];
            arr[mid] = arr[left];

            if (i == n - 1) {
                return;
            }
                
            right--;
            while (left < right) {
                while (arr[right] >= piv && left < right)
                    right--;
                if (left < right)
                    arr[left++] = arr[right];
                while (arr[left] <= piv && left < right)
                    left++;
                if (left < right)
                    arr[right--] = arr[left];
            }

            arr[left] = piv;
            mid = left + 1;

            while (left > begin[i] && arr[left - 1] == piv) {
                left--;
            }
                
            while (mid < end[i] && arr[mid] == piv) {
                mid++;
            }
                
            if (left - begin[i] > end[i] - mid) {
                begin[i + 1] = mid;
                end[i + 1] = end[i];
                end[i++] = left;
            } 
            else {
                begin[i + 1] = begin[i];
                end[i + 1] = left;
                begin[i++] = mid;
            }
        } 
        else {
            i--;
        }
    }
}

// Quick sort đệ quy
template<class T> void QuickSort_UseRecursion(T *arr, lli left, lli right)
{
    if (left < right) {
        // Lấy pivot
        lli pivot = PivotQuickSort(arr, left, right);

        // Gọi lại đệ quy
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    } 
}
template<class T> lli PivotQuickSort(T *arr, lli left, lli right) {
    lli pivot = arr[right];
    lli i = (left - 1); 
 
    for (int j = left; j <= right - 1; j++)
    {
        // Nếu phần tử hiện tại < pivot
        if (arr[j] < pivot)
        {
            i++; 
            Swap(arr[i], arr[j]);
        }
    }
    Swap(arr[i + 1], arr[right]);
    return (i + 1);
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    QuickSort(arr, n);
    Output(arr, n);
    return 0;
}