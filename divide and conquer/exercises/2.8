/*2.8 设A和B都是从小到大已经排好序的n个不等的整数构成的数组
如果把A与B合并后的数组记作C
设计一个算法找出C的中位数
*/
// 思路：C中元素个数为偶数
#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

// 使用分治策略合并两个有序数组并找到中位数
double findMedian(int A[], int startA, int endA, int B[], int startB, int endB) {

    if (startA == endA && startB == endB)
        return (A[startA] + B[startB]) / 2.0;
    int midA = (startA + endA) / 2;
    int midB = (startB + endB) / 2;

    //中位数相等，C的中位数即（midA+midB）/2
    if (A[midA] == B[midB])
        return A[midA];

    else if (A[midA] < B[midB]) {
        startA = midA+1;
        endB = midB ;
        return findMedian(A, startA, endA, B, startB, endB);
    }
    else {
        endA = midA;
        startB = midB+1;
        return findMedian(A, startA, endA, B, startB, endB);
    }
}

int main() {
    int A[] = { 1, 3 };
    int m = sizeof(A) / sizeof(A[0]);

    int B[] = { 2, 4 };
    int n = sizeof(B) / sizeof(B[0]);

    double median = findMedian(A, 0, m - 1, B, 0, n - 1);

    cout << "合并后的数组的中位数: " << median << endl;
    
    return 0;
}
