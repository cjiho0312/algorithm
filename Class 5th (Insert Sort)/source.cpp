#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#pragma region 삽입 정렬
	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘입니다.

	int list[] = { 8, 2, 4, 1, 10, 7, 3, 9, 5, 6 };
	int size = sizeof(list) / sizeof(list[0]);


	for (int i = 1; i < size; i++)
	{
		int key = list[i];

		for (int j = i - 1; j >= 0; j--)
		{
			if (key < list[j])
			{
				list[j + 1] = list[j];
				list[j] = key;
			}
		}
	}

	for (const auto& element : list)
	{
		cout << element << " ";
	}


#pragma endregion



	return 0;
}