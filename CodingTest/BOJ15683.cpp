//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
// 백준 15683번 감시 문제

using namespace std;
int n, m;
int minBlind = 0;
 
// 방향에 대한 변수
// 인덱스 : 0 북 1 동 2 남 3 서
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> office;
vector<vector<int>> spy;
bool NotInRange(int a, int b)
{
	return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir)
{
	dir %= 4;	//4방향으로 맞추기

	while(true)
	{
		x += dx[dir];
		y += dy[dir]; //방향에 맞게 증감
		if (NotInRange(x, y) || spy[x][y] == 6) return; // 범위 밖이거나 벽이면
		if (spy[x][y] != 0) continue; // 0도 6도 아닌곳 -> cctv거나 감시영역
		spy[x][y] = 7;
	}

}

int main()
{
	cin >> n >> m;
	minBlind = n * m;
	vector<pair<int, int>> cctv;

	office.resize(n);
	for (int i = 0; i < n; ++i)
	{
		office[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			cin >> office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6)
			{
				cctv.push_back({ i,j });
			}
		}
	}
	spy = office;
	int numcase = 1;
	for (int i = 0; i < cctv.size(); ++i)
	{
		numcase *= 4;
	}

	for (int temp = 0; temp < numcase; ++temp)
	{
		spy = office;	//감시영역 초기화
		int brute = temp;
		for (int i = 0; i < cctv.size(); ++i)
		{
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (office[x][y] == 1)
			{
				upd(x, y, dir);
			}
			else if (office[x][y] == 2)
			{
				upd(x, y, dir);
				upd(x, y, dir + 2);	//반대편
			}
			else if (office[x][y] == 3)
			{
				upd(x, y, dir);
				upd(x, y, dir +1);	//90도
			}
			else if (office[x][y] == 4)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);	
				upd(x, y, dir + 2);	//3방향
			}
			else if (office[x][y] == 5)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);	
				upd(x, y, dir + 3);	//4방향
			}
		}
		int val = 0;
		for (vector<int> v : spy)
		{
			for (int i : v)
			{
				if (i == 0)
					val++;	//감시영역, 벽을 제외한 모든 공간은 0
			}
		}
		minBlind = min(minBlind, val);		//더 작은 수 구하기
	}	

	cout << minBlind;
	return 0;
}