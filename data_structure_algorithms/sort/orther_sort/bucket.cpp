// bucket sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n + k) | Avarage: O(n + k) | Worst: O(n + k) | Memory: O(n + k) | Stable
// Ưu điểm: 
// - Phiên bản tổng quát của Counting Sort
// - Tối ưu khi sort mảng xác định (VD: Từ 0->1)
// Nhược điểm: 
// - Hạn chế với mảng chưa biết
// - Hạn chế với số âm
// - Cần thêm bộ nhớ
template<class T> void BucketSort(T *arr, lli n)
{
    // Tìm max, min để xác định số xô
    T min = arr[0];
	T max = arr[0];
	for (lli i = 1; i < n; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
        }
		if (arr[i] < min) {
			min = arr[i];
        }
	}

    // Số xô
    lli numBucket = max - min + 1;
    vector<vector<T>> bucket(numBucket);

    // Đổ các phần tử vào các xô
    lli index{};
    for (lli i = 0; i < n; i++) { 
        // Index tính theo công thức
        index = arr[i] - min; 
        bucket[index].push_back(arr[i]); 
    } 
  
    // Sort từng cái xô
    for (lli i = 0; i < n; i++) {
        // Interchange sort
        lli size = bucket[i].size();
        for (lli j = 0; j < size - 1; j++)
        {
            for (lli k = j + 1; k < size; k++)
            {
                if (bucket[i][j] > bucket[i][k]) {
                    Swap(bucket[i][j], bucket[i][k]);
                }
            }
        }
    }
  
    // Trộn các xô lại với nhau
    index = 0;
    lli bucketSize{};
    for (lli i = 0; i < n; i++) {
        bucketSize = bucket[i].size();
        if (bucketSize > 0) {
            for (lli j = 0; j < bucketSize; j++) {
                arr[index] = bucket[i][j];
                index++;
            }
        }
    }
}

int main() {
    float *arr; // dùng bucketsort float hoặc double sẽ hiệu quả
    lli n{};
    Input(arr, n);
    BucketSort(arr, n);
    Output(arr, n);
    return 0;
}