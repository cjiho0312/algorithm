#include <iostream>

using namespace std;

void find(int list[], int size, int findKey) // 반복문 활용
{
	int firstIndex = 0;
	int endIndex = size - 1;
	int pivotIndex = (firstIndex + endIndex) / 2;

	while (list[firstIndex] <= list[endIndex])
	{
		if (findKey == list[pivotIndex])
		{
			cout << "찾았습니다! " << findKey << "은(는) list[" << pivotIndex << "]에 있습니다." << endl;
			return;
		}
		else if (findKey < list[pivotIndex])
		{
			endIndex = pivotIndex - 1;
			pivotIndex = endIndex;
		}
		else if (findKey > list[pivotIndex])
		{
			firstIndex = pivotIndex + 1;
			pivotIndex = firstIndex;
		}
	}

	cout << "list에서 " << findKey << "을(를) 찾을 수 없습니다." << endl;

}

void find_(int list[], int findKey, int firstIndex, int endIndex) // 재귀함수 활용
{
	if (list[firstIndex] > list[endIndex] || findKey > list[endIndex] || findKey < list[firstIndex])
	{
		cout << "list에서 " << findKey << "을(를) 찾을 수 없습니다." << endl;
		return;
	}
	else
	{
		int pivotIndex = (firstIndex + endIndex) / 2;

		if (findKey == list[pivotIndex])
		{
			cout << "찾았습니다! " << findKey << "은(는) list[" << pivotIndex << "]에 있습니다." << endl;
			return;
		}
		else if (findKey < list[pivotIndex])
		{
			find_(list, findKey, firstIndex, pivotIndex - 1);
		}
		else if (findKey > list[pivotIndex])
		{
			find_(list, findKey, pivotIndex + 1, endIndex);
		}
	}
}

int main()
{
#pragma region 이분 탐색
	// 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
	// 좁혀 나가는 방식으로 작동하는 알고리즘입니다.

	int list[] = { 6, 10, 13, 22, 57 };
	int size = sizeof(list) / sizeof(list[0]);

	// find(list, size, 58);
	find_(list, 58, 0, size - 1);

#pragma endregion


	return 0;
}