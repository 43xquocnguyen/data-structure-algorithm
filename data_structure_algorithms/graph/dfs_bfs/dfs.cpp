#include "../_library_graph_.h"

// DFS
// Độ phức tạp: 
// - Time: O(V * E) (Danh sách kề)
// - Time: O(V^2) (Ma trận trọng số)
void DFS_UseRecursion(Graph &g, Index vertex) {
    // In ra đỉnh vertex và đánh dấu đã đi qua
    g.vertices[vertex].visited = YES;
    cout << g.vertices[vertex].lable << " ";

    Index nextVertex;
    while (true)
    {
        // Tìm đỉnh cạnh kế tiếp 
        nextVertex = FindAdjacentVertex(g, vertex);
        if (nextVertex == NULLINDEX) {
            break;
        }
        else {
            // Gọi lại đệ quy
            DFS_UseRecursion(g, nextVertex);
        }
    }
}
void DFS_UseStack(Graph &g, Index vertex) {
    // Tạo ra 1 cái stack<int> để lưu các đỉnh theo Index
    stack<Index> s;
    s.push(vertex);

    // In ra đỉnh vertex và đánh dấu đã đi qua
    cout << g.vertices[vertex].lable << " ";
    g.vertices[vertex].visited = YES;

    // Using stack
    Index currentVertex;
    Index nextVertex;
    while (true)
    {
        // Lấy thằng top ra & pop
        currentVertex = s.top();

        // Tìm next của current
        nextVertex = FindAdjacentVertex(g, currentVertex);

        // Check
        if (nextVertex == NULLINDEX) {
            s.pop();
            if (s.empty()) {
                break;
            }
        }
        else {
            // In ra thằng next và push lại vào trong
            cout << g.vertices[nextVertex].lable << " ";
            g.vertices[nextVertex].visited = YES;
            s.push(nextVertex);
        }
    }
}

// Start
void Start(Graph g) {
    system("cls");
    cout << "========== DFS ==========\n";
    cout << "===== Press to start ====\n\n";
    cout << "Press anything: ";
    char choose;
    cin >> choose;
    cin.ignore();
    system("cls");
    ResetVertex(g);

    OutputMatrixCost(g);
    cout << "DFS: ";
    DFS_UseRecursion(g, 0);
    cout << endl;
    system("pause");
}

int main() {
    Graph g;
    Initialize(g, true);
    InputGraph(g, "../graph.txt");
    Start(g);
    return 0;
}