#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9};
    for (auto &i : a) {
        cout << i << endl;
    }
    return 0;
}