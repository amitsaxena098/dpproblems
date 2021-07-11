#include<bits/stdc++.h>

/*
Time complexity : O(arr.size * sum)
Space complexity : O(arr.size * sum)
*/
using namespace std;


bool subSetSum(vector<int>& arr, int sum ) {

	vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1, false));

	for(int i = 0; i < arr.size()+1; i++) {
		for(int j = 0; j < sum+1; j++) {
			if(j == 0) {
				dp[i][j] = true;
			}

			if(i > 0 && j > 0) {
				if( j >= arr[i-1] ) {
					dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}

	return dp[arr.size()][sum];
}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;

	for(int i : arr) {
		sum += i;
	}

	if(sum%2 != 0) {
		cout << "False\n";
	} else {
		if(subSetSum(arr, sum/2)) {
			cout << "True\n";
		} else {
			cout << "false\n";
		}
	}

	return 0;

}