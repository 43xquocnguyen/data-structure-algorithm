// heap sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"
    
// Độ phức tạp: 
// Best: O(nlogn) | Avarage: O(nlogn) | Worst: O(nlogn) | Memory: O(1) | Unstable  
// Dynamic Programming, Greedy
// Internal sort
// Non-adaptive sort
// Ưu điểm: 
// - Nhanh với bất kì bộ dữ liệu nào
// - Có thể cài đặt không đệ quy
// - Không có worst case
// Nhược điểm: 
// - Chậm hơn Merge & Quick Sort
// - Không ổn định 
template<class T> void HeapSort(T *arr, lli n) {
    lli i, j;
    // Build Max Heap
    for (i = 1; i < n; i++) 
    {
        // Node con lớn node cha
        if (arr[i] > arr[(i - 1) / 2]) 
        {
            j = i;

            // Đưa node con lên trên
            // j: Node con | (j - 1) / 2]: Node cha
            while (arr[j] > arr[(j - 1) / 2]) 
            {
                Swap(arr[j], arr[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }

    for (i = n - 1; i > 0; i--)
    {
        // Cho phần tử lớn nhất xuống dưới cùng,
        // Sau đó, cập nhật lại cây
        Swap(arr[0], arr[i]);

        j = 0;
        lli childLeft;
        lli childRight;
        do
        {
            childLeft = (2 * j + 1);
            childRight = childLeft + 1;
            
            if (arr[childLeft] < arr[childRight] && childLeft < (i - 1)) {
                childLeft++;
            }
            
            if (arr[j] < arr[childLeft] && childLeft < i) {
                Swap(arr[j], arr[childLeft]);
            }

            j = childLeft;
        } while (childLeft < i);
    }
}

// Heap sort đệ quy
template<class T> void HeapSort_UseRecursion(T *arr, lli n)
{
    // Build heap bằng cây nhị phân 
    for (lli i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }

    // Heap Sort
    for (lli i = n - 1; i >= 0; i--)
    {
        // Cho phần tử lớn nhất xuống dưới cùng,
        // Sau đó, cập nhật lại cây
        Swap(arr[i], arr[0]);
        Heapify(arr, i, 0);
    }
}
template<class T> void Heapify(T *arr, lli n, lli i)
{
    lli childLeft = 2 * i + 1;
    lli childRight = 2 * i + 2;
    lli maxIdx;

    // Tìm ra node lớn nhất trong 3 node: node cha và 2 node con
    if (childLeft < n && arr[childLeft] > arr[i]) maxIdx = childLeft;
    else maxIdx = i;

    if (childRight < n && arr[childRight] > arr[maxIdx]) maxIdx = childRight;
 
    // Đổi chỗ và tiếp tục đệ quy
    if (maxIdx != i)
    {
        Swap(arr[i], arr[maxIdx]);
        Heapify(arr, n, maxIdx);
    }
}

int main() {
    lli *arr;
    lli n{};
    Input(arr, n);
    HeapSort(arr, n);
    Output(arr, n);
    return 0;
}