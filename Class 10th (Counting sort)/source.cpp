#include <iostream>

using namespace std;

int main()
{
#pragma region 계수정렬
	// 데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개 있는지
	// 개수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	int list[] = { 1,3,2,2,4,5,1,2 };
	int size = sizeof(list) / sizeof(list[0]);
	int maxSize = 5;

	int* arr = new int[maxSize];

	for (int i = 0; i < maxSize; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= maxSize; j++)
		{
			if (list[i] == j + 1)
			{
				arr[j]++;
				break;
			}
		}
	}

	int index = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			list[index] = i + 1;
			cout << list[index] << " ";
			index++;
		}
	}

#pragma endregion


	return 0;
}