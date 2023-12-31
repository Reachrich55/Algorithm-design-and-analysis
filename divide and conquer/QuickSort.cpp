#include <iostream>
#include <algorithm>
using namespace std;

// 快速排序
void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        // 将数组划分为两部分
        int pivot = arr[left]; // 选择第一个元素作为枢轴
        int i = left;
        int j = right;

        while (i != j) {
            // 从右向左扫描，找到第一个小于枢轴的元素
            while (i < j && arr[j] >= pivot)
                j--;

            // 从左向右扫描，找到第一个大于枢轴的元素
            while (i < j && arr[i] <= pivot)
                i++;

            // 交换两个元素，使得小于枢轴的元素在左侧，大于枢轴的元素在右侧
            if (i < j)
                swap(arr[i], arr[j]);
        }

        // 将枢轴元素放入正确的位置
        swap(arr[left], arr[i]);

        // 递归对划分的两部分进行排序
        QuickSort(arr, left, i - 1);
        QuickSort(arr, i + 1, right);
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "原始数组: ";
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    cout << "排序后的数组: ";
    printArray(arr, n);
    return 0;
}
