#include <iostream>
using namespace std;

// Backtracking 
void Permutations(string str, int left, int right)
{
	if (left == right) {
        cout << str << endl;
    }
	else
	{
		// Permutations made
		for (int i = left; i <= right; i++)
		{
			// Swapping
			swap(str[left], str[i]);

			// Đệ quy
			Permutations(str, left + 1, right);

			// Backtrack
			swap(str[left], str[i]);
		}
	}
}

int main()
{
	string str;
    cin >> str;
    int n = str.size();
    Permutations(str, 0, n - 1);
    return 0;
}

