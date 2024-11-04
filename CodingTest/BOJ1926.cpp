#include "bits/stdc++.h"

// 백준 2178번 그림 문제
using namespace std;

// i j 부터 탐색 시작
int bfs(vector<vector<int>>& visit,int i, int j, int row, int column)
{
	queue<pair<int, int>> bfsQueue;
	bfsQueue.push({ i,j });
	visit[i][j] = 0;	//방문한 노드는 0으로 바꿈
	pair<int, int> currentIndex;

	int size = 0;	//그림의 넓이
	while (!bfsQueue.empty())
	{
		currentIndex =  bfsQueue.front();
		bfsQueue.pop(); //꺼낸 값 제거
		++size; //값을 꺼낼 때 마다 그림크기 증가
		if (currentIndex.first - 1 >= 0 && visit[currentIndex.first - 1][currentIndex.second] == 1)
		{
			visit[currentIndex.first - 1][currentIndex.second] = 0;
			bfsQueue.push({ currentIndex.first - 1, currentIndex.second });
		}
		if (currentIndex.first + 1 < row && visit[currentIndex.first + 1][currentIndex.second] == 1)
		{
			visit[currentIndex.first + 1][currentIndex.second] = 0;
			bfsQueue.push({ currentIndex.first + 1, currentIndex.second });
		}
		if (currentIndex.second - 1 >= 0 && visit[currentIndex.first][currentIndex.second - 1] == 1)
		{
			visit[currentIndex.first][currentIndex.second - 1] = 0;
			bfsQueue.push({ currentIndex.first, currentIndex.second - 1 });
		}
		if (currentIndex.second + 1 < column && visit[currentIndex.first][currentIndex.second + 1] == 1)
		{
			visit[currentIndex.first][currentIndex.second + 1] = 0;
			bfsQueue.push({ currentIndex.first, currentIndex.second + 1 });
		}

	}
	
	return size;

}

pair<int,int> solution(vector<vector<int>>& paint, int row, int column)
{
	int paintCnt = 0; //그림의 개수
	int maxSize = 0;  //그림의 최대크기
	int tempSize = 0; //그림의 크기를 받아 둘 임시 변수
	vector<vector<int>> visit = paint;

	for (int j = 0; j < column; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			if (visit[i][j] == 1) //그림의 영역이면 bfs탐색
			{
				tempSize = bfs(visit, i, j, row, column);
				if (maxSize < tempSize)
					maxSize = tempSize;

				++paintCnt; //탐색이 시행 되면 그림이 하나 있다는 뜻
			}
		}
	}

	return pair<int, int>(paintCnt, maxSize);

}

int main()
{

	int row, column;

	cin >> row;
	cin >> column;
	vector<vector<int>> paint;
	cin.ignore();
	// 정해진 공간 할당
	paint.resize(row);
	for (int i = 0; i < row; ++i)
	{
		paint[i].resize(column);
		for (int j = 0; j < column; ++j)
		{
			cin >> paint[i][j]; //미로 한칸한칸의 정보 받기
		}
	}

	pair<int, int> result = solution(paint, row, column);

	cout << result.first << "\n" << result.second;

	return 0;
}