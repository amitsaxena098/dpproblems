#include<bits/stdc++.h>

/*
Time complexity : O(arr.size() * sum)
Space complexity : O(arr.size() * sum)
*/

using namespace std;

int main()
{
	vector<int> arr{2, 3, 7, 8, 10};
	int sum = ;

	vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1, false));



	for(int i = 0; i < arr.size()+1; i++)
	{
		for(int j = 0; j < sum+1; j++)
		{
			if(i == 0)
				dp[i][j] = false;
			if(j == 0)
				dp[i][j] = true;
			if(i > 0 && j > 0)
			{
				if(j >= arr[i-1])
				{
					dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
			}


		}
	}


	cout << dp[arr.size()][sum] << endl;

	return 0;
}