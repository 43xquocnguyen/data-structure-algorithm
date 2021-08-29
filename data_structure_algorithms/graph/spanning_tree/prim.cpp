#include "../_library_graph_.h"

// Prim
ListEdge Prim(Graph g)
{
    // -- Khởi tạo thuật toán -- //
    int n = g.numVertices;
    CostType *key = new CostType[n]; // Lưu giá trị cạnh gần có gtnn
    Index *root = new Index[n];      // Lưu root của các đỉnh
    g.vertices[0].visited = YES;     // Bắt đầu thuật toán với đỉnh 0
    for (Index v = 1; v < n; v++)
    {
        if (IsConnected(g, 0, v))
        {
            root[v] = 0;
            key[v] = g.cost[0][v];
        }
        else
        {
            key[v] = INF;
        }
    }

    // -- Prim -- //
    ListEdge e;
    for (Index count = 0; count < n - 1; count++)
    {
        // -- Lấy đỉnh gần nhất
        CostType minCost = INF;
        Index u = NULLINDEX;
        for (Index v = 1; v < n; v++)
        {
            // Nếu v là đỉnh chưa đi qua & trọng số min
            if (!g.vertices[v].visited && key[v] < minCost)
            {
                minCost = key[v];
                u = v;
            }
        }

        // -- Cập nhật đỉnh u đã đi qua & thêm cạnh vừa chọn vào solution
        g.vertices[u].visited = YES;
        Edge et = CreateEdge(root[u], u, g.cost[root[u]][u]);
        e.push_back(et);

        // -- Xét tiếp các đỉnh tiếp theo
        for (Index v = 0; v < n; v++)
        {
            // Check
            // u, v là 2 đỉnh liền kề
            // chưa xét qua v
            // kiểm tra xem độ dài cạnh uv có nhỏ hơn key hay không?
            if (g.cost[u][v] && (!g.vertices[v].visited) && g.cost[u][v] < key[v])
            {
                key[v] = g.cost[u][v];
                root[v] = u;
            }
        }
    }

    return e;
}

// In kết quả
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
    cout << " ======== Prim ========\n";
    cout << " === Press to start ===\n\n";
    cout << "Your choose: ";
    char choose;
    cin >> choose;
    cin.ignore();
    system("cls");
    ResetVertex(g);
    ListEdge e;

    e = Prim(g);
    OutputMatrixCost(g);
    cout << " ======== Prim ========\n";
    cout << " === Spanning Tree ===\n";
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