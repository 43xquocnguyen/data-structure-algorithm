// library graph cpp file

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

#include "_library_graph_.h"

// -- Create & initialize (Vertex, Edge, Path) -- //
Vertex CreateVertex(LableType lab) {
    Vertex v;
    v.lable = lab;
    v.visited = NO;
    return v;
}
Edge CreateEdge(Index source, Index target, CostType weight) {
    Edge e;
    e.source = source;
    e.target = target;
    e.weight = weight;
    return e;
}
Path CreatePath(LableType target) {
    Path p;
    p.target = target;
    p.length = INF;
    return p;
}

// ------------------- Graph ------------------- //

// -- Initialize -- //
void Initialize(Graph &g) {
    g.directed = false;
    g.numVertices = 0;
    g.numEdges = 0;
    g.vertices = NULL;
    g.edges.resize(0);
    g.cost = NULL;
}
void Initialize(Graph &g, bool directed) {
    g.directed = directed;
    g.numVertices = 0;
    g.numEdges = 0;
    g.vertices = NULL;
    g.edges.resize(0);
    g.cost = NULL;
}
void ResetVertex(Graph &g) {
    int numV = g.numVertices;
    for (int i = 0; i < numV; i++)
    {
        g.vertices[i].visited = NO;
    }
}

// -- Input & Output -- //
void InputGraph(Graph &g, string nameFile) {
    // File input
    ifstream fileIn(nameFile, ios_base::in);
    if (fileIn.fail()) {
        cout << "Error name file!\n";
        return;
    }

    // Đọc số đỉnh
    int numV;
    fileIn >> numV;
    g.numVertices = numV;

    // Đọc số cạnh
    int numE;
    fileIn >> numE;
    g.numEdges = numE;

    // Đọc đồ thị có hướng hay vô hướng ?
    char directed;
    fileIn >> directed;
    g.directed = (directed == 1) ? true : false;
    fileIn.ignore();

    // Đọc lable tất các đỉnh
    g.vertices = new Vertex[numV];
    for (Index i = 0; i < numV; i++)
    {
        LableType lable;
        fileIn >> lable;
        g.vertices[i] = CreateVertex(lable);
    }

    // Cấp phát cho ma trận trọng số
    g.cost = new CostType *[numV];
    for (Index i = 0; i < numV; i++)
    {
        g.cost[i] = new CostType[numV];
    }
    
    // Đọc ma trận trọng số & danh sách kề & tập cạnh
    g.adjacency.resize(numV);
    for (Index i = 0; i < numV; i++) 
    {
        for (Index j = 0; j < numV; j++) 
        {
            CostType weight;
            fileIn >> weight;

            // Ma trận trọng số
            g.cost[i][j] = weight;

            // Danh sách kề & tập cạnh
            if (weight == 0 || weight == INF) {
                continue;
            }
            else if (weight != INF) {
                // Danh sách kề
                g.adjacency[i].push_back(j);
                // Tập cạnh
                Edge e;
                if (g.directed) {
                    e = CreateEdge(i, j, weight);
                    g.edges.push_back(e);
                }
                else {
                    if (!IsExistEdge(g, j, i)) {
                        e = CreateEdge(i, j, weight);
                        g.edges.push_back(e);
                    }
                }
            }
        }
    }

    fileIn.close();
}
void InputGraph(Graph &g) {
    // keyboard input
}
void OutputGraph(Graph g) {
    OutputProperties(g);
    OutputMatrixCost(g);
    OutputAdjacency(g);
    OutputListEdge(g);
} 
void OutputProperties(Graph g) {
    // Thuộc tính và số lượng của graph
    int numV = g.numVertices;
    int numE = g.numEdges;
    cout << "Num vertices: " << numV << endl;
    cout << "Num Edges: " << g.numEdges << endl;
    cout << "Directed graph: " << ((g.directed == true) ? ("Directed\n") : ("No directed\n"));

    // Các đỉnh
    cout << "All vertex: ";
    for (Index i = 0; i < numV; i++) {
        cout << g.vertices[i].lable << " ";
    }
    cout << endl;
}   
void OutputMatrixCost(Graph g) {
    // Ma trận trọng số
    int n = g.numVertices;
    cout << "Matrix cost:\n";
    for (Index i = 0; i < n; i++) {
        for (Index j = 0; j < n; j++) 
        {
            if (g.cost[i][j] == INF) {
                cout << (char)236 << "  ";
            }
            else {
                cout << g.cost[i][j] << "  ";
            }
        }
        cout << endl;
    }
}
void OutputAdjacency(Graph g) {
    // Danh sách kề
    int n = g.numVertices;
    cout << "Matrix adjacency:\n";
    for (Index i = 0; i < n; i++)
    {
        int size = g.adjacency[i].size();
        cout << g.vertices[i].lable << ": ";
        for (Index j = 0; j < size; j++)
        {
            cout << g.vertices[g.adjacency[i][j]].lable << " ";
        }
        cout << "\n";
    }
}
void OutputListEdge(Graph g) {
    // Tập cạnh
    cout << "Edge set: {";
    for (Index i = 0; i < g.edges.size(); i++)
    {
        cout << "(" << g.vertices[g.edges[i].source].lable << "; "
             << g.vertices[g.edges[i].target].lable << "), "
             << "   " << g.edges[i].weight << endl;
    }
    cout << "}";
}

// -- Graph checking -- //
bool IsConnected(Graph g, Index source, Index target) {
    if (g.cost[source][target] != INF) 
    {
        return true;
    }
    return false;
}
bool IsExistEdge(Graph g, Index source, Index target) {
    int size = g.edges.size();

    // Kiểm tra tồn tại cạnh
    for (Index i = 0; i < size; i++)
    {
        if (g.edges[i].source == source && g.edges[i].target == target) {
            return true;
        }
    }

    return false;
}

// -- Graph finding vertex -- //
Index FindAdjacentVertex(Graph g, Index current) {
    int numV = g.numVertices;
    for (Index i = 0; i < numV; i++) 
    {
        if (!g.vertices[i].visited && IsConnected(g, current, i)) 
        {
            return i;
        }
    }
    return NULLINDEX;
}