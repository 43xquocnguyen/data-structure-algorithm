#include <iostream>
#include <unordered_map>
using namespace std;

int ceildivide(int top, int bot)
{
    return (bot + top - 1) / bot;
}

int main()
{
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        seen[temp]++;
    }

    int processing = 0;
    for (int i = 0; i <= 999; i++)
    {
        processing += seen[i];
    }

    int best = processing;
    for (int i = 1000; i <= 100000; i++)
    {
        processing += seen[i];
        processing -= seen[i - 1000];
        best = max(best, processing);
    }

    cout << ceildivide(best, k) << endl;
}
