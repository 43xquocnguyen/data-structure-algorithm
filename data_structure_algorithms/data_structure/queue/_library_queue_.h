// library queue header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef __library_queue__
#pragma once
#include <iostream>
#include <string>
using namespace std;

// ----------- Queue ----------- //
//                               //
//   __ _ _   _  ___ _   _  ___  //
//  / _` | | | |/ _ \ | | |/ _ \ //
// | (_| | |_| |  __/ |_| |  __/ //
//  \__, |\__,_|\___|\__,_|\___| //
//     | |                       //
//     |_|                       //
//                               //
// ----------- Queue ----------- //

#define MAX 1000
#define NULLINDEX -1
#define NULLDATA INT_MAX

typedef int Index;
typedef int PriorityType;
typedef long long int Data;

template<class T> void Swap(T &, T &);

// ------------ Node ------------ //
struct Node;
Node *CreateNode(Data);
Node *CreateNode(Data, PriorityType); // for priority queue

// ------------ Queue ------------ //
// Structure Queue
struct Queue;
void Initialize(Queue &);
void Initialize(Queue &, int);

// Function Queue
// Check Queue
bool QueueIsEmpty(Queue);
bool QueueIsFull(Queue);
int SizeQueue(Queue);

// Push & pop & peek
Data FontQueue(Queue);
bool EnQueue(Queue &, Data);
bool EnQueue(Queue &, Data, PriorityType); // for Priority Queue
bool DeQueue(Queue &);

// Output Queue
void OutputQueue(Queue);

template<class T> void Swap(T &ele1, T &ele2) {
    T temp = ele1;
    ele1 = ele2;
    ele2 = temp;
}

#endif