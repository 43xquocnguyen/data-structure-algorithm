#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    std::set<int> pivots;
    int largest_so_far = -2147483648;
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        pivots.erase(pivots.upper_bound(next), pivots.end());
        if (next > largest_so_far)
        {
            largest_so_far = next;
            pivots.insert(next);
        }
    }
    cout << pivots.size() << endl;
    return 0;
}