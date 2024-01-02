/*2.2 设A是n个非0实数构成的数组，设计一个算法重新排列数组中的数，使得负数都排在正数前面。
要求算法使用O(n)的时间和O(1)的空间.
*/

/*思路：类似快速排序的划分过程，从后向前把每个数与0比较，找到第一个负数A[r]。
从前向后把每个数与0比较，找到第一个正数A[l]。
如果r>l,则将A[r]与A[l]交换
*/
#include <iostream>
#include <algorithm>

using namespace std;

//快速排序
void Rearrange(int arr[], int left, int right) {
    if (left < right) {
        // 将数组划分为两部分

        int pivot = 0; // 将枢轴设为0
        int i = left;
        int j = right;

        while (i != j) // 一趟快排
        {
            while (i < j && arr[j] >= pivot) // 从右向左扫描，找到第一个小于枢轴的元素
                j--;
            
            while (i < j && arr[i] <= pivot) // 从左向右扫描，找到第一个大于枢轴的元素
                i++;
            // 交换这两个元素
            if (i < j) {
                swap(arr[i], arr[j]);
                // 将i指针向右移动，将j指针向左移动
                i++, j--;
            }
        }

        // 递归对划分的两部分进行排序
        Rearrange(arr, left, i - 1);
        Rearrange(arr, i + 1, right);
    }
    else return; // 递归出口
}

//打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    printArray(arr, n);

    Rearrange(arr, 0, n - 1);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
