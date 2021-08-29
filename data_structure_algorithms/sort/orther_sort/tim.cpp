// tim sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

const short RUN = 32; // RUN

// Độ phức tạp: 
// Best: O(n) | Avarage: O(nlogn) | Worst: O(nlogn) | Memory: O(n) | Stable
// Ưu điểm: 
// - Rất nhanh (Hơn Quick Sort một vài TH)
// - Là defaul sort của: Arrays.sort() của Java, sorted() & sort() của Python,...
// - Là sự kết hợp của Merge Sort và Insertion Sort
// - Chạy thời gian tuyến tính nếu dữ liệu đã được sắp xếp 
// Nhược điểm: 
// - Code phức tạp
template<class T> void TimSort(T *arr, lli n) {
    // Sort individual subarrays of size RUN
    for (lli i = 0; i < n; i += RUN)
    {
        lli index = Min((i + RUN - 1), (n - 1));
        TimInsertionSort(arr, i, index);
    }

    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (lli size = RUN; size < n; size = 2 * size)
    {
         
        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (lli left = 0; left < n; left += 2 * size)
        {
             
            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            lli mid = left + size - 1;
            lli right = Min((left + 2 * size - 1), (n - 1));

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            if (mid < right) {
                TimMerge(arr, left, mid, right);
            }
        }
    }
}
template<class T> void TimMerge(T *arr, lli left, lli mid, lli right) {
    // Tạo ra 2 mảng
    lli len1 = mid - left + 1;
    lli len2 = right - mid;

    T *leftArr = new T[len1];
    T *rightArr = new T[len2];

    for (lli i = 0; i < len1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (lli i = 0; i < len2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
 
    lli i = 0;
    lli j = 0;
    lli k = left;
 
    // Merge 2 mảng lại
    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
 
    // Đổ các phần tử còn lại của 2 mảng
    while (i < len1)
    {
        arr[k] = leftArr[i];
        k++;
        i++;
    }
    while (j < len2)
    {
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}
template<class T> void TimInsertionSort(T *arr, lli left, lli right) {
    // Insertion Sort
    for (lli i = left + 1; i <= right; i++)
    {
        T temp = arr[i];
        lli j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    TimSort(arr, n);
    Output(arr, n);
    return 0;
}