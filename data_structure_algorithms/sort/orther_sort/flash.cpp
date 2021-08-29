// flash sort

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#include "../_library_sort_.h"

// Độ phức tạp: 
// Best: O(n) | Avarage: O(n + r) | Worst: O(n^2) | Memory: O(n) | Unstable
// Ưu điểm: 
// - Nhanh nếu mảng được phân phối đều
// Nhược điểm: 
// - Không ổn định
template<class T> void FlashSort(T *arr, lli n)
{
    double scaleFactor = 0.1;
    int *l, nmin, nmax, i, j, k, nmove;
    // m is usually chosen to be 0.1 * n
    const size_t m = int(scaleFactor * n);

    /***** CLASS FORMATION ****/
    l = (int *)calloc(m, sizeof(int));
    nmin = 0;
    nmax = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < arr[nmin]) {
            nmin = i;
        }
        if (arr[i] > arr[nmax]) {
            nmax = i;
        }
    }
    if (arr[nmax] == arr[nmin]) {
        // array is sorted (max = min)
        return; 
    }

    int c1 = double(m - 1.0) / double(arr[nmax] - arr[nmin]);
    int min = arr[nmin];

    for (i = 0; i < n; ++i)
    {
        k = int(c1 * (arr[i] - min));
        ++l[k];
    }

    for (k = 1; k < m; ++k)
    {
        l[k] += l[k - 1];
    }

    int hold = arr[nmax];
    arr[nmax] = arr[0];
    arr[0] = hold;

    /**** PERMUTATION *****/
    int flash;
    nmove = 0;
    j = 0;
    k = m - 1;

    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (arr[j] - min));
        }

        flash = arr[j];
        while (j != l[k])
        {
            k = int(c1 * (flash - min));
            l[k]--;
            hold = arr[l[k]];
            arr[l[k]] = flash;
            flash = hold;
            nmove++;
        }
    }

    /**** STRAIGHT INSERTION *****/
    for (i = 1; i < n; ++i)
    {
        hold = arr[i];
        j = i - 1;
        while (j >= 0 && hold < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = hold;
    }

    free(l);
}

int main() {
    lli *a;
    lli n{};
    Input(a, n);
    FlashSort(a, n);
    cout << "Array: ";
    Output(a, n);
    return 0;
}