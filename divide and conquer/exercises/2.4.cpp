/*2.4 给定含有n个不同的数的数组L<x1, x2 ,…, xn>
如果L中存在xi,使得x1<x2<…<xi>xi+1>…>xn,则称L是单峰的,并称xi是L的“峰顶”
假设L是单峰的,设计一个算法找到L的峰顶。
*/
//思路：二分查找
#include <iostream>

using namespace std;

int FindPeak(int L[], int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (L[mid] < L[mid + 1]) {
            // 峰顶在右侧
            left = mid + 1;
        }
        else {
            // 峰顶在左侧或当前位置即为峰顶
            right = mid;
        }
    }

    // left == right，此时为峰顶的位置
    return L[left];
}

int main() {
    int arr[] = { 1, 3, 5, 8, 10, 6, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << FindPeak(arr, 0, n - 1);
    return 0;
}
