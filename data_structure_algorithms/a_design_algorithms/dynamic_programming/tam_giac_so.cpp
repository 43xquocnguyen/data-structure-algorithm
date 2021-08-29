#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void InputFile(int **&matrix, int &n)
{
    ifstream fileIn(".dynamicProgramming.txt", ios_base::in);
    if (fileIn.fail()) {
        return;
    }

    string temp;
    getline(fileIn, temp);
    getline(fileIn, temp);
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

void PrintMatrixF(int **matrixF, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << matrixF[i][j] << "\t";
        }
        cout << endl;
    }
    
}
void DynamicProgramming(int **matrix, int n, int *path) {
    // Ma trận quy hoạch
    int **matrixF = new int *[n]{};
    for (int i = 0; i < n; i++)
    {
        matrixF[i] = new int[i + 1]{};
    }

    // Dynamic Programming
    int largest;
    matrixF[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        { 
            if (j == 0) {
                if (i - 1 == 0) {
                    largest = 0;
                }
                else {
                    if (matrixF[i - 1][j] > matrixF[i - 1][j + 1]) {
                        largest = j;
                    }
                    else {
                        largest = j + 1;
                    }
                }
            }
            else if (j == i) {
                largest = j - 1;
            }
            else if (j == i - 1) {
                if (matrixF[i - 1][j] > matrixF[i - 1][j - 1]) {
                    largest = j;
                }
                else {
                    largest = j - 1;
                }
            }
            else {
                if (matrixF[i - 1][j - 1] > matrixF[i - 1][j]) {
                    largest = j - 1;
                }
                else {
                    largest = j;
                }

                if (matrixF[i - 1][j + 1] > matrixF[i - 1][largest]) {
                    largest = j + 1;
                }
            }
            matrixF[i][j] += (matrixF[i - 1][largest] + matrix[i][j]);
        }
    }

    // Lấy kết quả
    path[0] = matrixF[0][0];
    int max, maxLast;
    maxLast = path[0];
    for (int i = 1; i < n; i++)
    {
        max = matrixF[i][0]; // max của 1 dòng
        for (int j = 1; j < i + 1; j++)
        {
            if (matrixF[i][j] > max) {
                max = matrixF[i][j];
            }
        }
        path[i] = max - maxLast;
        maxLast = max;
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

    int *path = new int[n];
    DynamicProgramming(matrix, n, path); // source = vị trí đỉnh a[0][0]
    PrintPath(path, n);

    return 0;
}