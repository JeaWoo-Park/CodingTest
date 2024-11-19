#include "bits/stdc++.h"

// 백준 9663번 N-Queen 문제

using namespace std;

int N;
void Track(vector<pair<int,int>>& Queens, int cnt, int& result)
{
	if (cnt == N)
	{
		++result;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		bool valid = true;
		for (auto q : Queens)
		{
			if (q.second == i) valid = false;
			if (q.first + q.second == i + cnt) valid = false;
			if (q.first - q.second == cnt - i) valid = false;
		}
		if (valid)
		{
			Queens.push_back({ cnt,i });
			Track(Queens, cnt + 1, result);
			Queens.pop_back();
		}

	}
	return;
}


int main()
{
	
	cin >> N;
	vector<pair<int, int>> QueenList;

	int result = 0;
	Track(QueenList, 0, result);
	cout << result;

	return 0;
}