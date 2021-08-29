// all sort algorithms header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef _library__sort_
#pragma once
#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

// ------------ Sort ------------ //
//                      _         //
//                     | |        //
//       ___  ___  _ __| |_       //
//      / __|/ _ \| '__| __|      //
//      \__ \ (_) | |  | |_       //
//      |___/\___/|_|   \__|      //
//                                //
// ------------ Sort ------------ //

// Input & Output
template<class T> void Input(T *&, lli &);
template<class T> void Output(T *, lli);

// Swap function
template<class T> void Swap(T &, T &);

// Min function
template<class T> T Min(T, T);

//----- Basic sort -----//
// Interchange Sort
template<class T> void InterchangeSort(T *, lli);

// Bubble Sort 
template<class T> void BubbleSort(T *, lli);
template<class T> void BubbleSort_UseRecursion(T *, lli);

// Shaker Sort
template<class T> void ShakerSort(T *, lli);

// Insertion Sort
template<class T> void InsertionSort(T *, lli);
template<class T> void InsertionSort_UseRecursion(T *, lli);

// Selection Sort
template<class T> void Selection(T *, lli);
template<class T> void SelectionSort_UseRecursion(T *, lli, lli, lli, bool);

// Binary Insertion Sort
template<class T> void BinaryInsertionSort(T *, lli);
template<class T> void BinaryInsertionSort_UseRecursion(T *, lli);
//----- Basic sort -----//

//----- Advance sort -----//

// Heap Sort
template<class T> void HeapSort(T *, lli);
template<class T> void HeapSort_UseRecursion(T *, lli);
template<class T> void Heapify(T *, lli, lli); // for HeapSort Recursion

// Merge Sort
template<class T> void MergeSort(T *, lli); // Merge Sort khử đệ quy
template<class T> void MergeSort_UseRecursion(T *, lli, lli);
template<class T> void Merge(T *, lli, lli, lli); // for Merg Sort Recursion

// Quick Sort
template<class T> void QuickSort(T *, lli); // Quick Sort khử đệ quy
template<class T> void QuickSort_UseRecursion(T *, lli, lli);
template<class T> lli PivotQuickSort(T *, lli, lli);

// Shell Sort
template<class T> void ShellSort(T *, lli);

// Radix Sort
template<class T> void RadixSort(T *&, lli);
//----- Advance sort -----//

//----- Orther sort -----//
// Bucket Sort
template<class T> void BucketSort(T *, lli);

// Counting Sort
template<class T> void CountingSort(T *&, lli);

// Flash Sort
template<class T> void FlashSort(T *, lli);

// Comb Sort
template<class T> void CombSort(T *, lli);

// Gnome Sort
template<class T> void GnomeSort(T *, lli);

// Pigeonhole Sort
template<class T> void PigeonholeSort(T *, lli);

// Tim Sort
template<class T> void TimSort(T *, lli);
template<class T> void TimMerge(T *, lli, lli, lli);
template<class T> void TimInsertionSort(T *, lli, lli);
//----- Orther sort -----//

// Input & Output
template<class T> void Input(T *&arr, lli &n) {
    bool check;
    do
    {
        check = false;
        cin >> n;
        if (cin.fail() || n <= 0) {
            check = true;
        }
    } while (check);
    arr = new T[n]{};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
template<class T> void Output(T *arr, lli n) {
    cout << "Array: ";
    for (lli i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cout << arr[i] << "  ";
    }
}

// Swap function
template<class T> void Swap(T &ele1, T &ele2) {
    ele1 = ele1 + ele2 - (ele2 = ele1);
    // xor: ele1 ^= ele2 ^= ele1 ^= ele2; // can using for integer
}

// Min function
template<class T> T Min(T ele1, T ele2) {
    if (ele1 > ele2) {
        return ele2;
    }
    else {
        return ele1;
    }
}
#endif