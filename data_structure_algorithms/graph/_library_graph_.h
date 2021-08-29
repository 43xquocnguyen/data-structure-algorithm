// library graph header file

// ============================================== //
//                  Copyright by:                 //
//  _____                                         //
// |     |_ _ ___ ___    ___ ___ _ _ _ _ ___ ___  //
// |  |  | | | . |  _|  |   | . | | | | | -_|   | //
// |__  _|___|___|___|  |_|_|_  |___|_  |___|_|_| //
//    |__|                  |___|   |___|         //
//                                                //
//             43xquocnguyen@gmail.com            // 
// ============================================== //

#ifndef __library_graph__
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// ------------------- Graph ------------------- //
//                               | |             //
//           __ _ _ __ __ _ _ __ | |__           //
//          / _` | '__/ _` | '_ \| '_ \          //
//         | (_| | | | (_| | |_) | | | |         //
//          \__, |_|  \__,_| .__/|_| |_|         //
//             __/ |         | |                 //
//            |___/          |_|                 //
// ------------------- Graph ------------------- //

#define INF 1000
#define NO false
#define YES true
#define NULLINDEX -1

typedef int Index; // index của phần tử trong mảng
typedef char LableType; // kiểu tên của đỉnh, lable
typedef int CostType; // kiểu của giá trị trọng số  
typedef CostType** Matrix; // ma trận trọng số
typedef vector<vector<Index>> Adjacency; // danh sách đỉnh kề

// ------------------- Vertex ------------------- //
struct Vertex
{
    LableType lable; // tên đỉnh
    bool visited; // đi qua hay chưa?
};
Vertex CreateVertex(LableType);

// ------------------- Edge ------------------- //
struct Edge
{
    Index source; // đỉnh nguồn
    Index target; // đỉnh đến
    CostType weight; // trọng số
};
Edge CreateEdge(Index, Index, CostType);

// ------------------- Path ------------------- //
struct Path
{
    LableType target;
    CostType length;
};
Path CreatePath(LableType target);

// -------------------------------------------- //
typedef vector<Edge> ListEdge;
typedef vector<Path> ListPath;

// ------------------- Graph ------------------- //
struct Graph
{
    bool directed; // Vô hướng | có hướng
    int numVertices; // Số đỉnh
    int numEdges; // Số cạnh
    Vertex *vertices; // Tập đỉnh

    // Lưu trữ theo 3 cách
    Matrix cost; // Ma trận trọng số
    Adjacency adjacency; // Danh sách đỉnh kề
    ListEdge edges; // Tập cạnh
};

// -- Initialize & Reset -- //
void Initialize(Graph &); // Khởi tạo graph vô hướng
void Initialize(Graph &, bool); // Khởi tạo graph vô hướng hoặc có hướng
void ResetVertex(Graph &);

// -- Input & Output -- //
// Input
void InputGraph(Graph &); // Input bằng bàn phím
void InputGraph(Graph &, string); // Input bằng file
// Output
void OutputGraph(Graph);
void OutputProperties(Graph);
void OutputMatrixCost(Graph);
void OutputAdjacency(Graph);
void OutputListEdge(Graph);

// -- Graph checking -- //
bool IsConnected(Graph, Index, Index);
bool IsExistEdge(Graph, Index, Index);

// -- Graph finding vertex -- //
Index FindAdjacentVertex(Graph, Index); 

// ---------------------------------------------------- //
//       | |                (_) | | |                   //
//   __ _| | __ _  ___  _ __ _| |_| |__  _ __ ___  ___  //
//  / _` | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __| //
// | (_| | | (_| | (_) | |  | | |_| | | | | | | | \__ \ //
//  \__,_|_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/ //
//           __/ |                                      //
//          |___/                                       //
//                          _ _   _                     //
//                         (_) | | |                    //
//                __      ___| |_| |__                  //
//                \ \ /\ / / | __| '_ \                 //
//                 \ V  V /| | |_| | | |                //
//                  \_/\_/ |_|\__|_| |_|                //
//                                                      //
//                                   | |                //   
//               __ _ _ __ __ _ _ __ | |__              //   
//              / _` | '__/ _` | '_ \| '_ \             //   
//             | (_| | | | (_| | |_) | | | |            //   
//              \__, |_|  \__,_| .__/|_| |_|            //   
//                 __/ |         | |                    //   
//                |___/          |_|                    //
// ---------------------------------------------------- //
                      
// ------------------- DUYỆT ĐỒ THỊ (DFS & BFS) ------------------- //
// -- DFS -- //
void DFS_UseRecursion(Graph &, Index);
void DFS_UseStack(Graph &, Index);

// -- BFS -- //
void BFS_UseRecursion(Graph &, Index);

// ------------------- TÌM CÂY KHUNG NHỎ NHẤT (SPANNING TREE) ------------------- //
// Prim
ListEdge Prim(Graph);

// Kruskal
ListEdge Kruskal(Graph);

// Print solution
void PrintSolution(Graph, ListEdge);

// ------------------- TÌM ĐƯỜNG ĐI (SHORTEST PATH) ------------------- //
// Dijkstra
ListPath Dijkstra(Graph, Index);

// Floy-Warshall
ListPath *FloyWarshall(Graph);

// Bellman-Ford
ListPath BellmanFord(Graph, Index);

// Print solution
void PrintSolution(Graph, ListPath, Index);

#endif