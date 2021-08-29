// library hashing number header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef __library_hashing_number__
#define __library_hashing_number__
#pragma once
#include <iostream>
#include <cmath>
using namespace std;

// -------------- Hashing -------------- //
//  _               _     _              //
// | |             | |   (_)             //
// | |__   __ _ ___| |__  _ _ __   __ _  //
// | '_ \ / _` / __| '_ \| | '_ \ / _` | //
// | | | | (_| \__ \ | | | | | | | (_| | //
// |_| |_|\__,_|___/_| |_|_|_| |_|\__, | //
//                                 __/ | //
//                                |___/  //
// -------------- Hashing -------------- //

#define MAX 1000
#define NULLDATA INT_MAX
#define NULLINDEX -1 // Not found (Search use)
#define NO false
#define YES true
#define NSHIFT 2
#define PHI 1.618033989 // (sqrt(5) - 1) / 2

typedef unsigned long long int Index; // kiểu trả về index
typedef long long int Data; // data for store
typedef bool TypeCheck; // data for check

// ------------ Node (for List Node) ------------ //
struct Node;
Node *CreateNode(Data); 

// ------------ List Node ------------ //
typedef Node* List;
void Initialize(List &);

// -- For Data Type -- //
void AppendList(List &, Data); 
void DeleteNodeList(List &, Data); 
bool SearchNodeList(List, Data); 
void OutputList(List);

// ------------ Hash Table ------------ //
struct HashTable;
void Initialize(HashTable &); 
void Initialize(HashTable &, int); 

// ------------ Hash Function (for Number) ------------ //
Index HashFunction_UseDivision(HashTable, Data); // h(k) = k % n
Index HashFunction_UseMidSquareNumber(HashTable, Data); // n=100,k=25,k^2=2500=>>hash=50
Index HashFunction_UseFodingShift(HashTable, Data);
Index HashFunction_UseMultiplicationGoldenRadio(HashTable, Data);
Index HashFunction_UseRotation(HashTable, Data);

// -- Hash check -- //
bool HashIsEmpty(HashTable);
bool HashIsFull(HashTable);

// -- Insert, search, delete & Handle collison -- //
// Linear probing method (Dò tuyến tính)
bool Insert_LinearProbing(HashTable &, Data);
bool Delete_LinearProbing(HashTable &, Data);
Index Search_LinearProbing(HashTable, Data);

// Quadratic probing method (Dò bậc 2)
bool Insert_QuadraticProbing(HashTable &, Data);
bool Delete_QuadraticProbing(HashTable &, Data);
Index Search_QuadraticProbing(HashTable, Data);

// Direct chaining method - Using Linked List (Nối phần tử)
bool Insert_DirectChaining(HashTable &, Data);
bool Delete_DirectChaining(HashTable &, Data);
Index Search_DirectChaining(HashTable, Data);

// -- Output -- //
void Output(HashTable);

#endif