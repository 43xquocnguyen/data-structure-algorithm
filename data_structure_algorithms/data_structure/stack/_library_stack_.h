// library stack header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef __library_stack__
#pragma once
#include <iostream>
#include <string>
using namespace std;

// --------- Stack --------- //
//      _             _      //
//     | |           | |     //
//  ___| |_ __ _  ___| | __  //
// / __| __/ _` |/ __| |/ /  //
// \__ \ || (_| | (__|   <   //
// |___/\__\__,_|\___|_|\_\  //
//                           //
// --------- Stack --------- //

#define MAX 1000
#define NULLINDEX -1
#define NULLDATA INT_MAX

typedef int Index;
typedef long long int Data;

template<class T> void Swap(T &, T &);

// ------------ Node ------------ //
struct Node;
Node *CreateNode(Data);

// ------------ Stack ------------ //
// Structure Stack
struct Stack;
void Initialize(Stack &);
void Initialize(Stack &, int);

// Function Stack
// Check stack
bool StackIsEmpty(Stack);
bool StackIsFull(Stack);
int SizeStack(Stack);

// Push & pop & peek
Data PeekStack(Stack);
bool PushStack(Stack &, Data);
bool PopStack(Stack &);

// Output stack
void OutputStack(Stack);

template<class T> void Swap(T &ele1, T &ele2) {
    T temp = ele1;
    ele1 = ele2;
    ele2 = temp;
}

#endif