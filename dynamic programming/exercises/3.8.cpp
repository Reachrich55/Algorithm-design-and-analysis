/*3.8 设A={a1 ,a2,… ,an}是正整数的集合
设计一个算法判断是否能够把A划分成两个子集A1和A2
使得A1中的数之和与A2中的数之和相等?说明算法的设计思想
估计算法最坏情况下的时间复杂度.*/

/*思路：计算集合的总和 sum。
如果 sum 是奇数，那么不能划分成两个和相等的子集，直接返回 false。
如果 sum 是偶数，创建一个大小为 (sum/2)+1 的数组 dp，其中 dp[i] 表示是否能用集合中的一些数得到和为 i。
初始化 dp[0] 为 true，因为任何集合都可以通过选择不加入任何数得到和为0。
对于集合中的每个数 num，从后往前更新 dp 数组。对于每个 i，如果 dp[i-num] 为 true，那么 dp[i] 也为 true。这表示可以通过当前数 num 来得到和为 i。
最终，dp[sum/2] 的值就表示是否可以划分成两个和相等的子集。*/
#include <iostream>

using namespace std;

bool dp[100];

bool canPartition(int nums[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    if (sum % 2 != 0) {
        return false; // 总和为奇数，无法划分成两个和相等的子集
    }

    int target = sum / 2;
    
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[target];
}

int main() {

    int nums[] = { 1, 5, 11, 5 ,2 };
    int n = sizeof(nums) / sizeof(nums[0]);

    if (canPartition(nums, n)) {
        cout << "The set can be partitioned into two equal sum subsets." << endl;
    }
    else {
        cout << "The set cannot be partitioned into two equal sum subsets." << endl;
    }

    return 0;
}
