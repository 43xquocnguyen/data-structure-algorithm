/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

// Copyright (C) Quoc Nguyen
//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/  

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int *a, int n, int *b, int m, int *c) {
    int i = 0, j = 0;
    for (; i < n; i++) {
        c[i] = a[i];
    }
    for (; j < m; j++)
    {
        c[i] = b[j];
        i++;
    }

    int nc = n + m;
    for (i = 0; i < nc - 1; i++)
    {
        for (j = i + 1; j < nc; j++)
        {
            if (c[i] > c[j]) {
                int t = c[j];
                c[j] = c[i];
                c[i] = t;
            }
        }
    }
}

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0) { 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n + m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        merge(a, n, b, m, c);
        int nc = n + m;

        for (int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}

