#include "bits/stdc++.h"

// 백준 15649번 N과M 문제

using namespace std;

void Track(vector<int>& v, int N, int M)
{
	if (int(v.size()) == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << v[i];
			if (i + 1 == M)
			{
				cout << "\n";
			}
			else
			{
				cout << " ";
			}
		}
		v.pop_back();
		return;
	}
	for (int cur = 1; cur <= N; ++cur) {
		if (find(v.begin(), v.end(), cur) == v.end())
		{
			v.push_back(cur);
			Track(v, N, M);
		}
	}
	if (v.empty())
		return;
	v.pop_back();
	return;

}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v;
	Track(v, N, M);


	return 0;
}