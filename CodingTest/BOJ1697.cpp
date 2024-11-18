#include "bits/stdc++.h"

// 백준 1697번 숨바꼭질 문제

using namespace std;

#define MAX 100001

int main()
{
	
	vector<int> v;
	v.resize(MAX);
	fill(v.begin(), v.end(), -1);

	queue<int> findingQ;
	int sue, sister;

	cin >> sue >> sister;
	v[sue] = 0; //시작지점

	int currentIndex;
	findingQ.push(sue);
	while (v[sister] == -1)
	{
		currentIndex = findingQ.front();
		findingQ.pop();

		for (int i : {currentIndex + 1, currentIndex - 1, currentIndex * 2})
		{
			if (i < 0 || i >= MAX) continue;
			if (v[i] != -1) continue;
			v[i] = v[currentIndex] + 1;
			findingQ.push(i);
		}

	}

	cout << v[sister]; //루프를 종료하면 currentIndex가 찾기까지 걸린 시간

	return 0;
}