#include<iostream>
#include<algorithm>

using namespace std;

// dp[i][j]表示前i个物品放入容量为j的背包的最大价值
int dp[100][100];
int tag[100][100];
int Knapsack(int weights[], int values[], int n, int capacity) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            // 装入背包
            if (j >= weights[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weights[i - 1]] + values[i - 1]);
            }
            // 不装入背包
            else
            {
                dp[i][j] = dp[i - 1][j];
            }

            // 标记函数
            if (dp[i - 1][j] > dp[i][j - weights[i - 1]] + values[i - 1])
            {
                tag[i][j] = tag[i - 1][j];
            }
            else
            {
                tag[i][j] = i;
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int weights[] = { 2, 3, 4, 7 };
    int values[] = { 1, 3, 5, 9 };
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 10;

    int result = Knapsack(weights, values, n, capacity);

    cout << "Maximum Value in Knapsack: " << result << "\n" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            cout << tag[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
