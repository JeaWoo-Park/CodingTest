#include "bits/stdc++.h"

// 백준 2178번 미로 탐색 문제
using namespace std;

// 너비 우선 탐색으로 미로 탐색
int bfs(vector<vector<int>>& maze, int row, int column) //row와 column은 목적지 정보가 됨
{
	vector<vector<int>> visit = maze; // 방문 및 거리 정보
	for (vector<int>& v : visit)
	{
		for (int& i : v)
		{
			i--; // 이동 가능한 곳은 0으로 불가능한 곳은 -1로
		}
	}

	queue<pair<int, int>> bfsQueue;	//방문 노드 큐
	
	visit[0][0] = 1;
	bfsQueue.push({ 0,0 });
	pair<int, int> currentIndex;
	while (!bfsQueue.empty()) //큐가 비워지지 않을 동안 반복
	{
		currentIndex = bfsQueue.front();
		bfsQueue.pop(); // 꺼낸 노드 값 제거
		if (currentIndex == pair<int, int>(row - 1, column - 1))//현재 노드가 목적지라면 다른 탐색 과정은 필요 없음
			break;

		// 다음 칸이 이동 가능한 칸인지 방문하지 않았던 칸인지 판단
		if (currentIndex.first - 1 >= 0 && visit[currentIndex.first - 1][currentIndex.second] == 0)				//좌
		{
			visit[currentIndex.first - 1][currentIndex.second] = visit[currentIndex.first][currentIndex.second] + 1;		//방문했는지 표시와 함께 거리 측정 - 현재 노드에 + 1 하면 다음 노드까지의 거리가 된다.
			bfsQueue.push({ currentIndex.first - 1 ,currentIndex.second });		//방문한 노드 큐에 삽입
		}
		if (currentIndex.first + 1 < row && visit[currentIndex.first + 1][currentIndex.second] == 0)	//우
		{
			visit[currentIndex.first + 1][currentIndex.second] = visit[currentIndex.first][currentIndex.second] + 1;
			bfsQueue.push({ currentIndex.first + 1 ,currentIndex.second });
		}
		if (currentIndex.second - 1 >= 0 && visit[currentIndex.first][currentIndex.second - 1] == 0)		//상
		{
			visit[currentIndex.first][currentIndex.second - 1] = visit[currentIndex.first][currentIndex.second] + 1;		
			bfsQueue.push({ currentIndex.first ,currentIndex.second - 1 });
		}
		if (currentIndex.second + 1 < column && visit[currentIndex.first][currentIndex.second + 1] == 0)		//하
		{
			visit[currentIndex.first][currentIndex.second + 1] = visit[currentIndex.first][currentIndex.second] + 1;		
			bfsQueue.push({ currentIndex.first ,currentIndex.second + 1 });
		}



	}

	// 목적지 노드의 값 반환
	return visit[currentIndex.first][currentIndex.second];


}

int main()
{
	
	int row, column;

	cin >> row;
	cin >> column;
	vector<vector<int>> maze;
	cin.ignore();
	// 정해진 공간 할당
	maze.resize(row);
	for (int i = 0; i < row; ++i)
	{	
		maze[i].resize(column);
		string s;
		getline(cin, s);		//미로 정보 받기
		for (int j = 0; j < column; ++j)
		{
			maze[i][j] = s[j] - '0'; // char를 int로 변환
		}
	}

	int result = bfs(maze, row, column);
	cout << result;


	return 0;
}