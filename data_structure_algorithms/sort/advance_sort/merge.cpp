// merge sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(nlogn) | Avarage: O(nlogn) | Worst: O(nlogn) | Memory: O(n) | Stable 
// Divide & Conquer
// Non-adaptive sort
// External sort
// Ưu điểm: 
// - Nhanh
// - Có thể bất kì bộ dữ liệu nào
// Nhược điểm: 
// - Phải dùng đệ quy (Có thể khử đệ quy được !)
// - Cần thêm bộ nhớ

// Merge khử đệ quy (Tốn kém hơn)
template<class T> void MergeSort(T *arr, lli n) {
    T *temp = new T[n];
    lli rght, wid, rend;
    lli i, j, m, t;
    for (lli k = 1; k < n; k *= 2)
    {
        for (lli left = 0; left + k < n; left += k * 2)
        {
            rght = left + k;        
            rend = rght + k;
            if (rend > n) {
                rend = n; 
            }
            m = left;
            i = left;
            j = rght;
            while (i < rght && j < rend) { 
                if (arr[i] <= arr[j]) {         
                    temp[m] = arr[i];
                    i++;
                } else {
                    temp[m] = arr[j];
                    j++;
                }
                m++;
            }
            while (i < rght) {
                temp[m] = arr[i];
                i++;
                m++;
            }
            while (j < rend) {
                temp[m] = arr[j];
                j++;
                m++;
            }
            for (m = left; m < rend; m++)
            {
                arr[m] = temp[m];
            }
        }
    }
}

// Merge Sort đệ quy
template<class T> void MergeSort_UseRecursion(T *arr, lli left, lli right)
{
    lli mid;
    if (left < right)
    {
        // Chia ra theo mid
        mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        // Merge lại mảng đã chia
        Merge(arr, left, mid, right);
    }
}
template<class T> void Merge(T *arr, lli left, lli mid, lli right)
{
    T *temp = new T[right - left + 1]; // mảng tạm
    lli l = left;
    lli r = mid + 1;
    lli k = 0;
     
    while (l <= mid && r <= right)
    {
        if (arr[l] < arr[r]) {
            temp[k++] = arr[l++];
        }
        else {
            temp[k++] = arr[r++];
        }
    }
    
    while (l <= mid) {
        temp[k++] = arr[l++];
    }
     
    while (r <= right) {
        temp[k++] = arr[r++];
    }
    
    for (int i = 0; i < k; i++) {
        arr[i + left] = temp[i];
    }
     
}

int main() {
    lli *a;
    lli n{};
    Input(a, n);
    MergeSort_UseRecursion(a, 0, n - 1);
    Output(a, n);
    return 0;
}