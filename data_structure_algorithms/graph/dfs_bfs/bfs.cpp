#include "../_library_graph_.h"

// BFS
// Độ phức tạp: 
// - Time: O(V * E) (Danh sách kề)
// - Time: O(V^2) (Ma trận trọng số)
void BFS_UseQueue(Graph &g, Index vertex) {
    // Tạo ra 1 cái queue và bỏ vertex vào
    queue<Index> q;
    q.push(vertex);

    // BFS
    Index nextVertex;
    Index currentVertex;
    while (true)
    {
        if (q.empty()) {
            break;
        }

        // Pop ra vertex + output
        currentVertex = q.front();
        q.pop();
        g.vertices[currentVertex].visited = YES;
        cout << g.vertices[currentVertex].lable << " ";

        // Tìm tất cả các đỉnh còn lại cạnh đỉnh nguồn
        while (true)
        {
            nextVertex = FindAdjacentVertex(g, currentVertex);
            if (nextVertex == NULLINDEX) {
                break;
            }
            else {
                q.push(nextVertex);
                g.vertices[nextVertex].visited = YES;
            }
        }
    }
}

// Start
void Start(Graph g) {
    system("cls");
    cout << "========== BFS ==========\n";
    cout << "===== Press to start ====\n\n";
    cout << "Press anything: ";
    char choose;
    cin >> choose;
    cin.ignore();
    system("cls");
    ResetVertex(g);

    OutputMatrixCost(g);
    cout << "BFS: ";
    BFS_UseQueue(g, 0);
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