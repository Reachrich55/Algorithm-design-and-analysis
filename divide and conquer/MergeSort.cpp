#include <iostream>

using namespace std;

// 合并两个有序数组
void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // 创建临时数组
    int L[10], R[10];

    // 拷贝数据到临时数组 L[] 和 R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // 合并临时数组到 A[p..r]
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // 将剩余的元素复制到 A[p..r]
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序
void MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
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

    printf("原始数组: ");
    printArray(arr, n);

    MergeSort(arr, 0, n - 1);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
