#include <iostream>
#include <vector>
#include <queue>

#define SIZE 8
using namespace std;

class Graph
{
private:
	bool visited[SIZE];
	vector <int> list[SIZE];
	queue <int> queue;

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = 0;
		}
	}

	void insert(int i, int j)
	{
		list[i].push_back(j);
		list[j].push_back(i);
	}

	void search(int start)
	{
		queue.push(start);

		while (!queue.empty())
		{
			int temp = queue.front();

			visited[temp] = true;

			for (int i = 0; i < list[temp].size(); i++)
			{
				if (list[temp][i] != NULL && visited[list[temp][i]] == false)
				{
					queue.push(list[temp][i]);
				}
			}

			cout << temp << " "; // 출력

			queue.pop();
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색 (Breadth First Search)

	// 시작 정점을 방문한 후 시작 정점에 인접한
	// 모든 정점들을 우선적으로 방문하는 탐색 알고리즘입니다.

	Graph graph;

	graph.insert(1, 2);
	graph.insert(1, 3);

	graph.insert(2, 4);
	graph.insert(2, 5);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.search(1);

	// 더 이상 방문하지 않은 정점이 없을 때까지 방문하지 않은
	// 모든 정점들에 대해서 너비 우선 탐색을 적용합니다.

#pragma endregion


	return 0;
}