#include "bits/stdc++.h"

// ���� 2178�� �̷� Ž�� ����
using namespace std;

// �ʺ� �켱 Ž������ �̷� Ž��
int bfs(vector<vector<int>>& maze, int row, int column) //row�� column�� ������ ������ ��
{
	vector<vector<int>> visit = maze; // �湮 �� �Ÿ� ����
	for (vector<int>& v : visit)
	{
		for (int& i : v)
		{
			i--; // �̵� ������ ���� 0���� �Ұ����� ���� -1��
		}
	}

	queue<pair<int, int>> bfsQueue;	//�湮 ��� ť
	
	visit[0][0] = 1;
	bfsQueue.push({ 0,0 });
	pair<int, int> currentIndex;
	while (!bfsQueue.empty()) //ť�� ������� ���� ���� �ݺ�
	{
		currentIndex = bfsQueue.front();
		bfsQueue.pop(); // ���� ��� �� ����
		if (currentIndex == pair<int, int>(row - 1, column - 1))//���� ��尡 ��������� �ٸ� Ž�� ������ �ʿ� ����
			break;

		// ���� ĭ�� �̵� ������ ĭ���� �湮���� �ʾҴ� ĭ���� �Ǵ�
		if (currentIndex.first - 1 >= 0 && visit[currentIndex.first - 1][currentIndex.second] == 0)				//��
		{
			visit[currentIndex.first - 1][currentIndex.second] = visit[currentIndex.first][currentIndex.second] + 1;		//�湮�ߴ��� ǥ�ÿ� �Բ� �Ÿ� ���� - ���� ��忡 + 1 �ϸ� ���� �������� �Ÿ��� �ȴ�.
			bfsQueue.push({ currentIndex.first - 1 ,currentIndex.second });		//�湮�� ��� ť�� ����
		}
		if (currentIndex.first + 1 < row && visit[currentIndex.first + 1][currentIndex.second] == 0)	//��
		{
			visit[currentIndex.first + 1][currentIndex.second] = visit[currentIndex.first][currentIndex.second] + 1;
			bfsQueue.push({ currentIndex.first + 1 ,currentIndex.second });
		}
		if (currentIndex.second - 1 >= 0 && visit[currentIndex.first][currentIndex.second - 1] == 0)		//��
		{
			visit[currentIndex.first][currentIndex.second - 1] = visit[currentIndex.first][currentIndex.second] + 1;		
			bfsQueue.push({ currentIndex.first ,currentIndex.second - 1 });
		}
		if (currentIndex.second + 1 < column && visit[currentIndex.first][currentIndex.second + 1] == 0)		//��
		{
			visit[currentIndex.first][currentIndex.second + 1] = visit[currentIndex.first][currentIndex.second] + 1;		
			bfsQueue.push({ currentIndex.first ,currentIndex.second + 1 });
		}



	}

	// ������ ����� �� ��ȯ
	return visit[currentIndex.first][currentIndex.second];


}

int main()
{
	
	int row, column;

	cin >> row;
	cin >> column;
	vector<vector<int>> maze;
	cin.ignore();
	// ������ ���� �Ҵ�
	maze.resize(row);
	for (int i = 0; i < row; ++i)
	{	
		maze[i].resize(column);
		string s;
		getline(cin, s);		//�̷� ���� �ޱ�
		for (int j = 0; j < column; ++j)
		{
			maze[i][j] = s[j] - '0'; // char�� int�� ��ȯ
		}
	}

	int result = bfs(maze, row, column);
	cout << result;


	return 0;
}