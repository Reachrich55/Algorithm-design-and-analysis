/*5.6 子集和问题 设n个不同的正数构成集合S,求出使得和为某数M的S的所有子集*/

#include <iostream>

using namespace std;

int current[100];

void findSubsets(int S[], int n, int index, int target, int current[], int currentSize) {
    if (target == 0) {
        cout << "Subset: { ";
        for (int i = 0; i < currentSize; i++) {
            cout << current[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    for (int i = index; i < n; i++) {
        if (S[i] <= target) {
            current[currentSize] = S[i];
            findSubsets(S, n, i + 1, target - S[i], current, currentSize + 1);
        }
    }
}

int main() {
    // 示例用例
    int S[] = { 3, 1, 4, 6, 2, 5 };
    int n = sizeof(S) / sizeof(S[0]);
    int target = 10;

    findSubsets(S, n, 0, target, current, 0);

    return 0;
}
