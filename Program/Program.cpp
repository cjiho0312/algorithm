#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 8

class Kruckal
{
private:

	int cost = 0;
	int parent[SIZE];

	class Edge
	{
	private:
		int x, y, w;

	public:
		Edge(int vertexX, int vertexY, int weight)
		{
			this->x = vertexX;
			this->y = vertexY;
			this->w = weight;
		}

		const int& X() { return x; }
		const int& Y() { return y; }
		const int& W() { return w; }

		const bool & operator <(const Edge&other)
		{
			return this->w < other.w;
		}
	};
	
	vector<Edge> nodelist;

public:

	void insert(int vertexX, int vertexY, int weight)
	{
		Edge edge(vertexX, vertexY, weight);

		nodelist.push_back(edge);
	}

	void calculate()
	{
		sort(nodelist.begin(), nodelist.end());
	}

	int find(int x)
	{
		if (x == parent[x])
		{
			return x;
		}
		else
		{
			return parent[x] = find(parent[x]);
		}
	}

	void Union(int x, int y)
	{
		int a = find(x);
		int b = find(y);

		if (a == b) return;

		if (a < b)
		{
			parent[y] = a;
		}
		else
		{
			parent[x] = b;
		}
	}

	bool same(int x, int y)
	{
		return find(x) == find(y);
	}

	void runKruckal()
	{
		for (int i = 0; i < SIZE; i++)
		{
			parent[i] = i;
		}

		for (int i = 0; i < nodelist.size(); i++)
		{
			if (!same(nodelist[i].X(), nodelist[i].Y()))
			{
				Union(nodelist[i].X(), nodelist[i].Y());

				cost += nodelist[i].W();
			}
		}

		cout << "min cost : " << cost << endl;
	}
};


int main()
{
#pragma region �ּ� ���� Ʈ��
	// �׷����� ��� ������ �����ϸ鼭 ����Ŭ�� �������� �ʴ�
	// �κ� �׷�����, �׷����� ��� ������ �ּ� ������� �����ϴ� Ʈ���Դϴ�.

	// �׷����� ������ ���� n���� ��, ������ ���� n-1�� �Դϴ�.

	Kruckal kruskal;

	kruskal.insert(1, 7, 12);
	kruskal.insert(4, 7, 13);
	kruskal.insert(4, 1, 30);
	kruskal.insert(5, 7, 79);
	kruskal.insert(4, 2, 23);
	kruskal.insert(1, 2, 71);
	kruskal.insert(2, 5, 65);
	kruskal.insert(1, 5, 15);
	kruskal.insert(6, 5, 44);
	kruskal.insert(3, 5, 18);
	kruskal.insert(3, 6, 36);

	kruskal.calculate();

	kruskal.runKruckal();




#pragma endregion



	return 0;
}