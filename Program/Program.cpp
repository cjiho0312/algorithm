#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INFINITY 10000000
#define SIZE 6

class Dijkstra
{
private:
	int graph[SIZE][SIZE] { 0 };

	int distance[SIZE];
	bool visited[SIZE];

public:
	Dijkstra()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			distance[i] = 0;
		}
	}

	void insert(int x, int y, int w)
	{
		graph[x - 1][y - 1] = w;
		graph[y - 1][x - 1] = w;
	}

	const int& find() // 방문 체크한 요소 제외 최소값 찾고, 인덱스값 반환
	{
		int min = INFINITY;
		int index;

		for (int i = 0; i < SIZE; i++)
		{
			if (visited[i]==false && distance[i] != 0 && min > distance[i])
			{
				min = distance[i];
				index = i;
			}
		}

		return index;
	}

	void update(int start) // 경로 중 더 작은 값의 경로가 나오면 distance 갱신
	{
		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = graph[start][i];
		}

		visited[start] = true;

		for (int i = 0; i < SIZE - 1; i++)
		{
			int minNode = find();

			visited[minNode] = true;

			for (int j = 0; j < SIZE; j++)
			{
				if (visited[j] == false)
				{
					if (distance[minNode] + graph[minNode][j] < distance[j])
					{
						distance[j] = distance[minNode] + graph[minNode][j];
					}
				}
			}
		}

		for (const auto& element : distance)
		{
			cout << element << " ";
		}

	}

	void print()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "[" << i << "] ";

			for (int j = 0; j < SIZE; j++)
			{
				cout << graph[i][j] << " ";
			}
			
			cout << endl;
		}
	}
};

int main()
{
#pragma region 다익스트라 알고리즘
	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는
	// 알고리즘입니다.

	// 1. 거리 배열에서 weight[시작 노드]의 값들로 초기화합니다.

	// 2. 시작점을 방문 처리합니다.

	// 3. 거리 배열에서 최소 비용 노드를 찾고 방문 처리합니다.
	//    단, 이미 방문한 노드는 제외합니다.

	// 4. 최소 비용 노드를 거쳐갈 지 고민해서 거리 배열을 갱신합니다.
	//	  단, 이미 방문한 노드는 제외합니다.

	// 5. 모든 노드를 방문할 때까지 3 ~ 4번을 반복합니다.

	// 방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를
	// 방문하고, 그 노드롸 연결된 다른 노드까지의 거리를 계산합니다.

	Dijkstra dijkstra;

	dijkstra.insert(1, 2, 2);
	dijkstra.insert(1, 3, 5);
	dijkstra.insert(1, 4, 1);
	dijkstra.insert(1, 5, INFINITY);
	dijkstra.insert(1, 6, INFINITY);

	dijkstra.insert(2, 3, 3);
	dijkstra.insert(2, 4, 2);
	dijkstra.insert(2, 5, INFINITY);
	dijkstra.insert(2, 6, INFINITY);

	dijkstra.insert(3, 4, 3);
	dijkstra.insert(3, 5, 1);
	dijkstra.insert(3, 6, 5);

	dijkstra.insert(4, 5, 1);
	dijkstra.insert(4, 6, INFINITY);

	dijkstra.insert(5, 6, 2);

	// dijkstra.print();

	dijkstra.update(0);



#pragma endregion

	return 0;
}