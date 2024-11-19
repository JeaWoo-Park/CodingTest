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
	Track(nums, cnt + 1, sum);		// 해당 인덱스 합 안한 상태로 다음단계로
	sum += nums[cnt];				// 해당 인덱스 합
	if (sum == s)					// 목표 도달 확인
	{
		++result;
	}
	Track(nums, cnt + 1, sum);		// 합 한 값으로 다음 단계로

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