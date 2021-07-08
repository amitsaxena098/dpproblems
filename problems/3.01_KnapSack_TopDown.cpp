#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> wt{10,20,30};
	vector<int> val{60, 100,120};
	int capacity = 50;

	vector<vector<int>> dp(wt.size()+1, vector<int>(capacity+1, 0));

	for(int i = 1; i < wt.size()+1; i++)
	{
		for(int j = 1; j < capacity+1 ; j++)
		{
			if(j >= wt[i-1])
			{

				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
				
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[wt.size()][capacity] << endl;

	return 0;
}