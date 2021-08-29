#include "../_library_graph_.h"

// Kruskal
ListEdge Kruskal(Graph g)
{
    // -- Khởi tạo thuật toán -- //
    // Sắp xếp tập cạnh theo trọng số
    int size = g.edges.size();
    for (Index i = 0; i < size - 1; i++)
    {
        for (Index j = i + 1; j < size; j++)
        {
            if (g.edges[i].weight > g.edges[j].weight)
            {
                swap(g.edges[i], g.edges[j]);
            }
        }
    }
    int n = g.numVertices;
    Index *root = new Index[n];
    for (Index i = 0; i < n; i++)
    {
        root[i] = i;
    }

    // -- Kruskal -- //
    ListEdge e;
    for (Index count = 0; count < n - 1; count++)
    {
        CostType minCost = INF;
        Index a = -1;
        Index b = -1;

        // -- Chọn cạnh nhỏ nhất hiện tại chưa được chọn
        for (Index u = count; u < n; u++)
        {
            Index source = g.edges[u].source;
            Index target = g.edges[u].target;
            Index rootSource = source;
            Index rootTarget = target;

            // -- Tìm root của source và target
            while (rootSource != root[rootSource] || rootTarget != root[rootTarget])
            {
                rootSource = root[rootSource];
                rootTarget = root[rootTarget];
            }

            if (rootSource != rootTarget && g.cost[source][target] < minCost)
            {
                minCost = g.cost[source][target];
                a = source;
                b = target;
                break;
            }
        }

        // -- Tìm root của a và b
        Index rootA = a;
        Index rootB = b;
        while (rootA != root[rootA] || rootB != root[rootB])
        {
            rootA = root[rootA];
            rootB = root[rootB];
        }
        root[rootA] = rootB;

        // Thêm cạnh vừa chọn vào solution
        Edge et = CreateEdge(a, b, g.cost[a][b]);
        e.push_back(et);
    }

    return e;
}

// In kết quả (Spanning tree)
void PrintSolution(Graph g, ListEdge e)
{
    int size = e.size();
    int sum = 0;
    for (Index i = 0; i < size; i++)
    {
        sum += e[i].weight;
        cout << g.vertices[e[i].source].lable
             << "" << g.vertices[e[i].target].lable
             << ": " << e[i].weight << " (cost)" << endl;
    }
    cout << "Sum cost: " << sum << endl;
}

// Start
void Start(Graph g)
{
    system("cls");
    cout << " ======== Kruskal ========\n";
    cout << " ===== Press to start ====\n\n";
    cout << "Your choose: ";
    char choose;
    cin >> choose;
    cin.ignore();
    system("cls");
    ResetVertex(g);
    ListEdge e;

    e = Kruskal(g);
    OutputMatrixCost(g);
    cout << " ======== Kruskal ========\n";
    cout << " ===== Spanning Tree =====\n";
    PrintSolution(g, e);
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