#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
int A[2000 + 16];
int B[2000 + 16];
int dp[2][2000 + 16];		// dp[i][j] := 前i + 1个数变成单调且最后一个数是B[j]，此时的最小成本
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	memcpy(B, A, N * sizeof(int));
	sort(B, B + N);
	for (int j = 0; j < N; ++j)
	{
		dp[0][j] = abs(A[0] - B[j]);
	}
	for (int i = 1; i < N; ++i)
	{
		int cur = i & 0x1;
		int pre = (i - 1) & 0x1;
		int pre_min_cost = dp[pre][0];	// dp[i - 1][0...j]的最小值
		for (int j = 0; j < N; ++j)
		{
			pre_min_cost = min(pre_min_cost, dp[pre][j]);
			dp[cur][j] = pre_min_cost + abs(A[i] - B[j]);	// 前一个最优解(长i-1 + 1)的基础上，加入B[j]凑成长i+1
		}
	}
	int cur = (N - 1) & 0x1;
	cout << *min_element(dp[cur], dp[cur] + N) << endl;
 
    return 0;
}
///////////////////////////End Sub//////////////////////////////////
