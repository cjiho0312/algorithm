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

		cout << start << " ";

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
#pragma region ���� �켱 Ž�� (Depth First Search)
	// root ��忡������ ���� �б�� �Ѿ�� ����
	// �ش� �б⸦ �Ϻ��ϰ� Ž���ϴ� ����Դϴ�.

	// ���� �켱 Ž���� ������ Ȱ���մϴ�.

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

	graph.search(1);

#pragma endregion


	return 0;
}