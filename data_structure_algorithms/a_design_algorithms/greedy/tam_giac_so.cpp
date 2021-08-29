#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void InputFile(int **&matrix, int &n)
{
    ifstream fileIn("tamGiacSo.txt", ios_base::in);
    if (fileIn.fail()) {
        return;
    }

    string temp;
    for (int i = 0; i < 2; i++)
    {
        getline(fileIn, temp);
    }
    getline(fileIn, temp, '=');

    fileIn >> n;
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            fileIn >> matrix[i][j];
        }
    }

    fileIn.close();
}

void Greedy(int **matrix, int n, int *path) {
    int leftJ, rightJ, nextI;
    int largest;
    int i = 0, j = 0;
    path[0] = matrix[0][0];

    for (; i < n - 1; i++)
    {
        nextI = i + 1;
        leftJ = j - 1;
        rightJ = j + 1;

        if (matrix[nextI][j] > matrix[nextI][rightJ]) {
            largest = j;
        }
        else {
            largest = rightJ;
        }

        if (leftJ >= 0 && matrix[nextI][leftJ] > matrix[nextI][largest]) {
            largest = leftJ;
        }
        j = largest;

        path[i + 1] = matrix[nextI][largest];
    }
}
void PrintPath(int *path, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << path[i];
        if (i != n - 1) {
            cout << " -> ";
        }
    }
}

int main() {
    int **matrix;
    int n = -1;
    InputFile(matrix, n);

    // path lưu các giá trị lựa chọn cho thứ tự đi tối ưu
    int *path = new int[n];
    Greedy(matrix, n, path); // source = vị trí đỉnh a[0][0]
    PrintPath(path, n);

    return 0;
}