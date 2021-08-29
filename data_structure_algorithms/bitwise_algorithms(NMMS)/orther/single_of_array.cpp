#include <iostream>
using namespace std;

int GetSingleElement(int *arr, int n)
{
    int ones = 0;
    int twos = 0;
    int common_bit_mask;
	
	for (int i = 0; i < n; i++) {
		
		twos = twos | (ones & arr[i]);
		
		ones = ones ^ arr[i];
		
		common_bit_mask = ~(ones & twos);
		
		ones &= common_bit_mask;
		
		twos &= common_bit_mask;
	}

	return ones;
}

int main()
{
    int arr[] = {3, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The element with single occurrence is " << GetSingleElement(arr, n);
    return 0;
}