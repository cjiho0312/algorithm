#include <iostream>
#include <vector>

#define SIZE 8

using namespace std;

class Graph
{
private:
	bool visited[SIZE];
	vector<int> list[SIZE];

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	void insert(int i, int j)
	{
		list[i].push_back(j);
		list[j].push_back(i);
	}

	void search(int start)
	{
		visited[start] = true;

		 for (int i = 0; i < list[start].size(); i++)
    {
        int next = list[start][i];
        if (!visited[next])
        {
            search(next);
        }
    }
	}
};


int main()
{
#pragma region 깊이 우선 탐색 (Depth First Search)
	// root 노드에서부터 다음 분기로 넘어가기 전에
	// 해당 분기를 완벽하게 탐색하는 방법입니다.

	// 깊이 우선 탐색은 스택을 활용합니다.

	Graph graph;

	graph.insert(1, 2);
	graph.insert(1, 3);

	graph.insert(2, 3);
	graph.insert(2, 4);
	graph.insert(2, 5);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.insert(4, 5);
	graph.insert(6, 7);



#pragma endregion


	return 0;
}