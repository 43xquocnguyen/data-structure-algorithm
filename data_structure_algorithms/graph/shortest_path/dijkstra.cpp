#include "../_library_graph_.h"

// Dijkstra
ListPath Dijkstra(Graph g, Index source)
{
    // -- Khởi tạo thuật toán -- //
    int n = g.numVertices;
    ListPath p(n); // Mảng lưu khoảng cách từ source -> các đỉnh còn lại
    for (Index i = 0; i < n; i++)
    {
        p[i] = CreatePath(g.vertices[i].lable);
    }
    p[source].length = 0;

    // -- Dijkstra -- //
    for (Index count = 0; count < n - 1; count++)
    {
        // -- Tìm đỉnh có trọng số nhỏ nhất
        CostType minCost = INT_MAX;
        Index u;
        for (Index i = 0; i < n; i++)
        {
            if (!g.vertices[i].visited && p[i].length <= minCost)
            {
                minCost = p[i].length;
                u = i;
            }
        }
        g.vertices[u].visited = YES;

        // -- Xét các đỉnh nối đỉnh
        for (Index v = 0; v < n; v++)
        {
            // Check đỉnh v:
            // - Chưa đi qua
            // - uv có nối với nhau
            // - p[u] + uv < p[v]
            if (!g.vertices[v].visited && (g.cost[u][v] != 0) && p[u].length != INF && p[u].length + g.cost[u][v] < p[v].length)
            {
                p[v].length = p[u].length + g.cost[u][v];
            }
        }
    }

    return p;
}

// In kết quả
void PrintSolution(Graph g, ListPath p, Index source)
{
    int size = p.size();
    for (Index i = 0; i < size; i++)
    {
        cout << g.vertices[source].lable << "->";
        cout << p[i].target << ": ";
        cout << p[i].length << " (cost)" << endl;
    }
}

// Start
void Start(Graph g)
{
    system("cls");
    cout << "======== Dijkstra ========\n";
    cout << "===== Press to start =====\n\n";
    cout << "Press anything: ";
    char choose;
    cin >> choose;
    cin.ignore();
    system("cls");
    ResetVertex(g);
    ListPath p;

    p = Dijkstra(g, 0);
    OutputMatrixCost(g);
    cout << "======== Dijkstra ========\n";
    cout << "====== Shortest path =====\n";
    PrintSolution(g, p, 0);
    system("pause");
}

int main()
{
    Graph g;
    Initialize(g, true);
    InputGraph(g, "../graph.txt");
    Start(g);
    return 0;
}