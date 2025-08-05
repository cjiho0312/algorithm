#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#pragma region 선택 정렬
	// 주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서
	// 결과를 교체하는 방식으로 정렬하는 알고리즘입니다.

	int arr[] = { 4, 6, 8, 3, 1, 1, 9, 7, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size - 1; i++)
	{
		int min = arr[i];
		int minIndex;

		for (int j = 0 + i; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minIndex = j;
			}
		}

		if (min != arr[i])
		{
			swap(arr[i], arr[minIndex]);

			// int temp = min;
			// arr[minIndex] = arr[i];
			// arr[i] = temp;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}


#pragma endregion

	return 0;
}