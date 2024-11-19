#include "bits/stdc++.h"

// 백준 1182번 부분수열의 합 문제

using namespace std;
int result = 0;
int n, s;
void Track(vector<int>& nums, int cnt, int sum = 0)
{
	if (n == cnt)
	{
		return;
	}
	Track(nums, cnt + 1, sum);
	sum += nums[cnt];
	if (sum == s)
	{
		++result;
	}
	Track(nums, cnt + 1, sum);

}

int main()
{
	
	cin >> n >> s;
	vector<int> nums;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		nums.push_back(temp);
	}
	Track(nums, 0);

	cout << result;
	return 0;
}