#include <iostream>

using namespace std;

// 找到跨越中点的最大子数组
int FindMaxCrossingSubarray(int A[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += A[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

// 解决最大子数组问题
int FindMaxSubarray(int A[], int low, int high) {
    if (low == high) {
        return A[low]; // 基本情况：只有一个元素
    }
    else {
        int mid = (low + high) / 2;

        // 情况1：最大子数组在左侧
        int left_max = FindMaxSubarray(A, low, mid);

        // 情况2：最大子数组在右侧
        int right_max = FindMaxSubarray(A, mid + 1, high);

        // 情况3：最大子数组跨越中点
        int cross_max = FindMaxCrossingSubarray(A, low, mid, high);

        // 返回三种情况中的最大值
        return max(max(left_max, right_max), cross_max);
    }
}

int main() {
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_subarray_sum = FindMaxSubarray(arr, 0, n - 1);

    cout << "最大子数组的和为: " << max_subarray_sum;

    return 0;
}
