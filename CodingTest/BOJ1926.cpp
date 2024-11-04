#include "bits/stdc++.h"

// ���� 2178�� �׸� ����
using namespace std;

// i j ���� Ž�� ����
int bfs(vector<vector<int>>& visit,int i, int j, int row, int column)
{
	queue<pair<int, int>> bfsQueue;
	bfsQueue.push({ i,j });
	visit[i][j] = 0;	//�湮�� ���� 0���� �ٲ�
	pair<int, int> currentIndex;

	int size = 0;	//�׸��� ����
	while (!bfsQueue.empty())
	{
		currentIndex =  bfsQueue.front();
		bfsQueue.pop(); //���� �� ����
		++size; //���� ���� �� ���� �׸�ũ�� ����
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
	int paintCnt = 0; //�׸��� ����
	int maxSize = 0;  //�׸��� �ִ�ũ��
	int tempSize = 0; //�׸��� ũ�⸦ �޾� �� �ӽ� ����
	vector<vector<int>> visit = paint;

	for (int j = 0; j < column; ++j)
	{
		for (int i = 0; i < row; ++i)
		{
			if (visit[i][j] == 1) //�׸��� �����̸� bfsŽ��
			{
				tempSize = bfs(visit, i, j, row, column);
				if (maxSize < tempSize)
					maxSize = tempSize;

				++paintCnt; //Ž���� ���� �Ǹ� �׸��� �ϳ� �ִٴ� ��
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
	// ������ ���� �Ҵ�
	paint.resize(row);
	for (int i = 0; i < row; ++i)
	{
		paint[i].resize(column);
		for (int j = 0; j < column; ++j)
		{
			cin >> paint[i][j]; //�̷� ��ĭ��ĭ�� ���� �ޱ�
		}
	}

	pair<int, int> result = solution(paint, row, column);

	cout << result.first << "\n" << result.second;

	return 0;
}