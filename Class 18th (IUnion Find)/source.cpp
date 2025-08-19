#include <iostream>

using namespace std;

#define SIZE 7
int parent[SIZE];

int find(int x)
{
	// 배열의 인덱스와 값이 같다면 root node를 발견

	// 부모 노드의 번호를 전달하면서, root Node를 찾을 때까지
	// 재귀 함수를 호출하여 반복합니다.

	if (x == parent[x])
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]); // 경로 압축
	}

	// 최종 부모를 찾는 과정에서 그 경로상의 모든 노드들이
	// 최종 부모를 직접 가리키도록 업데이트 해주는 최적화 기법입니다.
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

int main()
{
#pragma region 서로소 집합
	// 서로 공통된 원소를 가지고 있지 않은 두 개 이상의
	// 집합을 의미합니다.

	// union (합집합) : 두 집합을 하나로 합치는 연산입니다.

	// find (찾기) : 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산입니다.

	// 1. 합집합 연산을 확인하여, 서로 연결된 두 노드를 확인합니다.
	//	 1) A와 B의 루트 노드로 A'와 B'를 각각 찾는다.
	//   2) A'와 B'의 부모 노드를 설정합니다.

	// 2. 모든 합집합 연산을 처리할 때까지 1번 과정을 반복합니다.

	for (int i = 0; i < SIZE; i++) // 부모 초기화
	{
		parent[i] = i;
	}

	Union(1, 0);
	Union(0, 2);
	Union(3, 0);
	Union(4, 5);
	Union(6, 5);

	for (int i = 0; i < SIZE; i++) // 출력
	{
		cout << "[" << i << "] : " << parent[i] << endl;
	}

	cout << "same (1, 5) : " << same(1, 5) << endl;
	cout << "same (2, 3) : " << same(2, 3) << endl;


#pragma endregion


	return 0;
}