#include<iostream>

using namespace std;

const int N = 100;

int m[N][N]; //运算次数
int s[N][N]; //记录分割位置

void MatrixChain(int P[], int n)
{
	int r, i, j, k;
	//初始化对角线
	for (i = 0; i <= n; i++)
	{
		m[i][i] = 0;
	}
	//r个矩阵连乘(子问题规模)
	for (r = 2; r <= n; r++) 
	{
		for (i = 1; i <= n - r + 1; i++)//r个矩阵的r-1个空隙中依次测试最优点
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + P[i - 1] * P[i] * P[j];
			s[i][j] = i;
			for (k = i + 1; k < j; k++)//变换分隔位置，逐一测试
			{
				int t = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
				if (t < m[i][j])//如果变换后的位置更优，则替换原来的分隔方法。
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	int P[] = { 30,35,15,5,10,20 };
	int n = sizeof(P) / sizeof(P[0]);
	MatrixChain(P, n-1);

	cout << "最小计算量的值为：" << m[1][n-1] << endl;
	return 0;
}
