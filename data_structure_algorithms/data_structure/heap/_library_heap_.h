// library heap header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef __library_heap__
#pragma once
#include <iostream>
#include <string>
using namespace std;

// ----------- Heap ----------- //
//                               //
//   __ _ _   _  ___ _   _  ___  //
//  / _` | | | |/ _ \ | | |/ _ \ //
// | (_| | |_| |  __/ |_| |  __/ //
//  \__, |\__,_|\___|\__,_|\___| //
//     | |                       //
//     |_|                       //
//                               //
// ----------- Heap ----------- //

#define MAX 1000
#define NULLINDEX -1
#define NULLDATA INT_MAX

typedef int Index;
typedef long long int Data;

template<class T> T Min(T, T);
template<class T> T Max(T, T);
template<class T> void Swap(T &, T &);

// ------------ Node ------------ //
struct Node;
Node *CreateNode(Data);

// ------------ Heap ------------ //
// Structure Heap
struct Heap;
void Initialize(Heap &);
void Initialize(Heap &, int);

// Function Heap
// Check Heap
bool HeapIsEmpty(Heap);
bool HeapIsFull(Heap);
int HeightHeap(Heap);
int SizeHeap(Heap);

// Insert, extract, delete, search
bool Insert(Heap &, Data);
bool Extract(Heap &);
bool Delete(Heap &, Index);
Index SearchHeap(Heap, Data);

// Output Heap
void OutputHeap(Heap);

template<class T> T Min(T ele1, T ele2) {
    if (ele1 <= ele2) {
        return ele1;
    }
    return ele2;
}
template<class T> T Max(T ele1, T ele2) {
    if (ele1 >= ele2) {
        return ele1;
    }
    return ele2;
}
template<class T> void Swap(T &ele1, T &ele2) {
    T temp = ele1;
    ele1 = ele2;
    ele2 = temp;
}

#endif