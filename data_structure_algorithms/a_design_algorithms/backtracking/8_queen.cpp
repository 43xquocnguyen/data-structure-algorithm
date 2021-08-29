#include <iostream>
#include <vector>
using namespace std;

// Khởi tạo số lượng của bàn cờ
void Initialize(vector<vector<bool>> &board) {
    int n = -1;
    do
    {
        cout << "Enter size board: ";
        cin >> n;
    } while (n <= 1);
    board.resize(n);
    for (int i = 0; i < n; i++)
    {
        board[i] = vector<bool>(n, false);
    }
}

// In ra kết quả
void PrintSolution(vector<vector<bool>> board)
{
    int n = board.size();
    // In số trên bàn cờ (chiều ngang)
    cout << "X\t";
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << "\t";
    }
    cout << "\n\n";

    for (int i = 0; i < n; i++) {
        // In số trên bàn cờ (chiều dọc)
        cout << (i + 1) << "\t";
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                cout << "I";
            }
            else {
                cout << "-";
            }
            cout << "\t";
        }
        cout << "\n\n";
    }
}

// Hàm check 1 quân hậu có thể đặt tại vị trí [row][col] được không?
bool QueenCanPlace(vector<vector<bool>> board, int row, int col)
{
	int i, j;
    int n = board.size();

    // Check bên đường ngang trái
	for (i = 0; i < col; i++) {
		if (board[row][i]) {
            return false;
        }
    }

	// Check đường chéo trên bên trái
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j]) {
			return false;
        }
    }

	// Check đường chéo dưới bên trái
	for (i = row, j = col; j >= 0 && i < n; i++, j--) {
		if (board[i][j]) {
			return false;
        }
    }

	return true;
}

// Hàm solve
bool Solve(vector<vector<bool>> &board, int col)
{
    int n = board.size();
    
    // Đã hết
    if (col >= n) {
        return true;
    }
		
    // Duyệt qua tất cả các hàng
	for (int i = 0; i < n; i++) {
        
        // Kiểm tra có thể đặt tại hàng i cột col hay không?
		if (QueenCanPlace(board, i, col)) {

            // Đặt quân hậu ở đây
			board[i][col] = true;

			// Đệ quy
			if (Solve(board, col + 1)) {
                return true;
            }
            // BACKTRACKING
			board[i][col] = false;
		}
	}
	return false;
}

int main()
{
    // Mảng 2 chiều: Bàn cờ
    vector<vector<bool>> board;

    // Init
    Initialize(board);

    // Backtracking
	if (!Solve(board, 0)) {
        cout << "Solution no exits\n";
    }
    else {
	    PrintSolution(board);
    }
	return 0;
}
