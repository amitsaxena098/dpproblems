#include<bits/stdc++.h>

using namespace std;

int countSubsetSum(vector<int>& nums, int sum) {

	vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, 0));

	for(int i = 0; i < nums.size()+1; i++) {
		for(int j = 0; j < sum+1; j++) {
			if(j == 0) {
				dp[i][j] = 1;
			}

			if(i > 0 && j > 0) {
				if(j >= nums[i - 1]) {
					dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
				} else {
					dp[i][j] = dp[i-1][j];
				}

			}
		}
	}

	return dp[nums.size()][sum];
}

int main() {

	 
	 int n;

	 cin >> n;

	 vector<int> nums(n);
	 for(int i = 0; i < n; i++) {
	 	cin >> nums[i];
	 }

	 int sum;

	 cin >> sum;

	 cout << countSubsetSum(nums, sum) << endl;

	 return 0;
}