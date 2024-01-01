#include <iostream>

using namespace std;


// 查找最大子数组
int FindMaxSubarray(int A[], int n)
{
	int Sum;
	Sum = A[0];
	for (int i = 1; i < n; i++)
		Sum = max(Sum + A[i], A[i]);
	return Sum;
}

int main() {
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_subarray_sum = FindMaxSubarray(arr, n - 1);

    cout << "最大子数组的和为: " << max_subarray_sum;

    return 0;
}
