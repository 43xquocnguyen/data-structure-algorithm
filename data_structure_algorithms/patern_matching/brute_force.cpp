#include <string>
#include <string.h>
#include <iostream>
using namespace std;

// Độ phức tạp: O(m(n - m + 1))
int BruteForce(char des[], char target[]) {
    int n = strlen(des);
    int m = strlen(target);

    int count = 0;
    int i, j;

    // Brute Force
    for (i = 0; i < (n - m); i++)
    {
        for (j = 0; (j < m); j++) {
            if (target[j] != des[i + j]) {
                break;
            }
        }
        if (j >= m) {
            count++;
        }
    }
    
    return count;
}

int main() {
    char des[] = "dasdBACdsadBAasdsad";
    char target[] = "BAC";

    int count = BruteForce(des, target);
    cout << "(target) " << count << " time in (des)";
}