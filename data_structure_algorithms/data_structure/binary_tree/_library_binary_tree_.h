// library binary search tree header

//  _       ____    __   _            _ __  
// (_/_(_(_(_)(__   / (_(_/_(_(_(_/__(/_/ (_
//  /(                 .-/     .-/          
// (_)                (_/     (_/

#ifndef __library_bst__
#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

// ---------------------- Binary Search Tree ---------------------- //
//  _     _                                                  _      //
// | |   (_)                                                | |     //
// | |__  _ _ __   __ _ _ __ _   _   ___  ___  __ _ _ __ ___| |__   //
// | '_ \| | '_ \ / _` | '__| | | | / __|/ _ \/ _` | '__/ __| '_ \  //
// | |_) | | | | | (_| | |  | |_| | \__ \  __/ (_| | | | (__| | | | //
// |_.__/|_|_| |_|\__,_|_|   \__, | |___/\___|\__,_|_|  \___|_| |_| //
//                            __/ |                                 //
//                           |___/                                  //
//                      _                                           //
//                     | |                                          //
//                     | |_ _ __ ___  ___                           //
//                     | __| '__/ _ \/ _ \                          //
//                     | |_| | |  __/  __/                          //
//                      \__|_|  \___|\___|                          //
//                                                                  //
// ---------------------- Binary Search Tree ---------------------- //

#define MAX 100
#define NULLDATA "NONE"

typedef long long int Data; // data for store

// ------------ Node ------------ //
struct Node;
Node *CreateNode(Data);

// ------------ Tree ------------ //
typedef Node* Tree;
void Initialize(Tree &); 

// Function Tree

// Check & Count Tree
bool TreeIsEmpty(Tree);
int HeightTree(Tree);
int HeightTree_UseQueue(Tree);

// Max in Tree, diameter max in trê
int MaxInTree(Tree);
int Diameter(Tree);

// Insert, Delete, Search
bool InsertTree(Tree &, Data);
string SearchTree(Tree, Data); // return path
bool DeleteNodeTree(Tree &, Data);

// Display output, default: N-L-R (Node left right)
void OutputRecursion(Tree); 
void OutputUseStack(Tree); 
void OutputUseQueue(Tree); 
void OutputNodeTwoChild(Tree);
void OutputNodeOneChild(Tree);
void OutputLeafNode(Tree);

// For AVL & Red Black
// Rolation AVL & Red black
void Adjustment_Balance(Tree &);
int GetBalance(Tree t);
Tree LeftRolation(Tree t);
Tree RightRolation(Tree t);

#endif