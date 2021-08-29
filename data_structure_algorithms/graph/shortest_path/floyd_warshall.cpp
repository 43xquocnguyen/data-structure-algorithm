#include "../_library_graph_.h"

// Floyd-warshall
ListPath *FloydWarshall(Graph g)
{
    // -- Khởi tạo -- thuật toán
    int n = g.numVertices;
    // Cấp phát
    ListPath *p = new ListPath[n]; // Solution
    Matrix d = new CostType *[n];  // Mảng lưu các phần tử đứng trước
    for (Index i = 0; i < n; i++)
    {
        d[i] = new CostType[n];
    }
    // Khởi tạo
    for (Index i = 0; i < n; i++)
    {
        for (Index j = 0; j < n; j++)
        {
            p[i].push_back(CreatePath(g.vertices[j].lable));
            p[i][j].length = g.cost[i][j];
            d[i][j] = i;
        }
    }

    // -- Floyd-warshall -- //
    for (Index k = 0; k < n; k++)
    {
        for (Index i = 0; i < n; i++)
        {
            for (Index j = 0; j < n; j++)
            {
                if (p[i][j].length > (p[i][k].length + p[k][j].length) 
                && (p[k][j].length != INF && p[i][k].length != INF))
                {
                    p[i][j].length = p[i][k].length + p[k][j].length;
                    d[i][j] = d[k][j];
                }
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
    cout << "======== Floyd-warshall ========\n";
    cout << "======== Press to start ========\n\n";
    cout << "Press anything: ";
    char choose;
    cin >> choose;
    cin.ignore();
    system("cls");
    ResetVertex(g);
    ListPath *p;

    p = FloydWarshall(g);
    OutputMatrixCost(g);
    cout << "======== Floyd-warshall ========\n";
    cout << "========= Shortest path ========\n";
    for (Index i = 0; i < g.numVertices; i++)
    {
        cout << "- Path " << g.vertices[i].lable << ":" << endl;
        PrintSolution(g, p[i], i);
        if (i != g.numVertices - 1)
        {
            cout << endl;
        }
    }
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