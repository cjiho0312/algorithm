#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Maze
{
private:
	int N, M;

	bool iFoundIt = false;

public:
	Maze()
	{
		N = 0;
		M = 0;
	}

	void makeMaze()
	{
		cin >> N >> M;

		if (N <= 0 || M <= 0)
		{
			cout << "Error : Too small number" << endl;
			return;
		}

		int** map = new int* [N];
		bool** visited = new bool* [N];

		for (int i = 0; i < N; i++) // 동적 2차원 배열 생성
		{
			map[i] = new int[M];
			visited[i] = new bool[M];
		}

		for (int i = 0; i < M; i++) // 맵 생성
		{
			string num;

			cin >> num;

			if (num.size() < N || num.size() > N)
			{
				cout << "Error : Wrong size" << endl;
				return;
			}
			for (int j = 0; j < N; j++)
			{
				if (num[j] == '0' || num[j] == '1')
				{
					map[i][j] = num[j] - 48;
				}
				else
				{
					cout << "Error : Please insert only 1 or 0" << endl;

					return;
				}
			}
		}

		for (int i = 0; i < N; i++) // 방문 배열 초기화
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
				{
					visited[i][j] = 1; // 벽은 이미 방문 했다고 침
				}
				else
				{
					visited[i][j] = 0; // 길은 false로 처리
				}
			}
		}

		findRoad(map, visited, N, M, 0, 0);

		if (iFoundIt == false)
		{
			cout << "No" << endl;
		}

		for (int i = 0; i < M; i++)
		{
			delete[] map[i];
			delete[] visited[i];
		}

		delete[] map;
		delete[] visited;
	}

	void findRoad(int** map, bool** visited, int N, int M, int x, int y)
	{
		if (iFoundIt == true)
		{
			return;
		}

		if (x >= N || y >= M || x < 0 || y < 0 || visited[x][y] == true)
		{
			return;
		}

		else if (x == N - 1 && y == M - 1)
		{
			cout << "YES" << endl;
			iFoundIt = true;
			return;
		}

		visited[x][y] = true;

		findRoad(map, visited, N, M, x + 1, y);
		findRoad(map, visited, N, M, x - 1, y);
		findRoad(map, visited, N, M, x, y + 1);
		findRoad(map, visited, N, M, x, y - 1);
	}
};

int main()
{
	Maze maze;
	maze.makeMaze();

	return 0;
}