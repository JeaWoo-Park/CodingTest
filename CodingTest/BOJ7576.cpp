#include "bits/stdc++.h"

// 백준 2178번 토마토 문제

using namespace std;

int CheckTomato(vector<vector<int>>& tomato)
{
	int max = 0;
	for (vector<int>& v : tomato)
	{
		for (int& i : v)
		{
			if (i == 0)
			{
				//익지 않은 토마도 존재
				return -1;
			}
			if (max < i)
			{
				max = i;
			}
		}
	}
	return max - 1; //1부터 시작했기 때문에 거리는 -1해야함
}

int main()
{

	queue<pair<int, int>> q; // 노드 좌표를 넣는 큐
	vector<vector<int>> tomato; //토마도 노드
	int row, column;

	cin >> column;
	cin >> row;
	cin.ignore();
	tomato.resize(row);
	for (int i = 0; i < row; ++i)
	{
		tomato[i].resize(column);
		for (int j = 0; j < column; ++j)
		{
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
				q.push({ i,j });		// 익은 토마토(1) 이라면 시작 노드로 큐에 추가
		}
	}

	pair<int, int> currentIndex;
	while (!q.empty())
	{
		currentIndex = q.front();
		q.pop();					//가장 앞 노드를 가져오고 pop

		if (currentIndex.first - 1 >= 0 && tomato[currentIndex.first - 1][currentIndex.second] == 0)
		{
			tomato[currentIndex.first - 1][currentIndex.second] = tomato[currentIndex.first][currentIndex.second] + 1;	//현재 노드에서 1을 더하면 다음 노드의 거리
			q.push({ currentIndex.first - 1,currentIndex.second });														//다음 노드 큐에 추가
		}
		if(currentIndex.first + 1 < row && tomato[currentIndex.first + 1][currentIndex.second] == 0)
		{
			tomato[currentIndex.first + 1][currentIndex.second] = tomato[currentIndex.first][currentIndex.second] + 1;
			q.push({ currentIndex.first + 1,currentIndex.second });
		}
		if (currentIndex.second - 1 >= 0 && tomato[currentIndex.first][currentIndex.second - 1] == 0)
		{
			tomato[currentIndex.first][currentIndex.second - 1] = tomato[currentIndex.first][currentIndex.second] + 1;
			q.push({ currentIndex.first,currentIndex.second - 1 });
		}
		if (currentIndex.second + 1 < column && tomato[currentIndex.first][currentIndex.second + 1] == 0)
		{
			tomato[currentIndex.first][currentIndex.second + 1] = tomato[currentIndex.first][currentIndex.second] + 1;
			q.push({ currentIndex.first ,currentIndex.second + 1 });
		}


	}

	cout << CheckTomato(tomato);



	return 0;
}