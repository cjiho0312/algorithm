#include <iostream>
using namespace std;

int main()
{
#pragma region 거품 정렬
	// 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘입니다.

	int array[] = { 8, 9, 1, 5, 7, 6, 3, 10 };

	int size = sizeof(array) / sizeof(*array);
	int count = size;

	while (count > 1)
	{
		for (int i = 0; i < count - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}

		--count;
	}

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

#pragma endregion


	return 0;
}