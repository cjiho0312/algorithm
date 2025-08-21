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

	const int& find() // �湮 üũ�� ��� ���� �ּҰ� ã��, �ε����� ��ȯ
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

	void update(int start) // ��� �� �� ���� ���� ��ΰ� ������ distance ����
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
#pragma region ���ͽ�Ʈ�� �˰���
	// ���������κ��� ��� �������� �ּ� �Ÿ��� �����ִ�
	// �˰����Դϴ�.

	// 1. �Ÿ� �迭���� weight[���� ���]�� ����� �ʱ�ȭ�մϴ�.

	// 2. �������� �湮 ó���մϴ�.

	// 3. �Ÿ� �迭���� �ּ� ��� ��带 ã�� �湮 ó���մϴ�.
	//    ��, �̹� �湮�� ���� �����մϴ�.

	// 4. �ּ� ��� ��带 ���İ� �� ����ؼ� �Ÿ� �迭�� �����մϴ�.
	//	  ��, �̹� �湮�� ���� �����մϴ�.

	// 5. ��� ��带 �湮�� ������ 3 ~ 4���� �ݺ��մϴ�.

	// �湮���� ���� ��� �߿��� ���� ���� �Ÿ��� ���� ��带
	// �湮�ϰ�, �� ���� ����� �ٸ� �������� �Ÿ��� ����մϴ�.

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