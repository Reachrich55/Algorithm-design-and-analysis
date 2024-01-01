#include<iostream>
#include<algorithm>

using namespace std;

int dp[100][100];

int LCS(string A, string B) {
    int m = A.length();
    int n = B.length();

    // 初始化数组，将边界条件置为0
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // 处理初值
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            // i,j ≥ 1
            else if (A[i - 1] == B[j - 1]) //选入公共子序列
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // 返回右下角的元素，即最终的LCS长度
    return dp[m][n];
}

int main() {
    string A = "ABCBDAB";
    string B = "BDCABA";

    int result = LCS(A, B);

    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}
