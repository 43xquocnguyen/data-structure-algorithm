#include "../_library_graph_.h"

// Bellman-Ford
ListPath BellmanFord(Graph g, Index source)
{
    // -- Khởi tạo thuật toán -- //
    int n = g.numVertices;
    int e = g.numEdges;
    ListPath p(n); // Mảng lưu khoảng cách từ source -> các đỉnh còn lại
    for (Index i = 0; i < n; i++)
    {
        p[i] = CreatePath(g.vertices[i].lable);
    }
    p[source].length = 0;

    // -- Bellman-Ford -- //
    for (Index i = 1; i <= n - 1; i++)
    {
        for (Index j = 0; j < e; j++)
        {
            Index u = g.edges[j].source;
            Index v = g.edges[j].target;
            CostType weight = g.edges[j].weight;

            if (p[u].length != INF && p[u].length + weight < p[v].length)
            {
                p[v].length = p[u].length + weight;
            }
        }
    }

    // -- Check không có chu trình âm -- //
    for (Index i = 0; i < e; i++)
    {
        Index u = g.edges[i].source;
        Index v = g.edges[i].target;
        CostType weight = g.edges[i].weight;
        if (p[u].length != INT_MAX && p[u].length + weight < p[v].length)
        {
            cout << "Graph contains negative weight cycle" << endl;
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
    cout << "======== Bellman-Ford ========\n";
    cout << "======= Press to start =======\n\n";
    cout << "Press anything: ";
    char choose;
    cin >> choose;
    cin.ignore();
    system("cls");
    ResetVertex(g);
    ListPath p;

    p = BellmanFord(g, 0);
    OutputMatrixCost(g);
    cout << "======== Bellman-Ford ========\n";
    cout << "======== Shortest path =======\n";
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