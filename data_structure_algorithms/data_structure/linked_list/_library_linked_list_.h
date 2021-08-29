// library linked list header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef __library_linkedlist__
#pragma once
#include <iostream>
#include <string>
using namespace std;

// ------------- Linked List -------------  //
//                                          //
// | (_)     | |          | | | (_)   | |   //
// | |_ _ __ | | _____  __| | | |_ ___| |_  //
// | | | '_ \| |/ / _ \/ _` | | | / __| __| //
// | | | | | |   <  __/ (_| | | | \__ \ |_  //
// |_|_|_| |_|_|\_\___|\__,_| |_|_|___/\__| //
//                                          //
// ------------- Linked List -------------  //

#define NULLINDEX -1

typedef long long int Data;

// ------------ Node ------------ //
struct Node;
Node *CreateNode(Data);
void SwapData(Node *, Node *);
void SwapAddress(Node *, Node *);

// ------------ Linked List ------------ //
// -- Linked List -- //
struct LinkedList;
void Initialize(LinkedList &);
LinkedList Initialize(Node *, Node *);

// -- Function Linked List -- //
// Add
void AddHead(LinkedList &, Node *);
void AddTail(LinkedList &, Node *);
bool AddAfterNodeDataQ(LinkedList &, Data, Node *);
bool AddInIndex(LinkedList &, int, Node *);

// Delete
bool DeleteHead(LinkedList &, Data &);
bool DeleteTail(LinkedList &, Data &);
bool DeleteNodeData(LinkedList &, Data);
bool DeleteNodeIndex(LinkedList &, int, Data &);
void ClearList(LinkedList &);

// Reverse
void ReverseLinkedList(LinkedList &);
void ReverseLinkedList_UseRecursion(LinkedList &);

// Search
int SearchLinkedList(LinkedList, Data);
int SearchLinkedList_UseRecursion(LinkedList, int &, Data);

// Access
Node *AccessLinkedList(LinkedList, int);

// Cal length (tính độ dài)
int LengthLinkedList(LinkedList);
int LengthLinkedList_UseRecursion(LinkedList);

// Sort Linked List (default: Bubble sort)
void SortLinkedList(LinkedList &);
void MergeSortLinkedList(LinkedList &); // for Doubly Linked List
void QuickSortLinkedList(LinkedList &); // for Doubly Linked List

// Output list
void OutputLinkedList(LinkedList);

#endif