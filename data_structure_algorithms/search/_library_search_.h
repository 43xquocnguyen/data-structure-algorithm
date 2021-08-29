// library search header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef _library__search_
#pragma once
#include <iostream>
using namespace std;
typedef long long int lli;

// ----------- Search ------------ //
//                          _      //
//                         | |     //
//  ___  ___  __ _ _ __ ___| |__   //
// / __|/ _ \/ _` | '__/ __| '_ \  //
// \__ \  __/ (_| | | | (__| | | | //
// |___/\___|\__,_|_|  \___|_| |_| //
//                                 //
// ----------- Search ------------ //
                         

// Input & Output
template<class T> void Input(T *&, lli &, T &);
template<class T> void Output(T *, lli, T);

// Min function
template<class T> T Min(T , T);

//----- Basic search -----//
// Linear Search
template<class T> lli LinearSearch_Simple(T *, lli, T);
template<class T> lli LinearSearch_Variant(T *, lli, T);
template<class T> lli LinearSearch_UseRecursion(T *, lli, lli, T);

// Binary Search
template<class T> lli BinarySearch(T *, lli, T);
template<class T> lli BinarySearch_UseRecurtion(T *, lli, lli, T);
//----- Basic search -----//

//----- Orther search -----//
// Jump Search
template<class T> lli JumpSearch(T *, lli, T);

// Interpolation Search
template<class T> lli InterpolationSearch(T *, lli, T);
template<class T> lli InterpolationSearch_UseRecurtion(T *, lli, lli, T);

// Exponential Search
template<class T> lli ExponentialSearch(T *, lli, T);

// Ternary Search
template<class T> lli TernarySearch(T *, lli, T);
template<class T> lli TernarySearch_UseRecursion(T *, lli, lli, T);
//----- Orther search -----//


// Input & Output
template<class T> void Input(T *&arr, lli &n, T &target) {
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
    cin >> target;
}
template<class T> void Output(T *arr, lli n, T target) {
    cout << "Array: ";
    for (lli i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cout << arr[i] << "  ";
    }
    if (target != -1) {
        cout << "\nPos found: " << target << endl;
    }
    else {
        cout << "\nNot found " << target << endl;
    }
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