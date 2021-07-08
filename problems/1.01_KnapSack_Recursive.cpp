#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int capacity, int n)
{
	if(n == 0 || capacity == 0)
		return 0;

	if(capacity >= wt[n-1])
		return max(val[n-1] + knapsack(wt, val, capacity - wt[n-1], n-1), knapsack(wt, val, capacity, n-1));
	else
		return knapsack(wt, val, capacity, n-1);
}
int main()
{
	vector<int> wt{10,20,30};
	vector<int> val{60, 100,120};
	int capacity = 50;
	
	cout << knapsack(wt, val, capacity, wt.size()) << endl;;

	return 0;
}