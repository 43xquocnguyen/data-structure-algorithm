// shell sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp:
// Best: O(nlogn) | Avarage: Tùy thuộc vào chọn gap sequences | Worst: O(n^3/2) | Memory: O(1) | Unstable
// Ưu điểm:
// - Hiệu quả với dữ liệu trung bình
// - Phiên bản cải tiến của Insertion Sort
// - Nhanh hơn 5 lần Bubble Sort, 1 Insertion Sort
// Nhược điểm:
// - Thuật toán phức tạp
// - Độ phức tạp còn phụ thuộc vào Gap sequences
// - Chậm hơn Merge, Heap, QuickSort,...
template<class T> void ShellSort(T *arr, lli n)
{
    // Shell sort phụ thuộc một trình tự nhất định
    // Mảng số gia tăng, dùng để hỗ trợ Shell Sort (Gap sequences)
    // Dãy ban đầu Shell: (n / 2^k) => O(n^2)
    // --- Các dãy khác có thể sử dụng ---:
    lli papernovStasevich[10] = {1, 3, 5, 9, 17, 33, 65, 129, 257, 513}; // 2^k + 1 => O(n^3/2)
    // ui knuth[10] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524};   // (3^k - 1) / 2 => O(n^3/2)
    // ui hibbard[10] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023}; // 2^k - 1 => O(n^3/2)
    // ui sedgewick[10] = {1, 8, 23, 77, 281, 1073, 4193, 16577, 65921, 262913}; // 4^k + 3 * 2^(k - 1) + 1 => O(n^4/3)
    // ui pratt[10] = {1, 2, 3, 4, 6, 9, 8, 12, 18, 27}; // Successive numbers of the form 2^p 3^q => O(n * (logn)^2)
    // --- và các dãy khác ---

    // Tìm khoảng cách lớn nhất của h
    int maxHeight;
    for (int i = 9; i >= 0; i--)
    {
        if (n / 2 > papernovStasevich[i])
        {
            maxHeight = i; 
            break;
        }
    }

    // Shell sort
    for (int idxGap = maxHeight; idxGap >= 0; idxGap--)
    {
        int gap = papernovStasevich[idxGap];

        for (int dc = 0; dc < gap; dc++)
        {
            for (int i = dc + gap; i < n; i += gap)
            {
                int temp = arr[i];
                int j = i;

                while ((j > dc) && (arr[j - gap] > temp))
                {
                    arr[j] = arr[j - gap];
                    j = j - gap;
                }

                if (j < i)
                {
                    arr[j] = temp;
                }
            }
        }
    }
}

int main()
{
    lli *arr;
    lli n{};
    Input(arr, n);
    ShellSort(arr, n);
    Output(arr, n);
    return 0;
}