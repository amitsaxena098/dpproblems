#include<bits/stdc++.h>

/*
Time Complexity: O(N*capacity). 
Auxiliary Space: O(N*capacity). 
*/

using namespace std;


int knapsack(vector<int>& wt, vector<int>& val, int capacity, int n, vector<vector<int>>& memo)
{
	if(n == 0 || capacity == 0)
		return 0;

	if(memo[n][capacity] != -1)
		return memo[n][capacity];

	if(capacity >= wt[n-1])
		return memo[n][capacity] = max(val[n-1] + knapsack(wt, val, capacity - wt[n-1], n-1, memo), knapsack(wt, val, capacity, n-1, memo));
	else
		return memo[n][capacity] = knapsack(wt, val, capacity, n-1, memo);
}
int main()
{
	vector<int> wt{10,20,30};
	vector<int> val{60, 100,120};
	int capacity = 50;

	vector<vector<int>> memo(capacity+1, vector<int>(wt.size()+1, -1));
	
	cout << knapsack(wt, val, capacity, wt.size(), memo) << endl;;

	return 0;
}